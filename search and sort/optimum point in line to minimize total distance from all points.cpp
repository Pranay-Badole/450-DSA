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
	#define aump(mp)	      for(auto x:mp) cout<<x.x<<' '<<x.y<<endl; 
	#define vi 				  vector<int>
	#define vvi 			  vector<vector<int>>
	#define vc 				  vector<char>
	#define vvc 			  vector<vector<char>>
	#define print(a,b,c)	  cout << a <<' ' << b << ' ' << c << endl;
	#define EPS 1e-6

	const int N=1e5+5;
	const int M=1e18 + 7;

	class point{
		public:
		int x, y;
		point(){}
		point(int a, int b){
			x = a;
			y = b;
		}
	};

	class line{
	public:
		int a, b, c;
		line(int x, int y, int z){
			a = x;
			b = y;
			c = z; 
		}
	};

	double dist(point p, double a, double b) {
		double ans = sqrt((p.x - a)*(p.x - a) + (p.y - b)*(p.y - b));
		
		return ans;
	}

	double compute(point p[], double a, double b, int n){
		double tot = 0;

		for(int i = 0; i < n; i++) {
			tot += dist(p[i], a, b);
		} 
		return tot;
	}

	double fun(point p[], line li, int n){
			double l = -1e6, r = 1e6;
			double ans;

		while(r - l > EPS){
			double mid1 = l + (r-l)/3;
			double mid2 = r - (r-l)/3;
			// cout << l << ' ' << r << " ";

			double mid1_y = -(li.c + (li.a * mid1))/li.b; 
			double mid2_y = -(li.c + (li.a * mid2))/li.b; 
	
	
			double fr = compute(p, mid1, mid1_y, n);
			double sc = compute(p, mid2, mid2_y, n);
			// cout << fr << ' ' << sc << endl;
			// cout << mid1 << " " << fr << " ";
			// cout << mid2 << " " << sc << endl;

			if(fr < sc){
				r = mid2;
			}
			else{
				l = mid1;
			}
			}
			double x = (l+r)/2;
			double y = -(li.c + (li.a * x))/li.b;

		ans = compute(p, x, y, n);
		return ans;
	}	

	double find_optimum(vvi &v, line l){
		int n = sz(v);
		point p[n];

		for(int i = 0; i < n; i++) {
			p[i] = point(v[i][0], v[i][1]);
		}
		

		double ans = fun(p, l, n);
		return ans;
	}

	void solve(){

		vector<vector<int>> v = {{ -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }};
		line l(1, -1, -3);
		
		double ans = find_optimum(v, l);
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
		while(t--) {
			solve();
			cout << endl;
		} 
		return 0;
	}
