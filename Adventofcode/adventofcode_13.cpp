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

bool isPowerOfTwo(int n){
    return n != 0 && ((n & (n-1)) == 0);
}

bool oneBitPosDiffer(int x, int y){
    return isPowerOfTwo(x ^ y);
}

int stringToBinary(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') s[i] = '0';
    if (s[i] == '#') s[i] = '1';
  }
  return stoi(s, 0, 2);
}

int getMirrorIndex(vi vec) {
  for (int i = 0; i < vec.size() - 1; i++) {
    int start = i;
    int end = i+1;
    int count = 0;
    bool mirror = true;

    while (start >= 0 && end < vec.size()) {
      if (vec[start] != vec[end]) {
        // --- Part two ---
        if (count < 1 && oneBitPosDiffer(vec[start], vec[end])) {
          count++;
        }
        else {
          mirror = false;
          break;
        } 
      }
      start--;
      end++;
    }

    // Count condition added for Part two.
    if (mirror && (count == 1)) return i;
  }

  return -1;
}

ll getMirrors(vs vec) {
    vi rows, columns;
    int n = vec.size();
    int m = vec[0].length();

    // Build rows
    for (int i = 0; i < n; i++) {
      rows.pb(stringToBinary(vec[i]));
    }

    // Build columns
    for (int j = 0; j < m; j++) {
      string temp;
      for (int i = 0; i < n; i++) {
        temp += vec[i][j];
      }
      columns.pb(stringToBinary(temp));
    }

    ll ans = 0, k;
    if ((k = getMirrorIndex(rows)) != -1) ans += (100*(k+1));
    if ((k = getMirrorIndex(columns)) != -1) ans += (k+1);

    return ans;
}

int main() {
    string s;
    vs vec;
    ll ans = 0;

    while(getline(cin, s)) {      
      if (empty(s)) {
        ans += getMirrors(vec);
        // Clear values for next pattern.
        vec.clear();
      }
      else {
        vec.pb(s);
      }
    }
    ans += getMirrors(vec);

    cout << ans << endl;

    return 0;
}
