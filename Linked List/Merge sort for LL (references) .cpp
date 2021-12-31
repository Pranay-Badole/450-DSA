
        #include "bits/stdc++.h"
        using namespace std;    

        #define ll                            long long
        #define int                           FO
        #define pb                            push_back
        #define ppb                           pop_back
        #define pf                            push_front
        #define ppf                           pop_front
        #define all(x)                        (x).begin(),(x).end()
        #define uniq(v)                       (v).erase(unique(all(v)),(v).end())
        #define sz(x)                         (ll)((x).size())
        #define fr                            first
        #define sc                            second
        #define pii                           pair<ll,ll>
        #define mkp                           make_pair
        #define rep(i,a,b)                    for(ll i=a;i<b;i++)
        #define rrep(i,a,b)                   for(ll i=a;i>=b;i--)
        #define REP(i,a,b)                    for(ll i=a;i<=b;i++)
        #define mem1(a)                       memset(a,-1,sizeof(a))
        #define mem0(a)                       memset(a,0,sizeof(a))
        #define ppc                           __builtin_popcount
        #define ppcll                         __builtin_popcountll
        #define acc                              accumulate
        #define endl                          '\n'
        #define length(a)                     sizeof(a)/sizeof(a[0])
        #define auv(v)                        for(auto &x:v) cout<<x<<' '; cout<<endl;
        #define auvv(v)                       for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
        #define aump(mp)                      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl;  
        #define vi                            vector<ll>
        #define vvi                           vector<vector<ll>>
        #define vc                            vector<char>
        #define vvc                           vector<vector<char>>
        #define two(x)                        cout << x.fr << ' ' << x.sc << ' ';
        #define EPS 1e-9

        struct custom_hash {
            static uint64_t splitmix64(uint64_t x) {
                // http://xorshift.di.unimi.it/splitmix64.c
                x += 0x9e3779b97f4a7c15;
                x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
                x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
                return x ^ (x >> 31);
            }
            size_t operator()(uint64_t x) const {
                static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
                return splitmix64(x + FIXED_RANDOM);
            }
        };

        #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            std::cerr << name << " : " << arg1 << endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }


        const ll M = 1e9 + 7;
        const ll MM = 998244353;
        const ll N = 1000005;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class Node {
    public:
        ll data;
        Node* next;

        Node(ll data){
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

        void push(ll a){
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

        ll len(Node * temp) {
            if(!temp) return 0;

            ll cnt = 1;
            while(temp -> next) {temp = temp -> next; cnt++;}
            return cnt;
        }



        void split_list(Node* head, Node* &fr, Node* &sc) {
            
            ll n = len(head);
            trace(n);
            n = n / 2;
            fr = head;

            while(--n) {
                head = head -> next;
            }

            sc = head -> next;
            head -> next = NULL;

        }

        void merge(Node* &head, Node *fr, Node *sc){
            Node * t1 = fr, *t2 = sc;

            Node * temp;
            Node *prev = temp;

            while(t1 && t2){
                if(t1 -> data < t2 -> data) {
                    prev -> next = t1;
                    prev = t1;
                    t1 = t1 -> next;
                }
                else{
                    prev -> next = t2;
                    prev = t2;
                    t2 = t2 -> next;
                }
            }
            if(t1) {
                prev -> next = t1;
            }
            if(t2){
                prev -> next = t2;
            }

            head = temp -> next;
            // prev -> next = NULL;

        }

        void merge_sort(Node* &head) {

            if(!head || head -> next == NULL){
                return;
            }

            Node *fr, *sc;

            split_list(head, fr, sc);

            merge_sort(fr);
            merge_sort(sc);

            merge(head, fr, sc);
        }
    
    };

    void solve(){

        linkedlist lll;

        lll.push(6);
        lll.push(8);
        lll.push(5);
        lll.push(3);
        lll.push(2);
        lll.push(1);
        lll.push(7);
        lll.push(4);

        lll.print_list(lll.head);
        lll.merge_sort(lll.head);cout << endl;
        lll.print_list(lll.head);
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
            
            cerr << setprecision(15) << fixed;
            cout << setprecision(15) << fixed;
            
            ll t = 1;
            // cin >> t;

            while(t--) {
                solve();
                cout << endl;
            } 
            return 0;
        }   