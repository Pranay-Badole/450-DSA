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

	#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
	    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
		
	class Node{
	public:
		Node *left;
		Node *right;
		int l, h, mx;
		
		Node(int l, int h):l(l), h(h), left(NULL), right(NULL){};
	};

	void inorder(Node *root){
		if(!root) return;

		inorder(root -> left);
		cout << root -> l << ' ' << root -> h << ' ' << root -> mx << endl;
		inorder(root -> right);
	}

	Node *insert(Node *root, int a, int b){
		if(!root){
			root = new Node(a, b);
			root -> mx = b;
			return root;
		}

		if(root -> l > a){
			root -> left = insert(root -> left, a, b);
		}
		else{
			root -> right = insert(root -> right, a, b);
		}
		if(root -> mx < b){
			root -> mx = b;
		}
		
		return root;
	}

	bool overlap(Node *root, int l, int h) {
		if(h <= root -> l || l >= root -> h){
			return 0;
		}
		return 1;
	}

	Node* check_all_overlap(Node* root, int l, int h) {
		if(!root) return NULL;

		if(overlap(root, l, h)){
			return root;
		}

		if(root -> left && root -> left -> mx > l){
			return check_all_overlap(root -> left, l, h);
		}

		return check_all_overlap(root -> right, l, h);
	}

	void solve(){	

		vector<pii> v;
		int n;cin >> n;

		rep(i,0,n){
			int a, b;
			cin >> a >> b;
			v.pb({a, b});
		}

		Node *head = NULL;

		head = insert(head, v[0].fr, v[0].sc);

		rep(i,1,n){
			Node *ans = check_all_overlap(head, v[i].fr, v[i].sc);
			if(ans){
				cout << v[i].fr << ' ' << v[i].sc;
				cout << " ==> ";
				cout << ans -> l << ' ' << ans -> h << endl;
			}
			insert(head, v[i].fr, v[i].sc);
		}
		inorder(head);
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
