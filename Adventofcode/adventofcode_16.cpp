#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vull vector<unsigned long long>
#define vs vector<string>
#define vll vector<long long>
#define mci map<char, int>
#define si set<int>
#define sc set<char>
#define ull unsigned long long

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)

#define pb push_back
#define eb emplace_back

template <class T>
void print_v(vector<T> &v) { cout << '{'; for (auto x : v) cout << x << ','; cout << '}'; cout << endl; }

template <class TP>
void print_v_p(vector<TP> &v) { cout << '{'; for (auto x : v) cout << x.second << ','; cout << '}'; cout << endl; }

/* Utility */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }

map<string, int> tiles;
set<string> tiles_set;

void energize(vs grid, int i, int j, char dir) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].length()) {
    return;
  }
  if (tiles.find(to_string(i) + "," + to_string(j) + "," + dir) != tiles.end()) return;
  tiles[to_string(i) + "," + to_string(j) + "," + dir]++;
  tiles_set.insert(to_string(i) + "," + to_string(j));

  if (grid[i][j] == '|') {
    if (dir == 'r' || dir == 'l') {
      energize(grid, i-1, j, 'u');
      energize(grid, i+1, j, 'd');
    }
    else if (dir == 'u') {
      energize(grid, i-1, j, dir);
    }
    else if (dir == 'd') {
      energize(grid, i+1, j, dir);
    }
  }

  if (grid[i][j] == '/') {
    if (dir == 'u') {
      energize(grid, i, j+1, 'r');
    }
    else if (dir == 'd') {
      energize(grid, i, j-1, 'l');
    }
    else if (dir == 'r') {
      energize(grid, i-1, j, 'u');
    }
    else if (dir == 'l') {
      energize(grid, i+1, j, 'd');
    }
  }

  if (grid[i][j] == '\\') {
    if (dir == 'u') {
      energize(grid, i, j-1, 'l');
    }
    else if (dir == 'd') {
      energize(grid, i, j+1, 'r');
    }
    else if (dir == 'l') {
      energize(grid, i-1, j, 'u');
    }
    else if (dir == 'r') {
      energize(grid, i+1, j, 'd');
    }
  }

  if (grid[i][j] == '-') {
    if (dir == 'u' || dir == 'd') {
      energize(grid, i, j+1, 'r');
      energize(grid, i, j-1, 'l');
    }
    else if (dir == 'r') {
      energize(grid, i, j+1, dir);
    }
    else if (dir == 'l') {
      energize(grid, i, j-1, dir);
    }
  }

  if (grid[i][j] == '.') {
    if (dir == 'u') {
      energize(grid, i-1, j, dir);
    }
    else if (dir == 'd') {
      energize(grid, i+1, j, dir);
    }
    else if (dir == 'l') {
      energize(grid, i, j-1, dir);
    }
    else if (dir == 'r') {
      energize(grid, i, j+1, dir);
    }
  }
}

int main() {
    string s;
    int ans = 0;
    vs grid;

    while(getline(cin, s)) {     
      grid.pb(s);
    }

    /* --- Part one --- */
    // energize(grid, 0, 0, 'r'); 
    // cout << tiles_set.size() << endl;

    /* --- Part two --- */
    for (int j = 0 ; j < grid[0].size(); j++) {
      energize(grid, 0, j, 'd'); 
      ans = max(ans, int(tiles_set.size()));
      tiles.clear();
      tiles_set.clear();
    }

    for (int j = 0 ; j < grid[0].size(); j++) {
      energize(grid, grid.size() - 1, j, 'u'); 
      ans = max(ans, int(tiles_set.size()));
      tiles.clear();
      tiles_set.clear();
    }

    for (int i = 0 ; i < grid.size(); i++) {
      energize(grid, i, 0, 'r'); 
      ans = max(ans, int(tiles_set.size()));
      tiles.clear();
      tiles_set.clear();
    }

    for (int i = 0 ; i < grid.size(); i++) {
      energize(grid, i, grid[0].size() - 1, 'l'); 
      ans = max(ans, int(tiles_set.size()));
      tiles.clear();
      tiles_set.clear();
    }

    cout << ans << endl;

    return 0;
}