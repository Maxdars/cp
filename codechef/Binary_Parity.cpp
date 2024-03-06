
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

    int t, n, a, q, x;
    cin >> t;

    while(t--) {
        
        cin >> n;
        string s;
        s = toBinary(n);
        if (count(s.begin(), s.end(), '1')%2 == 0) cout << "EVEN" << endl;
        else cout << "ODD" << endl;

    }

    return 0;

}