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


	int check(int mid, vi &v, int c){

		int last = v[0];
		int k = 1;

		for(int i = 0; i < sz(v); i++){
			if(v[i] - last >= mid){
				k++;
				last = v[i];
				if(k == c){
					return 1;
				}
			}
		}
		return 0;
	}

	void solve(){

		int n, c;
		cin >> n >> c;

		vector<int> v;

		rep(i,0,n){
			int s;
			cin >> s;
			v.pb(s);
		}		
 	
 		sort(all(v));
		
		int l = 0, r = v[n-1] - v[0];
		
		int ans;

		while (l <= r){
			int mid = l + (r-l) / 2;
			
			int flag = check(mid, v, c);

			if(flag){
				ans = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;			
			}
		}
		cout << ans;
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
		cin >> t;
		while(t--) {
			solve();
			cout << endl;
		} 
		return 0;
	}
