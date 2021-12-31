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

	pii partition(vi &v, int l, int r) {
		int pivot = v[l];

		int j = l + 1;
		int le = l, gr = r;
		int i = l;

		while(i <= gr){
			if(v[i] < pivot){
				swap(v[i], v[le]);
				i++;
				le++;
			}
			else if(v[i] > pivot){
				swap(v[i], v[gr]);
				gr--;
			}
			else{
				i++;
			}
		}
		return {le, gr};
	}

	void quick_sort(vi &v, int l, int r) {	
		if(l >= r){
			return;
		}

		pii mid = partition(v, l, r);

		quick_sort(v, l, mid.fr - 1);
		quick_sort(v, mid.sc + 1, r);
	}

	void solve(){
	
		int n;
		cin >> n;

		vi v(n);

		rep(i,0,n){
			cin >> v[i];
		}
		vi a = v;

		sort(all(a));
		cout << (a==v);

		quick_sort(v, 0, n-1);
		// cout << ans.fr << ' ' << ans.sc;
		cout << endl << (a==v);
		// for(int i =0; i < n; i++){
		// 	cout << (a[i]==v[i] )<<' ';
		// }
		// auv(v);
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
