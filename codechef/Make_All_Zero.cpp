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

    int main()
    {

        int t, N, a;
        cin >> t;

        while(t--) {
            cin >> N;
            vi A, mins;
            int min_a = 10e6, decr = 0;

            for (int i = 0; i < N; i++) {
                cin >> a;
                A.pb(a);
                min_a = min(min_a, a);
                mins.pb(min_a);
            }

            // print_v(A);
            // print_v(mins);

            int ans = 0;
            for (int i = N-1; i >= 0; i--) {
                if ((A[i] - decr) > 0 && mins[i] - decr > 0 && (A[i] - decr) <= (mins[i] - decr)) {
                    decr++;
                    ans += 1;
                }
                else if ((A[i] - decr) > 0 ) { // && mins[i] - decr == 0
                    ans += 1;
                }
            }

            cout << ans << endl;
        }

        return 0;

    }