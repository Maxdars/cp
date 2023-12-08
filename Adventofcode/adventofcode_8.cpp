#include <bits/stdc++.h>
#include <iostream>
#include <istream>
#include <sstream>
#include <regex>
#include <map>

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

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

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
void yes() { std::cout<<"YES"<<endl; }
void no() { std::cout<<"NO"<<endl; }

vector<string> splitString(string delimiter, string s) {
  vector<string> result;
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

map<string,pair<string,string> > nodes;
string seq;

/* ---- Part 1 ---- */
ll lookup(int seq_index, string current_node) {
    if (current_node == "ZZZ") return 0;
    if (seq_index == seq.length()) seq_index = 0;
    string next_node = seq[seq_index] == 'L' ? nodes[current_node].first : nodes[current_node].second;
    return 1 + lookup(seq_index+1, (seq[seq_index] == 'L' ? nodes[current_node].first : nodes[current_node].second));
}

/* ---- Part 2 ---- */
ll lookupMultiple(int seq_index, string current_node, ll counter) {
      if (current_node[2] == 'Z') {
        return counter;
      }

      if (seq_index == seq.length()) seq_index = 0;
      counter++;
      string next_node = seq[seq_index] == 'L' ? nodes[current_node].first : nodes[current_node].second;
      return lookupMultiple(seq_index+1, next_node, counter);
}

int main() {
    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }
        size_t pos = 0;
        if ((pos = line.find("=")) != string::npos) {
          vector<string> arr = splitString(" = ", line);
          vector<string> childs = splitString(", ", arr[1]);
          string left = childs[0].substr(1);
          string right = childs[1].substr(0, childs[1].length() - 1);
          nodes[arr[0]] = make_pair(left, right);
          arr.clear();
          childs.clear();
        }
        else {
          seq = line;
        }
    }


    vll starting_nodes;
    for (auto x: nodes) {
      if (x.first[2] == 'A') {
        ll min_z = lookupMultiple(0, x.first, 0);
        starting_nodes.pb(min_z);
      }
    }

    /* --- Part two --- */
    ll n_lcm = lcm(starting_nodes[0], starting_nodes[1]);
    for (ll i = 2; i < starting_nodes.size(); i++) {
        n_lcm = lcm(starting_nodes[i], n_lcm);
    }

    cout << n_lcm << endl;

    /* --- Part one --- */
    // ll ans = lookup(0, starting_nodes);
    // std::cout << ans << endl;

    return 0;
}

// https://adventofcode.com/2023/day/8