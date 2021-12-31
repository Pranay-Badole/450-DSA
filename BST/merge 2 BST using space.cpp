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
	#define auv(v)		      for(auto &x:v) cout<<x->data<<' '; cout << endl;
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

		int data;
		Node* left;
		Node* right;
		
		Node(int data):data(data), left(NULL), right(NULL){};

	};

	class BST{
	public:
		Node *head;

		BST():head(NULL){}
	};
	
	void to_list(Node* root, vector<Node*> &v){
		if(!root) return;

		to_list(root -> left, v);
		v.pb(root);
		to_list(root -> right, v);
	}
	
	Node* construct(int l, int r, vector<Node*> v){
		
		if(l > r) return NULL;

		int mid = l + (r - l)/2;
		
		Node *root = v[mid];
		root -> left = construct(l, mid - 1, v);
		root -> right = construct(mid + 1, r, v);
		
		return root;
	}

	Node* merge(Node* a, Node* b, int na, int nb){
		vector<Node*> v1;
		vector<Node*> v2;

		to_list(a, v1);
		to_list(b, v2);
		
		vector<Node*> v;

		int i = 0, j = 0;
		while(i < na && j < nb){
			if(v1[i] -> data < v2[j] -> data){
				v.pb(v1[i++]);
			}
			else{
				v.pb(v2[j++]);
			}
		}
		while(i < na) v.pb(v1[i++]);
		while(j < nb) v.pb(v2[j++]);

		auv(v);

		Node *head = construct(0, sz(v)-1, v);

		return head;
	}
	
	void inorder(Node* root){
		if(!root) return;

		inorder(root -> left);
		cout << root -> data << ' ';
		inorder(root -> right);
	}
	
	void solve(){	
		BST fr;
		BST sc;

		fr.head = new Node(100);
		fr.head -> left = new Node(50);
		fr.head -> right = new Node(300);
		fr.head -> left -> left = new Node(20);
		fr.head -> left -> right = new Node(70);

		sc.head = new Node(80);
		sc.head -> left = new Node(40);
		sc.head -> right = new Node(120);

		Node *head = merge(fr.head, sc.head, 5, 3);
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
			// cout << endl;
		} 
		return 0;
	}
