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


bool isEqual(vector<vll> a, vector<vll> b) {
    for (int i = 0; i < a.size(); i++) {
       for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }

        }
    }
    return true;
}

ll rotate(vector<vll> a, vector<vll> b, int i, int j) {

    if (i+1 >= a.size() && j+1 >= a[0].size()) {
        return isEqual(a, b) ? 0 : -1;
    }

    if (a[i][j] == b[i][j]) {
        return min(rotate(a, b, i+1, j), rotate(a, b, i, j+1));
    }
    
    

}

int main()
{

    int n, m, k;
    cin >> n >> m;

    // input
    map<ll, ll> occ_a, occ_b;
    vector<vll> a(n, vector<ll>(m)), b(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            occ_a[a[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            occ_b[b[i][j]]++;

        }
    }

    //
    // int ans = 0;
    // for (auto occ: occ_a) {
        
    // }

    cout << rotate(a, b, 0, 0) << endl;

    return 0;

}