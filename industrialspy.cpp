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
#include <unordered_set>
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

vector<bool> prime(10001, 1);
vector<int> primes;

void perm(vector<int>& nums, vector<bool>& used, unordered_set<int>& seen, int cur, int& ans) {
	if(seen.find(cur) != seen.end()) return;
	else seen.insert(cur);
	//DEBUG(cur);
	int i = 0;
    bool p = cur > 1;
    while(primes[i]*primes[i] <= cur && i < primes.size()) {
        if(cur % primes[i] == 0) {
            p = false;
            break;
        }
        ++i;
    }
    if(p) {
        ++ans;
        //DEBUG(cur);
    }
	REP(i, nums.size()) {
		if(used[i]) continue;
		used[i] = 1;
		perm(nums, used, seen, cur*10 + nums[i], ans);
		used[i] = 0;
	}
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    prime[0] = prime[1] = 0;
    FOR(i, 2, 100) {
    	if(prime[i]) {
    		for(int j = 2*i; j <= 10000; j += i) {
    			prime[j] = 0;
    		}
    	}
    }
    FOR(i, 2, 10000) if(prime[i]) primes.push_back(i);
    int c;
    scanf("%d", &c);
    REP(test, c) {
    	string s;
    	cin >> s;
    	unordered_set<int> seen;
    	vector<int> nums;
    	REP(i, s.size()) nums.push_back(s[i]-'0');
    	vector<bool> used(nums.size(), 0);
    	int ans = 0;
    	perm(nums, used, seen, 0, ans);
    	printf("%d\n", ans);
    }

    return 0;
}