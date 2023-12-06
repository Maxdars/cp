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

    int smallest(int x, int y, int z) {
        int smallest = x;
        if (y < smallest)
            smallest=y;
        if(z < smallest)
            smallest=z;

        return smallest;
        }

    int countEggs(int n, int s, int m, int l) {

        if (n <= 0) return 0;

        return smallest(
            s + countEggs(n-6, s, m, l),
            m + countEggs(n-8, s, m, l),
            l + countEggs(n-12, s, m, l)
        );

    }

    int main()
    {

        int n, s, m, l;
        cin >> n >> s >> m >> l ;        

        cout << countEggs(n, s, m, l) << endl;

        return 0;
    }