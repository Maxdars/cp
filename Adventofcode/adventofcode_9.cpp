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

vector<ll> splitString(string delimiter, string s) {
  vector<ll> result;
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
      token = s.substr(0, pos);
      if (!token.empty()) result.pb(stoll(token));
      s.erase(0, pos + delimiter.length());
  }
  result.pb(stoll(s));
  return result;
}

int main() {
    vector<vll> numbers;
    string s;
    ll ans = 0;

    while(getline(cin, s)) {
      numbers.pb(splitString(" ", s));
    }

    for (auto row: numbers) {
      vector<vll> differences;
      vector<ll> diff;
      ll flag = true;

      for (ll i = 1; i < row.size(); i++) {
        diff.pb(row[i] - row[i-1]);
        if (row[i+1] - row[i] != 0) flag = false;
      }

      differences.pb(row);
      differences.pb(diff);

      while(!flag) {
        flag = true;;
        diff.clear();
        for (ll j = 1; j < differences.back().size(); j++) {
          diff.pb(differences.back()[j] - differences.back()[j-1]);
          if (differences.back()[j] - differences.back()[j-1] != 0) flag=false;
        }
        differences.pb(diff);
      }

      /* --- Part one --- */
      // ll count = 0;
      // for (ll i = differences.size() - 2; i >= 0 ; i--) {
      //   count += differences[i].back();
      // }
      // ans += count;


      /* --- Part two --- */
      ll count = 0;
      for (ll i = differences.size() - 2; i >= 0 ; i--) {
        count = differences[i].front() - count;
      }
      ans += count;

    }

    cout << ans << endl;

    return 0;
}

// https://adventofcode.com/2023/day/9
