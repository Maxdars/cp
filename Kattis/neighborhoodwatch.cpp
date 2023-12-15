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
    ll n, k, last_h, a, ans = 0;
    cin >> n >> k;

    ans = (n*(n-1)/2) + k;

    last_h = 1;
    while (k--) {
        cin >> a;
        ans -= ((a - last_h) * (a - last_h - 1) / 2);
        last_h = a + 1;
    }

    if ((n + 1 - last_h) > 1) {
        ans -= ((n + 1 - last_h)*(n - last_h)/2);
    }

    cout << ans << endl;

    return 0;
}
