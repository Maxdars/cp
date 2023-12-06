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

/* Utility */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }

int main()
{

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int k = s[1] - '0';
        char c = s[0];

        for(int i = 1; i <= 8; i++) {
            if (i != (int)k) {
                cout << c << i << endl;
            }
        }

        char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        for(int i = 0; i < 8; i++) {
            if (letters[i] != c) {
                cout << letters[i] << k << endl;
            }
        }
    }

    return 0;

}