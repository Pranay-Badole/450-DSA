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

int visited[1005][1005];

class cell{
	public:
	int x,y;
	int dist;
	cell(int X, int Y, int d){
		this->x = X;
		this->y = Y;
		this->dist = d;
	}
};

bool check(int x, int y, int N){
	if(x>=1 && x<=N && y>=1 && y<=N){
		return true;
	}
	return false;
}


int helper(vector<int>&KnightPos,vector<int>&TargetPos, int N){
	int i = KnightPos[0];
	int j = KnightPos[1];

	int m = TargetPos[0];
	int n = TargetPos[1];

	int dx[] = {1, -1,  1, -1,  2, -2, -2,  2};
	int dy[] = {2, -2, -2,  2,  1, -1,  1, -1};
	queue < cell > q;

	q.push(cell(i,j,0));
	visited[i][j] = 1;

	while(!q.empty()){
		cell t = q.front();
		q.pop();
		// cout<< t.x << " " << t.y << " "<< t.dist<<endl;

		if(t.x == m && t.y == n){
			return t.dist;
		}
		
		rep(i,0,8){
			int x1 = t.x + dx[i];
			int y1 = t.y + dy[i];

			if(check(x1,y1,N) && visited[x1][y1]==0)
			{	
				visited[x1][y1] = 1;
				int z = t.dist;
				q.push(cell(x1,y1,z+1));
			}
		}
	}
	return 0;
}

void solve(){

	int n;
	cin>>n;
	memset(visited, 0 , sizeof visited);

	vector< int > knightPos(2);
	vector< int > targetPos(2);

	for(int i = 0; i<2; i++){
		cin >> knightPos[i];
	} 
	for(int i = 0; i<2; i++){
		cin >> targetPos[i];
	} 
	int ans = helper(knightPos, targetPos, n);

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
 
		int t=1;
		// cin>>t;
		while(t--) solve(),cout<<endl;
		return 0;
	}