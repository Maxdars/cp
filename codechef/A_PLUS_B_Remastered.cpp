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

        int t, N, A, B;
        cin >> t;

        while(t--) {
            vi vec_A, vec_B;
            bool flag = true;

            cin >> N;
            for (int i = 0; i < N; i++) {
                cin >> A;
                vec_A.pb(A);
            }
            for (int i = 0; i < N; i++) {
                cin >> B;
                vec_B.pb(B);
            }

            sort(vec_A.begin(), vec_A.end());
            sort(vec_B.begin(), vec_B.end(), greater<>());

            for (int i = 1; i < N; i++) {
                if (vec_A[i]+vec_B[i] != vec_A[i-1]+vec_B[i-1]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                print_v(vec_A);
                print_v(vec_B);
            }
            else {
                cout << -1 << endl;
            }
        }

        return 0;

    }