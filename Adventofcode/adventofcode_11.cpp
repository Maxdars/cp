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

bool emptyRow(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '.') {
      return false;
    }
  }
  return true;
}

bool emptyColumn(vs s, int j) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i][j] != '.') {
      return false;
    }
  }
  return true;
}

int main() {
    string s;
    vs space;
    ll ans = 0, i = 0;

    vi empty_rows;
    vi empty_columns;

    while(getline(cin, s)) {
      if (emptyRow(s)) {
        empty_rows.pb(i);
        // part one
        // space.pb(s);
      }
      i++;
      space.pb(s);
    }

    // Part one
    // int length = s.length();
    // for (int j = 0; j < length; j++) {
    //   if (emptyColumn(space, j)) {
    //     for (int i = 0; i < space.size(); i++) {
    //       space[i] = space[i].insert(j+1, ".");
    //     }
    //     length++;
    //     j++;
    //   }
    // }

    // Part two
    int length = s.length();
    for (int j = 0; j < length; j++) {
      if (emptyColumn(space, j)) {
        empty_columns.pb(j);
      }
    }

    vector<pair<ll,ll>> nodes;
    for (int i = 0; i < space.size(); i++) {
      for (int j = 0; j < space[0].length(); j++) {
        if (space[i][j] == '#') {
          int count_i = 0;
          int count_j = 0;
          for(auto xi: empty_rows) {
            if (i > xi) count_i++;
          }
          for(auto xj: empty_columns) {
            if (j > xj) count_j++;
          }

          pair<ll,ll> node = make_pair((1000000 - 1)*count_i + i , (1000000 - 1)*count_j + j);
          nodes.pb(node);
        }
      }
    }

    // Part one + two
    for (int i = 0; i < nodes.size() - 1; i++) {
      for (int j = i+1; j < nodes.size(); j++) {
        ll _min = min(abs(nodes[j].first - nodes[i].first), abs(nodes[j].second - nodes[i].second));
        ll _max = max(abs(nodes[j].first - nodes[i].first), abs(nodes[j].second - nodes[i].second));
        ans += ((_min*2) + _max - _min);
      }
    }

    cout << ans << endl;

    // cout << ans << endl;

    return 0;
}
