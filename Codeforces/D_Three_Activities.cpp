#include <bits/stdc++.h>
#include <map>
#include <iostream>

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

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.second > b.second;
}

int main()
{

    ll t, n, k, start, end, ai, bi, ci;
    string s;
    
    cin >> t;

    while(t--) {
        vector<pair<ll,ll> > a, b, c;
        pair<ll,ll> p;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ai;
            p = make_pair(i, ai);
            a.pb(p);
        }
        for (int i = 0; i < n; i++) {
            cin >> bi;
            p = make_pair(i, bi);
            b.pb(p);
        }
        for (int i = 0; i < n; i++) {
            cin >> ci;
            p = make_pair(i, ci);
            c.pb(p);
        }
        
        sort(a.begin(), a.end(), comp);
        sort(b.begin(), b.end(), comp);
        sort(c.begin(), c.end(), comp);

        vll ans;

        int kk = 3;
        
        // Fix a and start with b
        for (ll i = 0; i < b.size(); i++) {
            if (b[i].first != a[0].first) {
                for (ll j = 0; j < c.size(); j++) {
                    if (c[j].first != b[i].first && c[j].first != a[0].first) {
                        ans.pb(c[j].second + b[i].second + a[0].second);
                        break;
                    }
                }
                break;
            }
        }
        // Fix a and start with c
        for (ll i = 0; i < c.size(); i++) {
            if (c[i].first != a[0].first) {
                for (ll j = 0; j < b.size(); j++) {
                    if (b[j].first != c[i].first && b[j].first != a[0].first) {
                        ans.pb(b[j].second + c[i].second + a[0].second);
                        break;
                    }
                }
                break;
            }
        }

        // Fix b and start with a
        for (ll i = 0; i < a.size(); i++) {
            if (a[i].first != b[0].first) {
                for (ll j = 0; j < c.size(); j++) {
                    if (c[j].first != a[i].first && c[j].first != b[0].first) {
                        ans.pb(c[j].second + a[i].second + b[0].second);
                        break;
                    }
                }
                break;
            }
        }
        // Fix b and start with c
        for (ll i = 0; i < c.size(); i++) {
            if (c[i].first != b[0].first) {
                for (ll j = 0; j < a.size(); j++) {
                    if (a[j].first != c[i].first && a[j].first != b[0].first) {
                        ans.pb(a[j].second + c[i].second + b[0].second);
                        break;
                    }
                }
                break;
            }
        }

        // Fix c and start with a
        for (ll i = 0; i < a.size(); i++) {
            if (a[i].first != c[0].first) {
                for (ll j = 0; j < b.size(); j++) {
                    if (b[j].first != a[i].first && b[j].first != c[0].first) {
                        ans.pb(b[j].second + a[i].second + c[0].second);
                        break;
                    }
                }
                break;
            }
        }
        // Fix c and start with b
        for (ll i = 0; i < b.size(); i++) {
            if (b[i].first != c[0].first) {
                for (ll j = 0; j < a.size(); j++) {
                    if (a[j].first != b[i].first && a[j].first != c[0].first) {
                        ans.pb(a[j].second + b[i].second + c[0].second);
                        break;
                    }
                }
                break;
            }
        }

        cout << *max_element(ans.begin(), ans.end()) << endl;
    }

 return 0;

}