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

	class Node {
	public:
		int data;
		Node* next;
		Node* prev;

		Node(int data){
			this->data = data;
			next = NULL;
			prev = NULL;
		}
		Node(){
			next = NULL;
			prev = NULL;
		}
	};

	class linkedlist{

	public:
	
		Node *head;
		Node *last;
		linkedlist(){
			head = NULL;
			last = NULL;
		}

		void push(int a){

			Node * temp = new Node(a);
			if(!head){head = last = temp;return;}
			temp -> next = head;
			head -> prev = temp;
			head = temp;
		}

		void print_list(Node *temp){

			while(temp){
				cout << temp -> data << " ";
				temp = temp -> next;
			}
			cout << endl;
		}
		void print_list_r(Node *temp){

			while(temp){
				cout << temp -> data << " ";
				temp = temp -> prev;
			}
			cout << endl;
		}
		
	};

	void solve(){

		linkedlist ll;

		ll.push(8);
		ll.push(7);
		ll.push(6);
		ll.push(5);
		ll.push(4);
		ll.push(3);
		ll.push(2);
		ll.push(1);

		int k;
		cin >> k;

		Node *temp = ll.head;
		Node *prev = NULL;

		while(temp){
			Node *start = temp;

			for(int i = 1; i < k; i++) {
				if(temp -> next == NULL){
					break;
				}
				temp = temp -> next;
			}
			Node *end = temp;

			Node *temp2 = temp;
			temp = temp -> next;

			int flag = 1;

			while(flag){
				if(temp2 == start){flag = 0;}
				Node *pre = temp2 -> prev;
				temp2 -> prev = temp2 -> next;
				temp2 -> next = pre;
				temp2 = pre;
			}
			start -> next = temp;
			if(temp)temp -> prev = start;
			
			if(!prev){ll.head = end;end -> prev = NULL;}
			else{prev -> next = end;end -> prev = prev;}
			prev = start;
		}

		temp = ll.head;
		while(temp -> next){
			temp = temp -> next;
		}
		ll.last = temp;

		ll.print_list(ll.head);
		ll.print_list_r(ll.last);

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
		cin >> t;

		while(t--) {
			solve();
			cout << endl;
		} 
		return 0;
	}
