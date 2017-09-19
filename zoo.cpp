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

void toLower(string& s) {
	REP(i, s.size()) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] - 'A' + 'a';
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, t = 1;
    string s;
    cin >> n;
    while(n) {
    	map<string, int> ans;
    	getline(cin, s);
    	REP(i, n) {
    		getline(cin, s);
	    	istringstream iss(s);
	    	while(iss.good()) iss >> s;
	    	toLower(s);
	    	++ans[s];
    	}
    	cout << "List " << t << ":" << endl;
    	for(auto itr = ans.begin(); itr != ans.end(); ++itr) cout << itr->first << " | " << itr->second << endl;
    	cin >> n;
    	++t;
    }

    return 0;
}