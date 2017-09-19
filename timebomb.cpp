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

string s[5];
string nums[10][5] = {{"***", "* *", "* *", "* *", "***"},
	{"  *", "  *", "  *", "  *", "  *"},
	{"***", "  *", "***", "*  ", "***"},
	{"***", "  *", "***", "  *", "***"},
	{"* *", "* *", "***", "  *", "  *"},
	{"***", "*  ", "***", "  *", "***"},
	{"***", "*  ", "***", "* *", "***"},
	{"***", "  *", "  *", "  *", "  *"},
	{"***", "* *", "***", "* *", "***"},
	{"***", "* *", "***", "  *", "***"},
	};

bool check(int n, int start) {
	REP(i, 5) if(s[i].substr(start, 3) != nums[n][i]) return false;
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, 5) getline(cin, s[i]);
    int n = 0;
    REP(i, (s[0].size()+1)/4) {
    	int num = -1;
    	REP(j, 10) {
    		if(check(j, 4*i)) {
    			num = j;
    			break;
    		}
    	}
    	if(num == -1) {
    		cout << "BOOM!!" << endl;
    		exit(0);
    	} else {
    		n = n*10 + num;
    	}
    }
    cout << (n % 6 ? "BOOM!!" : "BEER!!") << endl;

    return 0;
}