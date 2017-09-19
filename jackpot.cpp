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

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

ll w[100];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t;
    cin >> t;
    REP(test, t) {
    	int n;
    	cin >> n;
    	REP(i, n) cin >> w[i];
    	ll ans = w[0];
    	bool flag = false;
    	FOR(i, 1, n-1) {
    		ans = (ans/gcd(ans, w[i]))*w[i];
    		if(ans > 1000000000 || ans < 0) {
    			cout << "More than a billion." << endl;
    			flag = true;
    			break;
    		}
    	}
    	if(flag) continue;
    	cout << ans << endl;
    }

    return 0;
}