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

double quad(double* p, bool pos) {
	double disc = sqrt(p[1]*p[1]-4*p[0]*p[2]);
	if(pos) return (-p[1]+disc)/(2*p[2]);
	else return (-p[1]-disc)/(2*p[2]);
}

double f(double* p, double x) {
	double prod = 1, res = 0;
	REP(i, 4) {
		res += prod*p[i];
		prod *= x;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(9);
    while(1) {
    	double b[4], t[4], p[4], d[3];
    	REP(i, 4) cin >> b[i];
    	if(cin.fail()) break;
    	REP(i, 4) cin >> t[i];
    	//REP(i, 4) cout << b[i] << " ";
    	//cout << endl;
    	//REP(i, 4) cout << t[i] << " ";
    	//cout << endl;
    	REP(i, 4) p[i] = t[i]-b[i];
    	FOR(i, 1, 3) d[i-1] = i*p[i];
    	double s1 = quad(d, 1), s2 = quad(d, 0);
    	double maxV = max(max(f(p, 0), f(p, 1)), max(f(p, s1), f(p, s2)));
    	double minV = min(min(f(p, 0), f(p, 1)), min(f(p, s1), f(p, s2)));
    	cout << maxV - minV << endl;
    }

    return 0;
}