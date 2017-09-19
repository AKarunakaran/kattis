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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int mr, mc;
bool g[1000][1000];
vector<vector<int>> cl;

void bfs(int r, int c, int h) {
	queue<pii> next;
	next.push({r, c});
	while(!next.empty()) {
		r = next.front().first;
		c = next.front().second;
		next.pop();
		cl[r][c] = h;
		if(r != mr-1 && g[r+1][c] == g[r][c] && cl[r+1][c] == 0) next.push({r+1, c});
		if(r != 0 && g[r-1][c] == g[r][c] && cl[r-1][c] == 0) next.push({r-1, c});
		if(c != mc-1 && g[r][c+1] == g[r][c] && cl[r][c+1] == 0) next.push({r, c+1});
		if(c != 0 && g[r][c-1] == g[r][c] && cl[r][c-1] == 0) next.push({r, c-1});
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int r, c;
    scanf("%d %d\n", &r, &c);
    mr = r;
    mc = c;
    REP(i, r) {
    	REP(j, c) {
    		char ch;
    		scanf(" %c", &ch);
    		g[i][j] = (ch == '1');
    	}
    }
    /*REP(i, r) {
    	REP(j, c) cout << g[i][j];
    	cout << endl;
    }*/
    cl.resize(r, vector<int> (c, 0));
    int h = 1;
    REP(i, r) {
    	REP(j, c) {
    		if(cl[i][j]) continue;
    		bfs(i, j, h);
    		++h;
    	}
    }
    int n;
    scanf("%d", &n);
    REP(i, n) {
    	int r1, r2, c1, c2;
    	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    	--r1; --r2; --c1; --c2;
    	if(cl[r1][c1] == cl[r2][c2]) {
    		if(g[r1][c1]) printf("decimal\n");
    		else printf("binary\n");
    	} else printf("neither\n");
    }
    fflush(stdin);

    return 0;
}