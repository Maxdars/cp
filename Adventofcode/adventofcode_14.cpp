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


int main() {
    string s;
    vs grid;
    int current_i, ans = 0;

    while(getline(cin, s)) {      
      grid.pb(s);
    }

    for (int j = 0; j < grid[0].length(); j++) {
      current_i = 0;
      for (int i = 0; i < grid.size(); i++) {
        int count_0 = 0;
        while(i < grid.size() && grid[i][j] != '#') {
          if (grid[i][j] == 'O') {
            count_0++;
          }
          i += 1;
        }

        // When blocked
        ans += (count_0*(grid.size() - current_i) - (count_0*(count_0-1)/2));
        current_i = i + 1;
      }
    }

    cout << ans << endl;

    return 0;
}
