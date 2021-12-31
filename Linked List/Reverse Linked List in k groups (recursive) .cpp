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

		void print_list(){

			// cout << head -> data;
			
			Node* temp = head;

			while(temp){
				cout << temp -> data << ' ';
				temp = temp -> next;
			}
			cout << endl;
		}

		void reverse(){
			Node *temp = head;
			Node *left = NULL;
			Node *right = NULL;

			while(temp){
				right = temp -> next;
				temp -> next = left;
				left = temp;
				temp = right;		
			}
			head = left;
		}

		Node* k_reverse(Node *temp, int k){
			if(!temp){
				return temp;
			}
			int i = 0;

			Node *left = NULL;
			Node *start = temp;

			while(i < k && temp) {
				Node* right = temp -> next;
				temp -> next = left;
				left = temp;
				temp = right;
				i++;
			}

### comment out below lines if you want to print last group(< k) wihout reversing
			/*if(i != k){
			temp = left;
			left = NULL;

				while(temp){
				Node* right = temp -> next;
				temp -> next = left;
				left = temp;
				temp = right;
				}

			}
			else*/
			start -> next = k_reverse(temp, k);
			
			return left;
		}

	};

	void solve(){

		linkedlist ll;
		ll.push(8);ll.push(7);
		ll.push(6);
		ll.push(5);
		ll.push(4);ll.push(3);
		ll.push(2);ll.push(1);

		ll.print_list();

		ll.head = ll.k_reverse(ll.head, 5);	
		ll.print_list();	
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
