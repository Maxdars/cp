#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vull vector<unsigned long long>
#define vs vector<string>
#define vll vector<long long>
#define mci map<char, int>
#define si set<int>
#define sc set<char>
#define ull unsigned long long

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


vs splitString(string delimiter, string s) {
  vs result;
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
      token = s.substr(0, pos);
      if (!token.empty()) result.pb(token);
      s.erase(0, pos + delimiter.length());
  }
  result.pb(s);
  return result;
}

/* --- Part one --- */
map<string,int> memo;
int getHashValue(string s) {
  if (memo.find(s) != memo.end()) return memo[s];
  int value = 0;
  for (int i = 0; i < s.length(); i++) {
    value += int(s[i]);
    value *= 17;
    value %= 256;
  }
  memo[s] = value;
  return value;
}

/* --- Part two --- */
int searchValue(vector<pair<string,int>> vec, string label) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i].first == label) return i;
  }
  return -1;
}

/* --- Part two --- */
void insertLens(string label, int val, map<int, vector<pair<string,int>>> &boxes) {
  int num = getHashValue(label), k;
  pair<string,int> lens = make_pair(label, val);
  k = searchValue(boxes[num], label);
  if (k != -1) {
    boxes[num][k].second = val;
  }
  else {
    boxes[num].pb(lens);
  }
}

/* --- Part two --- */
void remeoveLens(string label, map<int, vector<pair<string,int>>> &boxes) {
  int num = getHashValue(label), k;
  k = searchValue(boxes[num], label);
  if (k != -1) {
    boxes[num].erase(boxes[num].begin() + k);
  }
}

/* --- Part two --- */
void print_boxes(map<int, vector<pair<string,int>>> boxes) {
  for (int i = 0; i < boxes.size(); i++) {
    if (empty(boxes[i])) continue;
    for (int j = 0; j < boxes[i].size(); j++) {
      cout << "(" << boxes[i][j].first << "," << boxes[i][j].second << ") ";
    }
    cout << endl;
  }
}

int main() {
    string s, seq, label;
    int num, val, ans = 0;

    while(getline(cin, s)) {      
      seq += s;
    }

    vs vec = splitString(",", seq), line;
    map<int, vector<pair<string,int>>> boxes;

    for(auto hash: vec) {
      if (hash[hash.length() - 1] == '-') {
        label = hash.substr(0, hash.length() - 1);
        remeoveLens(label, boxes);
      }
      else {
        line = splitString("=", hash);
        label = line[0];
        val = stoi(line[1]);
        insertLens(label, val, boxes);
      }
    }

    for (int i = 0; i < boxes.size(); i++) {
      if (empty(boxes[i])) continue;
      for (int j = 0; j < boxes[i].size(); j++) {
        ans += ((i+1) * (j+1) * boxes[i][j].second);
      }
    }
   
    cout << ans << endl;

    return 0;
}
