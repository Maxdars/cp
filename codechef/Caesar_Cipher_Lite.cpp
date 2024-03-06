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

    int main()
    {

        int t, N, a;
        string P, C;
        cin >> t;

        while(t--) {
            vi ans;
            cin >> N;
            cin >> P >> C;

            for (int i = 0; i < N; i++) {
                int p = P[i] - 'A';
                int c = C[i] - 'A';
                int k = 0;
                while (p != c) {
                    p = (p+3) % 26;
                    k++;
                }
                ans.pb(k);
            }

            print_v(ans);
        }

        return 0;

    }