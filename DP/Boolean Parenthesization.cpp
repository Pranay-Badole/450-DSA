// Boolean Parenthesization


Make a function fun(l, r)
which returns the no of ways we can parenthesize the equation such that it returns true;

So traverse from l -> r to consider every possibility where we will split the equation.

There are 3 cases for splitting the string i.e the operator joining the 2 equation '^', '|', '&'

1. ' | '
    for this there are 3 cases 
        T | F
        F | T
        T | T

2. ' & '
    for this there is 1 case 
        T | T

3. ' ^ '
    for this there are 2 cases
        T | F
        F | T

For finding the no of ways the left or right part returns true we will use the same function fun()
==> left == fun(l, k-1) ||  right == fun(k+1, r)


Now the important and tricky part is how to find the no of ways it returns false.

For that ==>  No_of_False = Total - No_of_True; 

To find the total we use the CATALAN Numbers.
As a pre processing part we calculate the catalan numbers beforehand.



ANOTHER APPROACH IS TO have 3D DP
dp[i][j][2]

dp[i][j][0] no of ways to parenthesize the equation that evaluates to false(0);
dp[i][j][1] no of ways to parenthesize the equation that evaluates to true(1);

############################################################################################################################################

class Solution{
public:
    const int M = 1003;
    
    vector<vector<int>> dp;
    vector<int> catalan;
    
    void find_catalan(int N) {
        catalan.resize((N-1)/2, 0);
        catalan[0] = catalan[1] = 1;
        
        for(int i = 2; i < (N-1)/2; i++) {
            for(int j = 0; j < i; j++) {
                catalan[i] = (catalan[i] + (catalan[j]*catalan[i-j-1]) % M) % M;
            }
        }
    }
    
    int fun(int l, int r, string &s) {
        
        if(l == r) {
            if(s[l] == 'T') return 1;
            else if(s[l] == 'F') return 0;
        }
        
        if(dp[l][r] != -1) return dp[l][r];     
        
        int ans = 0;
        
        for(int k = l+1; k < r; k += 2) {

            if(s[k] == '|') {
                ans = (ans + (fun(l, k-1, s) * (catalan[(r - k - 1)/2] - fun(k+1, r, s) + M) % M) % M) % M;
                ans = (ans + (((catalan[(k - l - 1)/2] - fun(l, k-1, s) + M) % M) * fun(k+1, r, s)) % M) % M;
                ans = (ans + (fun(l, k-1, s) * fun(k+1, r, s)) % M) % M;
            }
            else if(s[k] == '&') {
                ans = (ans + (fun(l, k-1, s) * fun(k+1, r, s)) % M) % M;
            }
            else {
                ans = (ans + (fun(l, k-1, s) * (catalan[(r - k - 1)/2] - fun(k+1, r, s) + M) % M) % M) % M;
                ans = (ans + (((catalan[(k - l - 1)/2] - fun(l, k-1, s) + M) % M) * fun(k+1, r, s)) % M) % M;
            }
        }
        return dp[l][r] = ans;
    } 

    int countWays(int N, string S){
        
        dp.assign(N, vector<int>(N, -1));
        if(N > 1) find_catalan(N);
        
        // for(auto &x : catalan) cout << x << ' ';
        
        int ans = fun(0, N-1, S);
        return ans;
        
    }
};