
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

        void inorder(Node *root){

            if(!root){return ;}

            inorder(root -> left);
            cout << root -> data << " ";
            inorder(root -> right);
        }

    };

    Node* fun(ll &i, string &s){
        ll n = sz(s);
        if(i >= n){return NULL;}
            

        string val = "";

        while(i < n && isdigit(s[i])){
            val += s[i++];
        }
        
        ll v = stoi(val);

        Node *temp = new Node(v);
        
        // trace(i, v);

        if(i < n && s[i] == '('){
            i++;
            temp -> left = fun(i, s);
        }
        if(i < n && s[i] == ')'){
            i++;
            return temp;
        }
        
        // trace(2, i, v);

        if(i < n && s[i] == '('){
            i++;
            temp -> right = fun(i, s);
        }
        if(i < n && s[i] == ')'){
            i++;
        }
 
        return temp;
    }

    void solve(){
            
        string s; cin >> s;
        cout << s;
        Tree tr;

        ll i = 0;
        tr.head = fun(i, s);
        tr.level_order(tr.head);
        tr.inorder(tr.head);
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