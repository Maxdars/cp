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


bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first > b.first;
}

int main() {
    ll n, w, a, b, ans = 0, i = 0;
    vector<pair<ll, ll>> vec;
    cin >> n >> w;

    while (n--) {
        cin >> a >> b;
        pair<ll, ll> pizza = make_pair(a, b);
        vec.pb(pizza);
    }

    sort(vec.begin(), vec.end(), comp);

    while (w > 0 && i < vec.size()) {
        ll grams = vec[i].first * min(w, vec[i].second);
        ans += grams;
        w -= vec[i].second;
        i++;
    }

    cout << ans << endl;

    return 0;
}
