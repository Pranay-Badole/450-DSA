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

	Node * form(int i, string &s, vi &v) {
		if(i >= (int)s.size() || s[i] == '(' || s[i] == ')'){
			return NULL;
		}
		int num = 0, neg = 0;

		if(s[i] == '-'){
            i++; neg = 1;
        }
        while(i < sz(s) && s[i] != '(' && s[i] != ')'){
        	int data = (int)(s[i] - '0');
        	num = num*10 + data;
        	i++;
        }
        if(neg) num *= -1;
	
		Node *root = new Node(num);

		if(i < sz(s) && s[i] == '('){
			root -> left = form(i+1, s, v);
			
			if(v[i] + 1 < (int)s.size() && s[v[i]+1] == '(')
				root -> right = form(v[i]+2, s, v);
		}

		return root;
	}

	void solve(){
		string s;
		cin >> s;	
		
		int n = sz(s);
		vi v(n);

		stack<int> st;
		for(int i = 0; i < n; i++) {
			v[i] = i;
			if(s[i] == '('){
				st.push(i);
			}
			else if(s[i] == ')'){
				int l = st.top();
				st.pop();
				v[l] = i;
				v[i] = l;
			}
		}
		// auv(v);
		tree tr;
		tr.head = form(0, s, v);
		tr.level_order(tr.head);
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
