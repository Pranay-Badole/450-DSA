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
	

	void solve(){
		
		int q = 101;
		int d = 256;
		int h = 1;
		int t = 0;
		int p = 0;

		string txt, pat;
		
		getline(cin, txt);
		getline(cin, pat);
		
		int n = sz(txt);
		int m = sz(pat);

		for(int i = 1; i < m; i++){
			h = (h * d) % q;
		}

		for(int i = 0; i < m; i++){

			p = ((p * d) + pat[i]) % q;
			t = ((t * d) + txt[i]) % q;
			// cout << h << " " << p << ' ' << t << endl;
		}

		for(int i = 0; i <= n-m; i++){
			
			if(p == t){
				int j = 0;
				while(j < m){
					if(txt[i+j] != pat[j]){
						break;
					}
					j++;
				}

				if(j == m){
					cout << i <<' ';
				}
			}
			if(i < n-m){
			t = ((t - txt[i]*h)*d + txt[i+m]) % q;

			if(t < 0){
				t+=q;
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
		// cin >> t;
		while(t--) solve(), cout << endl;
		return 0;
	}
