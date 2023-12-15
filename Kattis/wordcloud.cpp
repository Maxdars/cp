#include <bits/stdc++.h>

using namespace std;

/* Data Type  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* Functions */
  /* Loop */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)

#define pb push_back
#define eb emplace_back

/* Printing vector */
template <class T>
void print_v(vector<T> &v) { cout << '{'; for (auto x : v) cout << x << ','; cout << '}'; cout << endl; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int main()
{
    int t, w;
    vi ans;

    while (true) {
        cin >> w >> t;
        if (t == 0 && w == 0 ) break;
        vi occ;
        vi widths;
        vi sizes;
        vs words;
        string word;
        int max_occ = 0;
        int n;

        int count = t;
        while (count--) {
            cin >> word >> n;
            words.push_back(word);
            occ.push_back(n);
            if (n > max_occ) max_occ = n;
        }

        for (int i = 0; i < t; i++) {
            sizes.push_back(8 + ceil((40 * (float)(occ[i]-4)) / (max_occ - 4)));
            widths.push_back(ceil((words[i].length() * sizes[i]) * (float)(0.5625)));
        }

        int current_width = 0;
        int max_current_height = 0;
        vi heights;

        for (int i = 0; i < t; i++) {
            if (current_width + widths[i] > w) {
                current_width = widths[i] + 10;
                heights.push_back(max_current_height);
                max_current_height = sizes[i];
            }
            else {
                if (sizes[i] > max_current_height) max_current_height = sizes[i];
                current_width += widths[i] + 10;
            }
        }

        heights.push_back(max_current_height);

        int sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            sum += heights[i];
        }

        ans.push_back(sum);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << "CLOUD " << i + 1 << ": " << ans[i] << endl;
    }

    return 0;

}