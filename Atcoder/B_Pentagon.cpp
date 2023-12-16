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
void print_v(vector<T> &v) { cout << '{'; for (auto x : v) cout << x << ','; cout << '}'; cout << endl; }

/* Utility */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
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

int main()
{

    string s1, s2;

    map<string, string> eq;

    eq["AB"] = 1;
    eq["BA"] = 1;
    eq["AC"] = 2;
    eq["CA"] = 2;
    eq["AE"] = 1;
    eq["EA"] = 1;
    eq["AD"] = 2;
    eq["DA"] = 2;
    eq["ED"] = 1;
    eq["DE"] = 1;
    eq["DC"] = 1;
    eq["CD"] = 1;
    eq["EC"] = 2;
    eq["CE"] = 2;
    eq["BD"] = 2;
    eq["DB"] = 2;
    eq["BC"] = 1;
    eq["CB"] = 1;
    eq["BE"] = 2;
    eq["EB"] = 2;

    cin >> s1;
    cin >> s2;

    cout << (eq[s1] == eq[s2] ? "Yes" : "No") << endl;

     return 0;

}