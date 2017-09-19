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
    	multiset<pair<int, int>> s;
    	int ng, nm;
    	cin >> ng >> nm;
    	REP(i, ng) {
    		int in;
    		cin >> in;
    		s.insert({in, 2});
    	}
    	REP(i, nm) {
    		int in;
    		cin >> in;
    		s.insert({in, 1});
    	}
    	auto itr = s.begin();
    	while(ng && nm) {
    		if(itr->second == 1) --nm;
    		else --ng;
    		++itr;
    	}
    	if(ng) cout << "Godzilla" << endl;
    	else cout << "MechaGodzilla" << endl;
    }

    return 0;
}