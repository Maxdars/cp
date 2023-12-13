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

vs splitString(string delimiter, string s) {
  vs result;
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
      token = s.substr(0, pos);
      if (!token.empty()) result.pb(token);
      s.erase(0, pos + delimiter.length());
  }
  result.pb(s);
  return result;
}

vector<int> splitNumbers(string delimiter, string s) {
  vector<int> result;
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
      token = s.substr(0, pos);
      if (!token.empty()) result.pb(stoi(token));
      s.erase(0, pos + delimiter.length());
  }
  result.pb(stoi(s));
  return result;
}

bool validate(vi vec, string s) {
  int i = 0, count = 0;
  vi check;

  for (int j = 0; j < s.length();) {
    if (s[j] == '#') {
      while (s[j] == '#') {
        j++;
        count++;
      }
      check.pb(count);
      count = 0;
    }
    else {
      j++;
    }
  }

  if (count > 0) {
    check.pb(count);
  }

  return vec == check;
}

int arrange(vector<int> vec, string s, int i) {
  int ans = 0;
  if (i == s.size()) {
    return validate(vec, s) ? 1 : 0;
  }

  if (s[i] == '?') {
    s[i] = '#';
    ans += arrange(vec, s, i+1);
    s[i] = '.';
    ans += arrange(vec, s, i+1);
  }
  else {
    ans += arrange(vec, s, i+1);
  }

  return ans;
}

int main() {
    string s;
    ll ans = 0;

    while(getline(cin, s)) {
      vs elements = splitString(" ", s);
      string line = elements[0];
      vi arrangements = splitNumbers(",", elements[1]);
      ans += arrange(arrangements, line, 0);
    }

    cout << ans << endl;

    return 0;
}
