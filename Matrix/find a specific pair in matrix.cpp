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
	#define mkp 				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)        for(int i=a;i>=b;i--)
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
 
const int N=1e5+5;
const int M=1e9 + 7;


int fun(int i, int j, vvi v, vvi &maxi){
	if(i >= v.size() || j >= v.size()){
		return INT_MIN;
	}
	if(maxi[i][j] != INT_MIN){
		return maxi[i][j];
	}
	// if(i == v.size()-1 && j == v[0].size()-1){
	// 	maxi[i][j] = v[i][j];
	// }

	int fr = fun(i+1, j, v, maxi);
	int sc = fun(i, j+1, v, maxi);
	int temp = max(fr, sc);
	temp = max(temp, v[i][j]);

	return maxi[i][j] = temp;
}

	void solve(){
		
		int n;
	   	cin >> n;

	   	vvi v(n,vi(n));

	   	rep(i,0,n){
	   		rep(j,0,n){
	   			cin >> v[i][j];
	   		}
	   	}
	   	vvi maxi(n,vi(n,INT_MIN)); 
		
		fun(0, 0, v, maxi);
		auvv(maxi);
		
		int ans = INT_MIN;

		rep(i,0,n){
	   		rep(j,0,n){
	   			if(i != v.size()-1 &&  j != v.size()-1){
	   				ans = max(maxi[i+1][j+1] - v[i][j], ans);
	   			}
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
		// cin >> t;
		while(t--) solve(), cout << endl;
		return 0;
	}
