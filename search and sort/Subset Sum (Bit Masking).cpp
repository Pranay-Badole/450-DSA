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
	
	// TC: 2^(N/2) * log(2^N/2)

	vi all_sum(int l, int r, vi &v){

		int n = r - l + 1;
		vector<int> st;

		for(int i = 0; i < (1 << n); i++){
			int m = i;

			int j = l;
			int sum = 0;

			while(m){
				if(m % 2){sum += v[j];}
				j++;
				m /= 2;
			}
			st.pb(sum);
		}

		sort(all(st));
		return st;
	}

	void fun(vi &v, int n, int a, int b){

		int mid = (n - 1)/2;
		a--;

		auto x = all_sum(0, mid, v);
		auto y = all_sum(mid + 1, n-1, v);

		// auv(x);
		// auv(y);
		
		int ans = 0;
		for(int i = 0; i < sz(x); i++) {
			
			int mx = upper_bound(all(y), b - x[i]) - y.begin() - 1;
			int mn = upper_bound(all(y), a - x[i]) - y.begin() - 1;

			// cout << mn << " " << mx << endl;
			
			ans += (mx - mn);
		
		}
		cout << ans;
	}


	void solve(){
	
		int n, a, b;
		cin >> n >> a >> b;

		vi v(n);

		rep(i,0,n){
			cin >> v[i];
		}

		// auv(v);

		fun(v, n, a, b);
		
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
