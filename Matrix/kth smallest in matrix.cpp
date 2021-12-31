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

	int kthSmallest(int v[][100], int n, int k)
	{
	int l = v[0][0];
	int r = v[n-1][n-1];

    int ans = 0;
    
    while(l <= r){
        int mid = l + (r-l)/2;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
             cnt += upper_bound(v[i], v[i]+n, mid) - v[i] ; 
        } 
        // cout << l << ' ' <<  r << ' ' << mid <<' '<< cnt << endl; 
        
        if(cnt < k){
            l = mid + 1;
        }    
        else{
            r = mid -1;
            ans = mid;
        }
    }    
    return ans;
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
