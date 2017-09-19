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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int r, c, ans[5] = {};
    char g[51][51];
    cin >> r >> c;
    REP(i, r) REP(j, c) cin >> g[i][j];
    REP(i, r-1) {
    	REP(j, c-1) {
    		int sq = 0;
    		if(g[i][j] == '#' || g[i+1][j] == '#' || g[i][j+1] == '#' || g[i+1][j+1] == '#') continue;
    		sq += (g[i][j] == 'X');
    		sq += (g[i+1][j] == 'X');
    		sq += (g[i][j+1] == 'X');
    		sq += (g[i+1][j+1] == 'X');
    		++ans[sq];
    	}
    }
    REP(i, 5) cout << ans[i] << endl; 

    return 0;
}