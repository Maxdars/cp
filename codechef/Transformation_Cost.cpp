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

    ll solve(string bin, int idx) {
        ll ans = 0;
        for (int i = bin.size() - 1; i > 0; i--) {
            if (bin[i] == '1') {
                int j = i-1;
                while (j >= 0 && bin[j] != '0') {
                    bin[j] = '0';
                    j--;
                }
                if (j <= 0) {
                    return ans;
                }
                else {
                    ans += (pow(2, (bin.size() - i - 1)));
                    bin[j] = '1';
                }
            }
        }
        return ans;
    }

    int main()
    {

        ll t, n;
        cin >> t;

        while(t--) {
            cin >> n ;
            ll ans = 0;
            
            string binary = bitset<32>(n).to_string();
            binary = binary.erase(0, binary.find_first_not_of('0'));

            ans = solve(binary, binary.size() - 1);
            cout << ans << endl;
        }

        return 0;

    }