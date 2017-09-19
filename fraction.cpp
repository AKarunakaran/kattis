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

double toR(int* a, int n) {
	double r = a[n-1];
	FORD(i, n-2, 0) r = a[i]+(1/r);
	return r;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n1, n2, a[9] = {}, b[9] = {};//, res[100] = {};
    cin >> n1 >> n2;
    REP(i, n1) cin >> a[i];
    REP(i, n2) cin >> b[i];
    double r1 = toR(a, n1), r2 = toR(b, n2);
    double r[4] = {r1+r2, r1-r2, r1*r2, r1/r2};
    REP(j, 4) {
    	vector<int> res;
    	double cur = r[j];
    	while(!EQ(cur, floor(cur)) && !EQ(cur, ceil(cur))) {
    		res.push_back(floor(cur));
    		cur = 1/(cur-floor(cur));
    	}
    	if(EQ(cur, floor(cur))) res.push_back(floor(cur));
    	else res.push_back(ceil(cur));
    	for(int i : res) cout << i << " ";
	    cout << endl;
    }

    return 0;
}