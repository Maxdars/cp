#include <bits/stdc++.h>

using namespace std;

/* Data Type  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* Functions */
  /* Loop */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)

#define pb push_back
#define eb emplace_back

/* Printing vector */
template <class T>
void print_v(vector<T> &v) { cout << '{'; for (auto x : v) cout << x << ','; cout << '}'; }

/* Utility */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;


int is_number(string s, int i) {
  if (s.substr(i, 3) == "one") return 1;
  if (s.substr(i, 3) == "two") return 2;
  if (s.substr(i, 3) == "six") return 6;
  if (s.substr(i, 4) == "four") return 4;
  if (s.substr(i, 4) == "five") return 5;
  if (s.substr(i, 4) == "nine") return 9;
  if (s.substr(i, 5) == "seven") return 7;
  if (s.substr(i, 5) == "eight") return 8;
  if (s.substr(i, 5) == "three") return 3;
  return 0;
}

int main()
{

  string s;
  ll ans = 0;
  while (getline(cin, s))
  {
      int first = 0, second = 0, k;
      for (int i = 0, j = s.length() - 1; i <= j;) {
        if (first != 0 && second != 0) break;
        if (isdigit(s[i])) {
          first = s[i] - '0';
        }
        else if((k = is_number(s, i)) != 0 ) {
          first = k;
        }
        else {
          i++;
        }
        if (isdigit(s[j])) {
          second = s[j] - '0';
        }
        else if((k = is_number(s, j)) != 0 ) {
          second = k;
        }
        else {
          j--;
        }
      }

      ans += first*10 + second;
  }

  cout << ans << endl;

  return 0;

}