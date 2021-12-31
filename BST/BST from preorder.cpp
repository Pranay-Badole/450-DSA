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
		int data;
		Node *left;
		Node *right;

		Node(int data):data(data), left(NULL), right(NULL){}
	};

	class BST{
	public:
		Node *head;
		BST():head(NULL){}
		
		Node * insert(Node * root, int data) {
			if(root == NULL){
				return new Node(data);
			}

			if(data < root -> data){
				root -> left = insert(root -> left, data);
			}
			else{
				root -> right = insert(root -> right, data);
			}
			return root;
		}

		void inorder(Node *root){
			if(!root) return;
			inorder(root -> left);
			cout << root -> data << ' ';
			inorder(root -> right);
		}

		Node* search(Node * root, int data){
			if(!root){
				return root;
			}
			if(root -> data == data){
				return root;
			}

			if(data < root -> data){
				return search(root -> left, data);
			}
			else
				return search(root -> right, data);

		}
	};

	void level_order(Node *root){
		queue<Node*>q;
		q.push(root);
		while(!q.empty()){
			cout<<q.front()->data<<' ';
			if(q.front()->left)q.push(q.front()->left);
			if(q.front()->right)q.push(q.front()->right);
			q.pop();
		}
	}

	Node* fun(vi &v, int &mn, int &mx) {
		static int k = 0;
		if(k >= sz(v)){
			return NULL;
		}

		Node *root;

		if(v[k] > mn && v[k] < mx){
			root = new Node(v[k]);
			k++;
		}
		else{
			root = NULL;
		}
		if(root){
			root -> left = fun(v, mn, v[k-1]);
			root -> right = fun(v, v[k-1], mx);
		}
		return root;
	}

		void solve(){	
			int n;
			cin >> n;
			vi v(n);
			rep(i,0,n) cin >> v[i];
			int min = INT_MIN;
			int max = INT_MAX;
			
			BST tr;
			tr.head = fun(v, min, max);

			level_order(tr.head);
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
