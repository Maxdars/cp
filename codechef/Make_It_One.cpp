
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
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
void print_v(vector<T> &v) { for (auto x : v) cout << x << ' '; cout << endl; }

template <class TP>
void print_v_p(vector<TP> &v) { for (auto x : v) cout << x.second << ' '; cout << endl; }

/* Utility */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }

bool comparePairs(const std::pair<char, int>& a, const std::pair<char, int>& b) {
    return a.second > b.second;
}

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int main()
{

    int t, n, l, r;
    cin >> t;

    while(t--) {
        vi vec;
        cin >> l >> r;
        n = r - l + 1;

        if (l%2 == 0 && r%2 == 0) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (i%2 == 0 && l+i+1 <= r) vec.pb(l+i+1);
            else if (i%2 == 0 && l+i+1 > r) vec.pb(l+i);
            else vec.pb(l+i-1);
        }

        if (n%2 != 0) {
            bool flag = false;
            for (int i = 0; i < n - 1; i++) {
                if (__gcd(vec[i], r) == 1 && __gcd(vec[n-1], l+i) == 1) {
                    swap(vec[i], vec[n-1]);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                print_v(vec);
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            print_v(vec);
        }
        

    }

    return 0;

}