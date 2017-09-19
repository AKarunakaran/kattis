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

double slope(pii& p1, pii& p2) {
	return (double)(p2.second-p1.second)/(double)(p2.first-p1.first);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    if(n <= 3) {
    	cout << "success" << endl;
    	exit(0);
    }
    vector<pii> p(n);
    REP(i, n) cin >> p[i].first >> " " >> p[i].second;
    bool good = true;
    FOR(i, 3, n-1) {
    	if(!EQ(slope(p[1], p[i]), slope(p[1], p[2])) {
    		good = false;
    		break;
    	}
    }
    if(good) {
    	cout << "success" << endl;
    	exit(0);
    }
    double s1 = slope(p[0], p[1]);
    int idx = 2;
    while(EQ(slope(p[0], p[1]), slope(p[0], p[idx]))) ++idx;
    

    return 0;
}