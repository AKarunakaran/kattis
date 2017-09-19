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
    string s;
    cin >> s;
    int n = s.size();
    int idx = 0;
    FOR(i, 0, n-3) {
    	if(s[i] == s[idx]) {
    		FOR(j, 1, i-idx) {
    			if(s[i-j] < s[idx+j]) {
    				idx = i;
    				break;
    			}
    		}
    	}
    	if(s[i] < s[idx]) idx = i;
    }
    ++idx;
    reverse(s.begin(), s.begin()+idx);
    int k = idx;
    FOR(i, k, n-2) {
    	if(s[i] == s[idx]) {
    		FOR(j, 1, i-idx) {
    			if(s[i-j] < s[idx+j]) {
    				idx = i;
    				break;
    			}
    		}
    	}
    	if(s[i] < s[idx]) idx = i;
    }
    ++idx;
    reverse(s.begin()+k, s.begin()+idx);
    reverse(s.begin()+idx, s.end());
    cout << s << endl;

    return 0;
}