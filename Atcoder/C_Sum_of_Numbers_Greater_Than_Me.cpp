    #include <bits/stdc++.h>
    #include <iostream>
    #include <map>

    using namespace std;

    #define ll long long
    #define pii pair<int, int>
    #define pll pair<long long, long long>
    #define vi vector<int>
    #define vll vector<long long>
    #define mll map<long long, long long>
    #define si set<int>
    #define sc set<char>

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

    bool comparePairs(const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second > b.second;
    }

    int main()
    {

        ll i, n, a, sum = 0;
        vll input;
        mll res;

        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a;
            input.push_back(a);
        }

        vll vec = input;
        sort(vec.rbegin(), vec.rend());

        for (auto a: vec) {
            if (!res.count(a)) {
                res[a] = sum;
            }
            sum += a;
        }

        for (auto a: input) {
            cout << res[a] << " ";
        }

        return 0;
    }