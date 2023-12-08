#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define mci map<char, int>
#define si set<int>
#define sc set<char>

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

set<string> isSafe(const vector<string>& grid, int x, int y) {
    int rows = grid.size();
    int cols = grid[0].length();
    
    set<string> njmat;

    if (x+1 >= 0 && x+1 < rows && y >= 0 && y < cols && grid[x+1][y] == '*') njmat.insert(to_string(x+1) + "," + to_string(y));
    if (x >= 0 && x < rows && y+1 >= 0 && y+1 < cols && grid[x][y+1] == '*') njmat.insert(to_string(x) + "," + to_string(y+1));
    if (x-1 >= 0 && x-1 < rows && y >= 0 && y < cols && grid[x-1][y] == '*') njmat.insert(to_string(x-1) + "," + to_string(y));
    if (x >= 0 && x < rows && y-1 >= 0 && y-1 < cols && grid[x][y-1] == '*') njmat.insert(to_string(x) + "," + to_string(y-1));
    if (x+1 >= 0 && x+1 < rows && y+1 >= 0 && y+1 < cols && grid[x+1][y+1] == '*') njmat.insert(to_string(x+1) + "," + to_string(y+1));
    if (x-1 >= 0 && x-1 < rows && y-1 >= 0 && y-1 < cols && grid[x-1][y-1] == '*') njmat.insert(to_string(x-1) + "," + to_string(y-1));
    if (x+1 >= 0 && x+1 < rows && y-1 >= 0 && y-1 < cols && grid[x+1][y-1] == '*') njmat.insert(to_string(x+1) + "," + to_string(y-1));
    if (x-1 >= 0 && x-1 < rows && y+1 >= 0 && y+1 < cols && grid[x-1][y+1] == '*') njmat.insert(to_string(x-1) + "," + to_string(y+1));

    return njmat;
}

map<string, vector<int> > findValidDigits(const vector<string>& grid) {
    map<string, vector<int> > occ;
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].length();) {
            if (isdigit(grid[i][j])) {
                string tempNum = "";
                set<string> validDigits;

                while (j < grid[i].size() && isdigit(grid[i][j])) {
                    tempNum += grid[i][j];
                    set<string> njmat = isSafe(grid, i, j);
                    for (auto n: njmat) {
                      validDigits.insert(n);
                    }
                    j++;
                }

                for (auto n: validDigits) {
                  if (occ.find(n) == occ.end()) {
                    vi current;
                    current.pb(stoi(tempNum));
                    occ[n] = current;
                  }
                  else {
                    occ[n].pb(stoi(tempNum));
                  }
                }

            } else {
                j++;
            }
        }
    }

    return occ;
}

int main() {
    string s;
    vs grid;
    int ans = 0;

    while(getline(cin, s)) {
      grid.pb(s);
    }

    map<string, vector<int> > result = findValidDigits(grid);

    for (auto n :result) {
      if (n.second.size() == 2) {
        ans += (n.second[0] * n.second[1]);
      }
    }

    cout << ans << endl;

    return 0;
}
