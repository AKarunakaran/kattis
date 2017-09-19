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

vector<pair<int, int>> ant;

int solve(int idx) {
	int opp = 0;
	if(ant[idx].second) {
		FOR(i, idx+1, ant.size()-1) if(!ant[i].second) ++opp;
		return idx+opp;
	} else {
		FORD(i, idx-1, 0) if(ant[i].second) ++opp;
		return idx-opp;
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    while(1) {
    	int l, a;
    	cin >> l >> a;
    	ant.resize(a);
    	if(cin.fail()) exit(0);
    	REP(i, a) {
    		char c;
    		cin >> ant[i].first >> c;
    		ant[i].second = (c == 'R') ? 1 : 0;
    	}
    	sort(ant.begin(), ant.end());
    	int maxT = 0;
    	REP(i, a) {
    		if(ant[i].second) maxT = max(maxT, l-ant[i].first);
    		else maxT = max(maxT, ant[i].first);
    	}
    	vector<int> ans;
    	REP(i, a) {
    		if(ant[i].second && l-ant[i].first == maxT) ans.push_back(solve(i));
    		else if(!ant[i].second && ant[i].first == maxT) ans.push_back(solve(i));
    	}
    	sort(ans.begin(), ans.end());
    	cout << "The last ant will fall down in " << maxT << " seconds - started at " << ant[ans[0]].first;
    	if(ans.size() == 2) cout << " and " << ant[ans[1]].first;
    	cout << '.' << endl;
    }


    return 0;
}