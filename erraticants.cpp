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
#include <tuple>
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

struct moveStr {
	bool N, E, S, W;
};

void dir(char c, int& x, int& y, vector<vector<moveStr>>& g) {
	if(c == 'N') {
		g[x][y].N = true;
		y += 1;
		g[x][y].S = true;
	}
	if(c == 'E') {
		g[x][y].E = true;
		x += 1;
		g[x][y].W = true;
	}
	if(c == 'S') {
		g[x][y].S = true;
		y -= 1;
		g[x][y].N = true;
	}
	if(c == 'W') {
		g[x][y].W = true;
		x -= 1;
		g[x][y].E = true;
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    REP(t, n) {
    	int s;
    	cin >> s;
    	vector<vector<moveStr>> g(200, vector<moveStr>(200, {0, 0, 0, 0}));
    	vector<vector<bool>> c(200, vector<bool>(200, 0));
    	int x = 100, y = 100;
    	REP(i, s) {
    		char c;
    		cin >> c;
    		dir(c, x, y, g);
    	}
    	c[x][y] = 1;
    	int ans = 0;
    	queue<pair<pair<int, int>, int>> next;
    	next.push({{x, y}, 0});
    	c[x][y] = 1;
    	while(!next.empty()) {
    		int d = next.front().second;
    		int curX = next.front().first.first, curY = next.front().first.second;
    		next.pop();
    		if(curX == 100 && curY == 100) {
    			ans = d;
    			break;
    		}
    		if(g[curX][curY].N && !c[curX][curY+1]) {
    			next.push({{curX, curY+1}, d+1});
    			c[curX][curY+1] = 1;
    		}
    		if(g[curX][curY].S && !c[curX][curY-1]) {
    			next.push({{curX, curY-1}, d+1});
    			c[curX][curY-1] = 1;
    		}
    		if(g[curX][curY].E && !c[curX+1][curY]) {
    			next.push({{curX+1, curY}, d+1});
    			c[curX+1][curY] = 1;
    		}
    		if(g[curX][curY].W && !c[curX-1][curY]) {
    			next.push({{curX-1, curY}, d+1});
    			c[curX-1][curY] = 1;
    		}
    	}
    	cout << ans << endl;
    }

    return 0;
}