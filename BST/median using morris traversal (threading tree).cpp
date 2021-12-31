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
	
	void to_list(Node* root, vector<Node*> &v) {
		if(!root) return;

		to_list(root -> left, v);
		v.pb(root);
		to_list(root -> right, v);
	}
	
	int find_size(Node* head) {
		if(!head) return 0;
		
		int ans = 0;

		ans += find_size(head -> left);
		ans += find_size(head -> right);
		
		return ans + 1;
	}
	void inorder(Node *root) {
		if(!root) return;

		inorder(root -> left);
		cout << root -> data << ' ';
		inorder(root -> right);
	}

	int morris(Node *root) {
		
		int cnt = 0;
		Node *cur = root;

		while(cur){
			if(!cur -> left){
				cnt++;
				cout << cur -> data << ' ';
				cur = cur -> right;
			}
			else{
				Node *temp = cur -> left;
				while(temp -> right != NULL && temp -> right != cur){
					temp = temp -> right;
				}
				if(temp -> right == NULL){
					temp -> right = cur;
					cur = cur -> left;
				}
				else if(temp -> right == cur){
					cnt++;
					cout << cur -> data << ' ';
					temp -> right = NULL;
					cur = cur -> right;
				}
			}
		}
		return cnt;
	}

	int median(Node *root, int n){
		int a, b;
		int f = n/2;
		int cnt = 0;

		while(root){
			if(!root -> left){
				cnt++;
				if(cnt == f){a = root -> data;}
				if(cnt == f+1){b = root -> data; break;}
				root = root -> right;
			}
			else{
				Node *prev = root -> left;

				while(prev -> right != NULL && prev -> right != root){
					prev = prev -> right;
				}
				if(prev -> right){
					cnt++;
					if(cnt == f){a = root -> data;}
					if(cnt == f+1){b = root -> data; break;}

					prev -> right = NULL;
					root = root -> right;
				}
				else{
					prev -> right = root;
					root = root -> left;
				}
			}
		}
		if(n % 2) return b;
		else return (a+b)/2;
	}

	void solve(){	

		BST tr;
		tr.head = new Node(6);	
		tr.head -> left = new Node(3);
		tr.head -> right = new Node(8);
		tr.head -> left -> left = new Node(1);
		tr.head -> left -> right = new Node(4);
		tr.head -> right -> left = new Node(7);
		// tr.head -> right -> right = new Node(9);
		// tr.head -> right -> right -> right = new Node(10);
		// tr.head -> left -> right -> right = new Node(14);
		
		int n = morris(tr.head);
		cout << endl;
		int ans = median(tr.head, n);
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
			// cout << endl;
		} 
		return 0;
	}
