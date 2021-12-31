
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
        const ll N = 15;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class Node{
    public:
        ll data;
        Node* left;
        Node* right;
        
        Node():left(NULL), right(NULL){}
        Node(ll a):left(NULL), right(NULL), data(a){}
    };

    class Tree{
    public:
        Node *head;
        Tree():head(NULL){}
        
        void level_order(Node *root){
            cout << endl;
            if(!root){return;}
            queue <Node *> q; 
            
            q.push(root);
            while(sz(q))
            {   
                ll n = sz(q); 
                while(n--){
                Node *top = q.front();
                q.pop();

                cout << top -> data << " ";
                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);
                }
            cout << endl;
            }
        }

        void postorder(Node *root){

            if(!root){return ;}

            postorder(root -> left);
            postorder(root -> right);
            cout << root -> data << " ";
        }

    };

    Node* fun(ll &i, ll l, ll r, vi &pre, unordered_map<ll, ll> mp) {

        if(l > r){
            return NULL;
        }


        Node *temp = new Node(pre[i]);
        ll pos = mp[pre[i]];
        i++;

        temp -> left = fun(i, l, pos - 1, pre, mp);
        temp -> right = fun(i, pos + 1, r, pre, mp);

        return temp;

    }

    void solve(){

        ll n; cin >> n;
        
        vi in(n); 
        vi pre(n);
        unordered_map<ll, ll> mp;

        rep(i, 0, n){
            cin >> in[i];
            mp[in[i]] = i;
        }
        rep(i, 0, n) cin >> pre[i];
        
        auv(in);auv(pre);

        ll i = 0;
        Tree tr;
        tr.head = fun(i, 0, n-1, pre, mp);
        tr.postorder(tr.head);

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