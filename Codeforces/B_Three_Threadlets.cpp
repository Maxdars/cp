#include <bits/stdc++.h>
#include <iostream>

using namespace std;


#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)

#define pb push_back
#define eb emplace_back

template <class T>
void print_v(vector<T> &v) { cout << '{'; for (auto x : v) cout << x << ','; cout << '}'; cout << endl; }

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }

int main()
{

    // https://codeforces.com/contest/1881/problem/B

    int t;
    cin >> t;

    while (t--) {
        ll a,b,c;
        cin >> a >> b >> c;
        int op = 3;

        ll sum = a + b + c;
        ll max_v = max(a, max(b,c));
        ll min_v = min(a, min(b,c));
        ll mid = sum - max_v - min_v;

        if (mid % min_v != 0 || max_v % min_v != 0 || (mid / min_v) + (max_v / min_v) - 2 > 3) {
            no();
        }
        else {
            yes();
        }

    }

    return 0;

}