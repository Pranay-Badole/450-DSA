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

	void solve(){

		int n, q;
		cin >> n >> q;

		vector<pii> v;

		rep(i,0,n){
			int a, b;
			cin >> a >> b;
			v.pb({a, b});
		}

		sort(all(v));

		vector<pii> final;
		final.pb(v[0]);

		rep(i,1,sz(v)){
			pii last = *final.rbegin();
			if(v[i].fr <= last.sc + 1){
				(*final.rbegin()).sc = max(v[i].sc, (*final.rbegin()).sc);
			}
			else{
				final.pb(v[i]);
			}
		}
		// aump(v);
		v.clear();

		int left = 1;
		for(int i = 0; i < sz(final); i++){
			int right = left + final[i].sc - final[i].fr;
			v.pb({left, right});
			left = right + 1;
		}
		// cout << left;
		// aump(final);
		// cout << endl;

		while(q--){
			int k;
			cin >> k;
			
			if(k >= left){
				cout << -1 << endl;

				continue;
			}

			int l = 0, r = sz(final) - 1;
 				
 			while(l <= r){
 				int mid = l + (r-l)/2;
 				if((k >= v[mid].fr) && (k <= v[mid].sc)){
 					cout << final[mid].fr + (k - v[mid].fr) << endl;
 					break;
 				}
 				else if(k < v[mid].fr){
 					r = mid - 1;
 				}
 				else{
 					l = mid + 1;
 				}
 			}
 		}
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
