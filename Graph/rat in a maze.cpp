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
	#define rrep(i,a,b)        for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto &x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;

const int M=100000000;

int flag[6][6];

void solvee(int i, int j, int m,  int n, string s, vector<string>&ans, vector<vector<int>> &v){
    
    if(i == m && j == n){cout<<s<<endl;  return ;}
    
    flag[i][j] = 1;
    
    if(i > 0){
        if(!flag[i-1][j] && v[i-1][j]){ s.pb('U'); solvee(i-1, j, m, n, s, ans, v); s.pop_back(); } }
	if(i < m){
         if(!flag[i+1][j] && v[i+1][j]){ s.pb('D'); solvee(i+1, j, m, n, s, ans, v);s.pop_back(); } }
    if(j > 0){
        if(!flag[i][j-1] && v[i][j-1]){  s.pb('L'); solvee(i, j-1, m, n, s, ans, v);s.pop_back(); } }
    if(j < n){
        if(!flag[i][j+1] && v[i][j+1]){ s.pb('R'); solvee(i, j+1, m, n, s, ans, v);s.pop_back(); } }
 
    flag[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
        
        memset(flag,0,sizeof flag);
        
        vector<string>ans;
         solvee(0, 0, n-1, n-1, "", ans, m);
        return ans;
}

void solve(){

	int n;
	cin>>n;
	vector<vector<int>> m(n,vector<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> m[i][j];
		}
	} 
	findPath(m,n);
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
 
		int t=1;
		// cin>>t;
		while(t--) solve(),cout<<endl;
		return 0;
	}