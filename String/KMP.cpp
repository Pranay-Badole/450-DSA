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

		string txt, pat;
		cin >> txt >> pat;
		
		int n = sz(txt);
		int m = sz(pat);
		
		vi lps(m);

		lps[0] = 0;
		int len = 0;
		int i = 1;

		while(i < m){
			if(pat[i] == pat[len]){
				len++;
				lps[i++] = len;
 			}
			else{
				if(len != 0){
					len = lps[len - 1];
				}
				else{
					lps[i] = 0;
					i++;
				}
			}
		}
		auv(lps);

		int j = 0;
		i = 0; 

		while(i < n){
			if(txt[i] == pat[j]){
				i++; j++;
			}
			if(j == m){
				cout << i - j << ' ';
				j = lps[j-1];
			}
			else if(i < n && txt[i] != pat[j]){
				if(j != 0){
					j = lps[j-1];
				}	
				else{
					i++;
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
