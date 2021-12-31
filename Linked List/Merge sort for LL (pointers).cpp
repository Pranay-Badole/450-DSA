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

		Node(int data){
			this->data = data;
			next = NULL;
		}
		Node(){
			next = NULL;
		}
	};

	class linkedlist{

	public:
	
		Node *head;
		linkedlist(){
			head = NULL;
		}

		void push(int a){
			Node * temp = new Node(a);
			temp -> next = head;
			head = temp;
		}

		void print_list(Node *temp){

			// cout << head -> data;
			while(temp){
				cout << temp -> data << ' ';
				temp = temp -> next;
			}
			cout << endl;
		}

		void merge_sort(Node **headref){
			Node *head = *headref;
			Node *a;
			Node *b;

			if(head -> next == NULL || head == NULL){
				return;
			}

			split_list(head, &a, &b);
			
			// print_list(a);
			// print_list(b);
			
			merge_sort(&a);
			merge_sort(&b);

			*headref = merge_list(a, b);

		}

		Node *merge_list(Node* a, Node *b) {
			Node *start = NULL;
			Node *curr;

			while(a && b){
				if(a -> data < b -> data){
					if(!start){
						start = a;
					}
					else{
						curr -> next = a;
					}
					curr = a;
					a = a -> next;
				}
				else{
					if(!start){
						start = b;
					}
					else{
						curr -> next = b;
					}
					curr = b;
					b = b -> next;
				}
			}
			if(a){
				curr -> next = a;
			}
			if(b){
				curr -> next = b;
			}

			return start;
		}

		void split_list(Node *head, Node** a, Node** b) {

			Node *slow = head;
			Node *fast = head -> next;

			while(fast) {
				fast = fast -> next;
				if(fast){
					slow = slow -> next;
					fast = fast -> next;
				}
			}

			*a = head;
			*b = slow -> next;
			slow -> next = NULL;
		}
	};

	void solve(){

		linkedlist ll;

		ll.push(6);
		ll.push(8);
		ll.push(5);
		ll.push(3);
		ll.push(2);
		ll.push(1);
		ll.push(7);
		ll.push(4);

		ll.print_list(ll.head);
		ll.merge_sort(&ll.head);
		ll.print_list(ll.head);
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
