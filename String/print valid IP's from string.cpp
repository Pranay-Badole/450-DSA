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
	const int M=1e18 + 7;
	
	vector<string> v;

	void  fun(int i, string &s, int k, string t) {
		if( i >= sz(s)){
			return;
		}
			
		if(k == 0){
			if(s[i] == '0'){
                return;
            }
			int q = stoll(s.substr(i));

			if( q <= 255){
				v.pb((t + s.substr(i)));
			}
			return;
		}

		string z = t;
		
		if(s[i] == '0'){
			fun(i+1, s, k - 1, t + '0' + '.');
		}
		else{
			z += s[i];
			fun(i+1, s, k - 1, z + '.');
			
			if(i + 1 < sz(s)){
				z+=s[i+1];
				fun(i+2, s, k - 1, z + '.');
			}
			if(i + 2 < sz(s)){ 
				z+=s[i+2];
				int q = stoi(s.substr(i,3));

			if(q <= 255){
				fun(i+3, s, k - 1, z + '.');
			}
			}
		}
	}

	void solve(){
	

		string s;
		cin >> s;
		v.clear();
		
		if(sz(s) > 12 || sz(s) < 4){
			cout << "No IP";
		}
		else
		 {
		  	fun(0, s, 3, "");
			auv(v);
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
		while(t--) solve(), cout << endl;
		return 0;
	}
