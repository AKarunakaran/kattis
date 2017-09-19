#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <unordered_map>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

unordered_map<string, vector<string>> g;

int command(string& s) {
	if(s == "union") return 1;
	if(s == "intersection") return 2;
	if(s == "difference") return 3;
	return 0;
}

void print(vector<string>& s) {
	REP(i, s.size()) cout << s[i] << " ";
	cout << endl;
}

vector<string> solve(int c, istringstream& cmd) {
	string in;
	vector<string> s1, s2, res;
	int cm;
	cmd >> in;
	cm = command(in);
	if(cm == 0) s1 = g[in];
	else s1 = solve(cm, cmd);
	cmd >> in;
	cm = command(in);
	if(cm == 0) s2 = g[in];
	else s2 = solve(cm, cmd);
	res.resize(s1.size()+s2.size());
	vector<string>::iterator it;
	if(c == 1) it = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());
	else if(c == 2) it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());
	else it = set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());

	res.resize(it-res.begin());

	return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string in;
    getline(cin, in);
    while(in.substr(0, 5) == "group") {
    	int n;
    	istringstream cmd(in);
    	cmd >> in >> in >> n;
    	auto& v = g[in];
    	REP(i, n) {
    		cmd >> in;
    		v.push_back(in);
    	}
    	sort(v.begin(), v.end());
    	getline(cin, in);
    }
    while(cin.good()) {
    	vector<string> ans;
    	istringstream cmd(in);
	    cmd >> in;
    	int c = command(in);
    	if(c == 0) {
	    	ans = g[in];
	    	print(ans);
	    	getline(cin, in);
	    	continue;
	    }
	    ans = solve(c, cmd);
	    sort(ans.begin(), ans.end());
	    print(ans);
	    getline(cin, in);
    }
    vector<string> ans;
	istringstream cmd(in);
    cmd >> in;
	int c = command(in);
	if(c == 0) ans = g[in];
    else ans = solve(c, cmd);
    print(ans);

    return 0;
}