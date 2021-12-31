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
/*
		#####   #     #  # # #
		  #		 #	#    #   #
		  #		#  #  #  # # #
		##### 	#     #  #
*/
		Passed_GFG_testcases ()

		void quick_sort(Node **headref){
			
			Node *head = *headref;
			
			if(head == NULL || head -> next == NULL){
				return;
			}

			int pivot = head -> data;
			head = head -> next;

			Node *lt = NULL;
			Node *gt = NULL;
			Node *temp1 = new Node(), *temp2 = new Node();

			while(head){
				if(head -> data < pivot){
					if(!lt){lt = head;}
					else{
						temp1 -> next = head;
					}
					temp1 = head;
					head = head -> next;
				}
				else{
					if(!gt){gt = head;}
					else{
						temp2 -> next = head;
					}
					temp2 = head;
					head = head -> next;
				}
			}

			temp1 -> next = NULL;
			temp2 -> next = NULL;
			

			quick_sort(&lt);
			quick_sort(&gt);

# # # IMP # # # 
take care of cases where lt = NULL or gt = NULL;

			Node *start;

			temp1 = lt;

			if(temp1){
				start = temp1;
				while(temp1 -> next){
					temp1 = temp1 -> next;
				}
			}

			if(temp1){
				temp1 -> next = *headref;
				temp1 = temp1 -> next;
				temp1 -> next = gt;
			}
			else{
				temp1 = *headref;
				start = temp1;
				temp1 -> next = gt;
			}


			*headref = start;
		}
	};

	void solve(){

		linkedlist ll;

		ll.push(5);
		ll.push(2);
		ll.push(4);
		ll.push(7);
		ll.push(6);
		ll.push(3);
		ll.push(1);
		ll.push(8);

		ll.print_list(ll.head);
		ll.quick_sort(&ll.head);
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
