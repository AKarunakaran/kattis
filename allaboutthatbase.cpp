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

map<char, int> m;
map<int, char> rm;

int convOp(string& s) {
	if(s == "+") return 0;
	if(s == "-") return 1;
	if(s == "*") return 2;
	if(s == "/") return 3;
	return -1;
}

int convert(string& s, int b) {
	int num = 0;
	int rad = 1;
	FORD(i, s.size()-1, 0) {
		if(m[s[i]] >= b) return -1;
		num += rad*m[s[i]];
		rad *= b;
	}
	return num;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    char c = '0';
    FOR(i, 0, 9) {
    	m[c+i] = i;
    	rm[i] = c+i;
    }
    c = 'a';
    FOR(i, 0, 25) {
    	m[c+i] = i+10;
    	rm[i+10] = c+i;
    }
    int n;
    cin >> n;
    REP(i, n) {
    	vector<char> sol;
    	FOR(b, 1, 36) {
    		string s;
    		int x, y, z, op;
    		cin >> s;
    		x = convert(s, b);
    		cin >> s;
    		op = convOp(s);
    		cin >> s;
    		y = convert(s, b);
    		cin >> s >> s;
    		z = convert(s, b);
    		if(x < 0 || y < 0 || z < 0) continue;
    		if(op == 0 && x + y == z) sol.push_back(rm[b]);
    		else if(op == 1 && x - y == z) sol.push_back(rm[b]);
    		else if(op == 2 && x * y == z) sol.push_back(rm[b]);
    		else if(op == 3 && x / y == z) sol.push_back(rm[b]);
    	}
    	if(sol.size()) REP(i, sol.size()) cout << sol[i];
    	else cout << "invalid";
    	cout << endl;
    }

    return 0;
}