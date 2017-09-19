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

double x, y, w, h, r;

double dist(pair<double, double> p1, pair<double, double> p2) {
	return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}

bool rect1(double a, double b) {
	return a >= x && a <= x+w && b >= y+r && b <= y+h-r;
}

bool rect2(double a, double b) {
	return a >= x+r && a <= x+w-r && b >= y && b <= y+h;
}

bool circ(double a, double b, vector<pair<double, double>>& c) {
	REP(i, 4) {
		if(dist({a, b}, c[i]) <= r) return true;
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t;
    scanf("%d", &t);
    REP(test, t) {
    	int m;
    	scanf("%lf %lf %lf %lf %lf %d", &x, &y, &w, &h, &r, &m);
    	vector<pair<double, double>> c(4);
    	c[0] = {x+r, y+r};
    	c[1] = {x+w-r, y+r};
    	c[2] = {x+r, y+h-r};
    	c[3] = {x+w-r, y+h-r};
    	REP(i, m) {
    		double a, b;
    		scanf("%lf %lf", &a, &b);
    		if(rect1(a, b) || rect2(a, b) || circ(a, b, c)) printf("inside\n");
    		else printf("outside\n");
    	}
    	printf("\n");
    }

    return 0;
}