#include "bits/stdc++.h"
	using namespace std;	
	#define int              long long 
 
	#define pb                push_back
	#define ppb               pop_back
	#define pf                push_front
	#define ppf               pop_front
	#define all(x)            (x).begin(),(x).end()
	#define uniq(v)           (v).erase(unique(all(v)),(v).end())
	#define sz(x)             (int)((x).size())
	#define fr                first
	#define sc                second
	#define pii               pair<int,int>
	#define mkp				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)       for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto &x:v) cout<<x<<' '; cout << endl;
	#define auvv(v)			  for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	#define vi 				  vector<int>
	#define vvi 			  vector<vector<int>>
	#define vc 				  vector<char>
	#define vvc 			  vector<vector<char>>
	#define print(a,b,c)	  cout << a <<' ' << b << ' ' << c << endl;
	#define EPS 1e-6

	const int N=3e5 + 5;
	const int M=1e18 + 7;

	bool comp(vi a, vi b){
		
		if(a[0] == b[0]){
			return (a[1] < b[1]);
		}
		return (a[0] < b[0]);
	
	}

	int next_valid(int i, vvi &v) {
		int l = i+1, r = sz(v) - 1;
		int ans = -1;

		while(l <= r) {
			int mid = l + (r-l) / 2;

			if(v[mid][0] >= v[i][1]){
				ans = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		return ans;
	}

	int dp[1000];

### here
	if we start from 0 ==> sz(v) then sort accd to start time bcz we will appply BS on start time here 
	if we start from sz(v) ==> 0 then sort accd to finish time (BS on end time here)

	int fun(int i, vvi &v) {
		if(i == sz(v)){
			return 0;
		}
		// if(dp[i] != -1){
		// 	return dp[i];
		// }

		int excl = fun(i+1, v);
		int incl = v[i][2];

		int j = next_valid(i, v);

		if(j != -1){
			// cout << "==> " << i << ' ' << j << endl;
			incl += fun(j, v);
		}
		// cout << excl << ' ' << incl << endl;
		return  max(excl, incl);
	}

	void solve(){
		memset(dp, -1, sizeof(dp));

		vvi v = {{3, 5, 2}, {1, 2, 50}, {6, 19, 100}, {2, 100, 101}};
		int n = sz(v);

		sort(all(v), comp);
		auvv(v);

		int ans = fun(0, v);
		cout << ans;
		// cout << next_valid(0, v) << endl;
		// cout << next_valid(1, v) << endl;
		// cout << next_valid(2, v) << endl;
		// cout << next_valid(3, v) << endl;
	}

	signed main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif
		#ifdef SIEVE
			sieve();
		#endif
		#ifdef NCR
			init();
		#endif
 
		int t = 1;
		// cin >> t;
		while(t--) {
			solve();
			cout << endl;
		} 
		return 0;
	}
