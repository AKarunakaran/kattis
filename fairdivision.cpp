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
typedef pair<double, int> pii;
typedef pair<ll, ll> pll;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t;
    cin >> t;
    REP(test, t) {
    	double p, n;
    	cin >> p >> n;
    	vector<pii> a(n);
    	vector<int> ans(n, 0);
    	REP(i, n) {
    		cin >> a[i].first;
    		a[i].second = i;
    	}
    	sort(a.begin(), a.end());
    	bool flag = false;
    	int fIdx;
    	REP(i, n) {
    		int idx = a[i].second;
    		if(a[i].first >= ceil(p/(n-i))) {
    			flag = true;
    			fIdx = i;
    			break;
    		}
    		ans[idx] = a[i].first;
    		p -= ans[idx];
    	}
    	if(flag) {
    		sort(a.begin()+fIdx, a.end(), [](pii& left, pii& right){return left.first > right.first || (left.first == right.first && left.second < right.second);});
	    	FOR(i, fIdx, n-1) {
	    		int idx = a[i].second;
	    		ans[idx] = ceil(p/(n-i));
	    		p -= ans[idx];
	    	}
    	}
    	if(!EQ(p, 0)) {
    		cout << "IMPOSSIBLE" << endl;
    		continue;
    	}
    	REP(i, n) cout << ans[i] << " ";
    	cout << endl;
    }

    return 0;
}