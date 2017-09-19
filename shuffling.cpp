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

int n, type, ans = 0;
vector<int> a, nxt;

void shuffle() {
	vector<int> b(n);
	REP(i, n) b[nxt[i]] = a[i];
	a = b;
	++ans;
}

bool good() {
	FOR(i, 1, n-1) if(a[i] < a[i-1]) return false;
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    cin >> n >> s;
    if(n == 1) {
    	cout << 1 << endl;
    	exit(0);
    }
    a.resize(n);
    type = (s == "out") ? 0 : 1;
    nxt.resize(n);
    REP(i, n) {
    	if(type == 0) {
			if(i <= (n-1)/2) nxt[i] = 2*i;
			else nxt[i] = 2*(i-((n-1)/2+1))+1;
		} else {
			if(i <= (n-2)/2) nxt[i] = 2*i+1;
			else nxt[i] = 2*(i-(n/2));
		}
    }
    REP(i, n) a[i] = i;
    shuffle();
    while(!good()) shuffle();
    cout << ans << endl;

    return 0;
}