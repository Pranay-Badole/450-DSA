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
	
	int find_size(Node* head){
		if(!head) return 0;
		
		int ans = 0;

		ans += find_size(head -> left);
		ans += find_size(head -> right);
		
		return ans + 1;
	}

	void median(Node *head, int &a, pii &ans){
		if(!head) return;

		median(head -> left, a, ans);
		// cout << head -> data << ' ';
		if(a == 1 && ans.sc == -1){
			ans.sc = head -> data;
			a--;
		}
		if(a == 2 && ans.fr == -1){
			ans.fr = head -> data;
		}
		a--;

		median(head -> right, a, ans);
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
		// tr.head -> left -> right -> left = new Node(10);
		// tr.head -> left -> right -> right = new Node(14);

		int n = find_size(tr.head);
		pii ans = {-1, -1};
		int a = (n/2) + 1;

		// cout << n << ' ' << a << endl;

		median(tr.head, a, ans);
		
		if(n % 2){ cout << ans.sc;}
		else{
			cout << (ans.fr + ans.sc) / 2;
		}
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
