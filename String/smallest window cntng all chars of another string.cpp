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
	#define auv(v)		      for(auto &x:v) cout<<x; cout << endl;
	#define auvv(v)			  for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	#define vi 				  vector<int>
	#define vvi 			  vector<vector<int>>
	#define vc 				  vector<char>
	#define vvc 			  vector<vector<char>>
	#define print(a,b,c)	  cout << a <<' ' << b << ' ' << c << endl;
 
	const int N=1e5+5;
	const int M=1e18 + 7;
		
	string smallestWindow (string s, string p)
    {   
        if(p.size() > s.size()){
            return "-1";
        }

        int mp[256] = {0};
        int temp[256] = {0};
        
        for(auto x : p){
            mp[x]++;
        }
        
        int n = s.size();
        
        int i = 0;
        int start = -1;
        int mx_len = INT_MAX;
        
        int cnt = 0;
        int flag = 0;
        
        for(int j = 0; j < n; j++) {
            char q = s[j];
            temp[q]++;
            
            if(temp[q] <= mp[q]){
                cnt++;
            }
            
            if(cnt == p.size()){
                flag = 1;
                while(temp[s[i]] > mp[s[i]] || mp[s[i]] == 0){
                    temp[s[i]]--;
                    i++;
                }
    
            int length = j-i+1;
            
            if(length < mx_len){
                start = i;
                mx_len = length;
            }
            }
        }
        
        if(flag == 0){
            return "-1";
        }
        else{
            
            return s.substr(start, mx_len);
        }
    }

	void solve(){
		string s;
		string p;

		cin >> s >> p;

		string ans = smallestWindow(s, p);

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
