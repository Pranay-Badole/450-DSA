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

		void level_order(Node *root){
			if(!root){return;}
			queue <Node *> q; 
			
			q.push(root);
			while(sz(q))
			{
				Node *top = q.front();
				q.pop();

				cout << top -> data << " ";
				if(top -> left) q.push(top -> left);
				if(top -> right) q.push(top -> right);
			}
			cout << endl;
		}

		void postorder(Node *root){

			if(!root){return ;}

			postorder(root -> left);
			postorder(root -> right);
			cout << root -> data << " ";
		}
		
	};

	void solve(){
		tree tr;

		tr.head = new Node(1);
		tr.head -> left = new Node(2);
		tr.head -> right = new Node(3);
		tr.head -> left -> left= new Node(4);
		// tr.head -> left -> right= new Node(4);	
		tr.head -> right -> left = new Node(5);	
		tr.head -> right -> right= new Node(6);
		tr.head -> right -> left -> left = new Node(7);	
		tr.head -> right -> left -> right = new Node(8);	
		
		tr.postorder(tr.head);
		cout << endl;

	// // ##################################
	// // POSTORDER ITERATIVE WAY 1 | TWO STACKS 
		
		Node *curr = tr.head;
		stack<Node *> st;
		stack<int> ans;

		st.push(curr);

		while(sz(st)){
			Node *top = st.top();
			st.pop();
			ans.push(top -> data);

			if(top -> left)
				st.push(top -> left);
			if(top -> right)
				st.push(top -> right);
		}

		while(sz(ans)){
			cout << ans.top() << " ";
			ans.pop();
		}

	// ##################################
	// POSTORDER ITERATIVE WAY 2

		cout << endl;
		Node *root = tr.head;

		do{

			while(root){
				if(root -> right)
					st.push(root -> right);

				st.push(root);

				root = root -> left;
			}

			root = st.top(); 
			st.pop();

			if(sz(st) && root -> right && root -> right == st.top()){
				st.pop();
				st.push(root);
				root = root -> right;
			}
			else{
				cout << root -> data << " ";
				root = NULL;
			}

		}
		while(sz(st));
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
