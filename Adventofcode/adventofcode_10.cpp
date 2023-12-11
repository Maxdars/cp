#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>
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

vs matrix;

/* --- Part one --- */
// int checkRoad(int i, int j, int source_i, int source_j){
//   if (matrix[i][j] == 'S') return 0;
//   if (matrix[i][j] == '.' || i >= matrix.size() || j >= matrix[0].size()) return -10e6;

//   if (matrix[i][j] == '|') {
//     return 1 + checkRoad((source_i < i ? i+1 : i-1), j, i, j);
//   } 
//   if (matrix[i][j] == '-') {
//     return 1 + checkRoad(i, (source_j < j ? j+1 : j-1), i, j);
//   } 
//   if (matrix[i][j] == 'L') {
//     return 1 + checkRoad((source_i == i ? i-1 : i), (source_j == j ? j+1 : j), i, j);
//   } 
//   if (matrix[i][j] == 'J') {
//     return 1 + checkRoad((source_i == i ? i-1 : i), (source_j == j ? j-1 : j), i, j);
//   } 
//   if (matrix[i][j] == '7') {
//     return 1 + checkRoad((source_i == i ? i+1 : i), (source_j == j ? j-1 : j), i, j);
//   }
//   if (matrix[i][j] == 'F') {
//     return 1 + checkRoad((source_i == i ? i+1 : i), (source_j == j ? j+1 : j), i, j);
//   }
// }

/* --- Part two --- */
int checkRoad(int i, int j, int source_i, int source_j, vector<vi> &path) {
  if (matrix[i][j] == '.' || i >= matrix.size() || j >= matrix[0].size()) return -10e6;
  if (matrix[i][j] == 'S') return 0;

  path[i].pb(j);
  if (matrix[i][j] == '|') {
    if ((source_i == i-1 || source_i == i+1)) {
      return 1 + checkRoad((source_i < i ? i+1 : i-1), j, i, j, path);
    }
    return -10e6;
  } 
  if (matrix[i][j] == '-') {
    if ((source_j == j-1 || source_j == j+1)) {
    return 1 + checkRoad(i, (source_j < j ? j+1 : j-1), i, j, path);
    }
    return -10e6;
  } 
  if (matrix[i][j] == 'L') {
    if ((source_i == i-1 || source_j == j+1)) {
      return 1 + checkRoad((source_i == i ? i-1 : i), (source_j == j ? j+1 : j), i, j, path);
    }
    return -10e6;
  } 
  if (matrix[i][j] == 'J') {
    if ((source_i == i-1 || source_j == j-1)) {
      
      return 1 + checkRoad((source_i == i ? i-1 : i), (source_j == j ? j-1 : j), i, j, path);
    }
    return -10e6;
  } 
  if (matrix[i][j] == '7') {
    if ((source_i == i+1 || source_j == j-1)) {
      return 1 + checkRoad((source_i == i ? i+1 : i), (source_j == j ? j-1 : j), i, j, path);
    }
     return -10e6;

  }
  if (matrix[i][j] == 'F') {
    if ((source_i == i+1 || source_j == j+1)) {
          return 1 + checkRoad((source_i == i ? i+1 : i), (source_j == j ? j+1 : j), i, j, path);
    }
    return -10e6;
  }

  return -10e6;
}

int main() {
    string s;


    int start_i, start_j, i = 0;
    while (getline(cin, s)) {
      matrix.pb(s);
      for (int j = 0; j < s.length(); j++) {
        if (s[j] == 'S') {
          start_i = i;
          start_j = j;
        } 
      }
      i++;
    }


    /* --- Part one --- */
    // vi ans;
    // ans.pb(1 + checkRoad(start_i + 1, start_j, start_i, start_j));
    // ans.pb(1 + checkRoad(start_i - 1, start_j, start_i, start_j));
    // ans.pb(1 + checkRoad(start_i, start_j + 1, start_i, start_j));
    // ans.pb(1 + checkRoad(start_i, start_j - 1, start_i, start_j));
    // cout <<  ceil(*max_element(ans.begin(), ans.end()) / 2) << endl;

    /* --- Part one --- */
    int ans = -10e6;
    vector<vi> ans_vec;

    vector<vi> down_vec(matrix.size());
    int down = 1 + checkRoad(start_i + 1, start_j, start_i, start_j, down_vec);
    if (down > ans) {
      ans = down;
      ans_vec = down_vec;
    }

    vector<vi> up_vec(matrix.size());  
    int up = (1 + checkRoad(start_i - 1, start_j, start_i, start_j, up_vec));
    if (up > ans) {
      ans = up;
      ans_vec = up_vec;
    }

    vector<vi> right_vec(matrix.size());
    int right = 1 + checkRoad(start_i, start_j + 1, start_i, start_j, right_vec);
    if (right > ans) {
      ans = right;
      ans_vec = right_vec;
    }

    vector<vi> left_vec(matrix.size());
    int left = 1 + checkRoad(start_i, start_j - 1, start_i, start_j, left_vec);
    if (left > ans) {
      ans = left;
      ans_vec = left_vec;
    }

    ans = 0;
    ans_vec[start_i].pb(start_j);
    string s_test (matrix[0].length(), '.');
    vector<string> test(matrix.size(),s_test);
    for (int i = 0; i < ans_vec.size(); i++) {
      for (int j = 0; j < ans_vec[i].size(); j++) {
        test[i][ans_vec[i][j]] = '*';
      }
    }
    for (auto x: test) {
      cout << x << endl;
    }
    // for (auto x: ans_vec) {
    //   //if (!x.empty()) {
    //     sort(x.begin(), x.end());
    //     int ground = 0;
    //     // print_v(x);
    //     for (int i = 1; i < x.size(); i=i+2) {
    //       ground += (x[i] - x[i-1] - 1);
    //     }
    //     // cout << "ground : " << ground << endl;
    //     ans += ground;
    //   //}
    // }

    cout << ans << endl;

    return 0;
}
