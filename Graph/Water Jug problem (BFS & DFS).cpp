#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;    
using namespace __gnu_pbds;

    #define ll                            long long
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
    #define acc                           accumulate
    #define endl                          '\n'
    #define length(a)                     sizeof(a)/sizeof(a[0])
    #define auv(v)                        for(auto &x:v) cout<<x<<' ';cout << endl;
    #define auvv(v)                       for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
    #define aump(mp)                      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl;  
    #define vi                            vector<ll>
    #define vvi                           vector<vector<ll>>
    #define vc                            vector<char>
    #define vvc                           vector<vector<char>>
    #define two(x)                        cout << x.fr << ' ' << x.sc << ' ';
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

    typedef tree<
    ll,
    null_type,
    less<ll>,  // less_equal<ll> for multiset
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
    // find_by_order(k);    returs iterator of Kth element starting from 0;
    // order_of_key(k);     no of elemets strictly less than k;


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


#define EPS 1e-9
const ll M = 1e9 + 7;;
const ll MM = 998244353;
const ll N = 2e5 + 7;


        ██████╗░███████╗░██████╗
        ██╔══██╗██╔════╝██╔════╝
        ██║░░██║█████╗░░╚█████╗░
        ██║░░██║██╔══╝░░░╚═══██╗
        ██████╔╝██║░░░░░██████╔╝
        ╚═════╝░╚═╝░░░░░╚═════╝░

vector<vector<int>> dp;
void dfs(int i, int j, int &x, int &y, int &d) {
    if(dp[i][j] == 1) return;
    
    dp[i][j] = 1;

    cout << "(" << i << ", " << j << ")" << endl;
    if((i == d && j == 0) || (j == d && i == 0)) {
        trace(i, j);
        return;
    }

    // Fill a Jug
    if(i == 0) dfs(x, j, x, y, d);
    if(j == 0) dfs(i, y, x, y, d);
    
    // Pour Water 
    int mx = min(x - i, j);
    dfs(i+mx, j-mx, x, y, d);

    mx = min(y-j, i);
    dfs(i-mx, j+mx, x, y, d);

    // Empty a Jug
    dfs(i, 0, x, y, d);
    dfs(0, j, x, y, d);
}

void print_path(pair<int, int> cur, map<pair<int, int>, pair<int, int>> &mp) {

    if(cur != mp[cur]) print_path(mp[cur], mp);

    cout << "(" << cur.fr << ", " << cur.sc << ")" << endl;
}


void solve() {
    int x, y, d;
    cin >> x >> y >> d;
    dp.assign(x+1, vector<int>(y+1, 0));

    dfs(0, 0, x, y, d);


        ██████╗░███████╗░██████╗
        ██╔══██╗██╔════╝██╔════╝
        ██████╦╝█████╗░░╚█████╗░
        ██╔══██╗██╔══╝░░░╚═══██╗
        ██████╦╝██║░░░░░██████╔╝
        ╚═════╝░╚═╝░░░░░╚═════╝░

    vector<vector<int>> vis(x+1, vector<int>(y+1, 0));
    queue<pair<int, int>> q;
    map<pair<int, int>, pair<int, int>> mp;
    
    q.push({0, 0});
    vis[0][0] = 1;
    mp[{0, 0}] = {0, 0};

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int i = cur.fr;
        int j = cur.sc;

        // cout << "(" << i << ", " << j << ")" << endl;
        if(((i == d) && (j == 0)) || ((j == d) && (i == 0))) {
            print_path({i, j}, mp);
            return;
        }

        // Fill a Jug
        if(!vis[x][j]){mp[{x, j}] = {i, j}; vis[x][j] = 1; q.push({x, j});}
        if(!vis[i][y]){mp[{i, y}] = {i, j}; vis[i][y] = 1; q.push({i, y});}
        
        // Pour Water
        int mx = min(x - i, j);
        if(!vis[i+mx][j-mx]){
            mp[{i+mx, j-mx}] = {i, j};  
            vis[i+mx][j-mx] = 1;
            q.push({i+mx, j-mx});
        }

        mx = min(y-j, i);
        if(!vis[i-mx][j+mx]) {
            mp[{i-mx, j+mx}] = {i, j};  
            vis[i-mx][j+mx] = 1;
            q.push({i-mx, j+mx});
        }

        // Empty a Jug
        if(!vis[i][0]){mp[{i, 0}] = {i, j}; vis[i][0] = 1; q.push({i, 0});}
        if(!vis[0][j]){mp[{0, j}] = {i, j}; vis[0][j] = 1; q.push({0, j});}

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
    
    cerr << setprecision(9) << fixed;
    cout << setprecision(9) << fixed;

    ll t = 1;
    // cin >> t;

    while(t--) {
        solve();
        cout << endl;
    } 
    return 0;
}   