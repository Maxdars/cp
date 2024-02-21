    #include <bits/stdc++.h>

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

        ll t, n, m, l, x, y;
        cin >> t;

        while(t--) {
            cin >> n >> m >> x >> y >> l;
            ll ans = 0;
            
            ll n_u = x/l + (x%l == 0 ? 0 : 1);
            ll n_d = (n - x)/l;
            
            ll m_l = y/l + (y%l == 0 ? 0 : 1);
            ll m_r = (m - y)/l;

            ans += (m_l + m_r)*(n_u + n_d);

            cout << ans << endl;
        
        }

        return 0;

    }