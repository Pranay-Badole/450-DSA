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
	class Node{
	public:
		int data;
		Node *left;
		Node *right;	

		Node(int a):data(a), left(NULL), right(NULL){}
	};

	class tree{
	public:
		Node *head;

		tree():head(NULL){}
	};

	void helper(Node *root, int sum, vi v, vvi&ans){
		if(!root) return;
		
		sum = sum - (root -> data);
		v.pb(root -> data);
		
		if(sum == 0) ans.pb(v);

		helper(root -> left, sum, v, ans);
		helper(root -> right, sum, v, ans);

	}

	void find(Node *root, int sum, vvi &ans){
		vi v;
		helper(root, sum, v, ans);
	}

    void order(Node *root, int k, vvi &ans){
        if(!root) return ;

        order(root -> left, k, ans);
        find(root, k, ans);
        order(root -> right, k, ans);
        
    }

	void solve(){
		tree tr;

		tr.head = new Node(1);
		tr.head -> left = new Node(3);
		tr.head -> right = new Node(-1);
 		tr.head -> left -> left= new Node(2);
		tr.head -> left -> right= new Node(1);	
		tr.head -> right -> left = new Node(4);	
		tr.head -> right -> right= new Node(5);
		tr.head -> right -> right -> right = new Node(6);
		tr.head -> left -> right -> left = new Node(1);
		tr.head -> right -> left -> left = new Node(1);
		tr.head -> right -> left -> right = new Node(2);

		int k = 4;

		vvi ans;
		order(tr.head, k, ans);
 		cout << "size " << sz(ans) << endl;

 		auvv(ans);

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
