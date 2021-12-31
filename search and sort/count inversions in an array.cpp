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

	int merge(vi & v, int l, int r, int mid){
		vi temp(r - l + 1);
		
		int i = l, j = mid + 1, k = 0;

		int cnt = 0;

		while(i <= mid && j <= r){
			if(v[i] <= v[j]){
				temp[k++] = v[i++];
			}
			else{
				temp[k++] = v[j++];	
				cnt += mid - i + 1;
			}
		}
		while(i <= mid){
			temp[k++] = v[i++];
		}
		while(j <= r){
			temp[k++] = v[j++];
		}

		for(int i = 0; i < sz(temp); i++){
			v[i+l] = temp[i];
		}
		return cnt;
	}

	int merge_sort(vi &v, int l, int r) {
		int ans = 0;
		
		if(l >= r){
			return ans;
		}

		int mid = l + (r - l)/2; 
		
		ans += merge_sort(v, l, mid);
		ans += merge_sort(v, mid + 1, r);

		ans += merge(v, l, r, mid);
		return ans;
	}

	void solve(){
	
		int n;
		cin >> n;

		vi v(n);

		rep(i,0,n){
			cin >> v[i];
		}

		cout << merge_sort(v, 0, n-1);
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
