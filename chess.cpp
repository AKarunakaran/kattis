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
    int t;
    cin >> t;
    REP(test, t) {
    	char r0, r1, c0, c1;
    	int c[2], r[2];
    	cin >> c0 >> r0 >> c1 >> r1;
    	c[0] = c0 - ('A'-1);
    	c[1] = c1 - ('A'-1);
    	r[0] = r0 - '0';
    	r[1] = r1 - '0';
    	if((c[0]+r[0])%2 != (c[1]+r[1])%2) {
    		cout << "Impossible" << endl;
    		continue;
    	}
    	if(c[0] == c[1] && r[0] == r[1]) {
    		cout << 0 << " " << char(c[0]+('A'-1)) << " " << r[0] << endl;
    		continue;
    	}
    	if(abs(c[0]-c[1]) == abs(r[0]-r[1])) {
    		cout << 1 << " " << char(c[0]+('A'-1)) << " " << r[0] << " " << char(c[1]+('A'-1)) << " " << r[1] << endl;
    		continue;
    	}
    	cout << "2 ";
    	bool good = false;
    	FOR(i, c[0]+1, 8) {
    		if(r[0]+(i-c[0]) > 8) break;
    		if(abs(i-c[1]) == abs(r[0]+(i-c[0])-r[1])) {
    			good = true;
    			cout << char(c[0]+('A'-1)) << " " << r[0] << " " << char(i+('A'-1)) << " " << r[0]+(i-c[0]) << " " << char(c[1]+('A'-1)) << " " << r[1] << endl;
    			break;
    		}
    	}
    	if(good) continue;
    	FORD(i, c[0]-1, 0) {
    		if(r[0]-(c[0]-i) < 0) break;
    		if(abs(i-c[1]) == abs(r[0]-(c[0]-i)-r[1])) {
    			good = true;
    			cout << char(c[0]+('A'-1)) << " " << r[0] << " " << char(i+('A'-1)) << " " << r[0]-(c[0]-i) << " " << char(c[1]+('A'-1)) << " " << r[1] << endl;
    			break;
    		}
    	}
    	if(good) continue;
    	FOR(i, c[0]+1, 8) {
    		if(r[0]-(i-c[0]) < 0) break;
    		if(abs(i-c[1]) == abs(r[0]-(i-c[0])-r[1])) {
    			good = true;
    			cout << char(c[0]+('A'-1)) << " " << r[0] << " " << char(i+('A'-1)) << " " << r[0]-(i-c[0]) << " " << char(c[1]+('A'-1)) << " " << r[1] << endl;
    			break;
    		}
    	}
    	if(good) continue;
    	FORD(i, c[0]-1, 0) {
    		if(r[0]+(c[0]-i) > 8) break;
    		if(abs(i-c[1]) == abs(r[0]+(c[0]-i)-r[1])) {
    			cout << char(c[0]+('A'-1)) << " " << r[0] << " " << char(i+('A'-1)) << " " << r[0]+(c[0]-i) << " " << char(c[1]+('A'-1)) << " " << r[1] << endl;
    			break;
    		}
    	}
    }

    return 0;
}