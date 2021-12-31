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
	
	 string findSubString(string s)
        {
           int n = s.size();
           unordered_map<char, int> mp;
           unordered_set<char> st;
           
           int tot = 0;
           for(auto x : s){
               if(!st.count(x)){
                    tot++;
                    st.insert(x);
               }
           }
           
           
           int max_len  = INT_MAX;
           int start = -1;
           
           int i = 0;
           int cnt = 0;
           
           for(int j = 0; j < n; j++){
               mp[s[j]]++;
               
               if(mp[s[j]] == 1){
                   cnt++;
               }
               
               if(cnt == tot){
                   while(mp[s[i]] > 1){
                       mp[s[i]]--;
                       i++;
                   }
                   
                   if(max_len > j - i + 1){
                       max_len = j - i + 1;
                       start = i;
                   }
               }
           }
           
           return s.substr(start, max_len);
        }

	void solve(){
	 	

		string s;
		cin >> s;

		string ans = findSubString(s);
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
		while(t--) solve(), cout << endl;
		return 0;
	}
