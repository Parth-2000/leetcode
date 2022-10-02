class Solution {
public:
    int M = 1000000007;
    int solve(int N, int& K, int Target, vector<vector<int>>&dp){
        
        if(Target==0 and N==0){
            return dp[N][Target]=1;  
        }
        
        if(Target==0 and N!=0){
            return dp[N][Target]=0;
        }
        
        if(Target!=0 and N==0){
            return dp[N][Target]=0;
        }
        
        if(dp[N][Target]!=-1){
            return dp[N][Target];
        }
        
        dp[N][Target]=0;
        
        for(int i=1;i<=K;i++){
            if(i<=Target){
                dp[N][Target]=( (dp[N][Target]%M) + (solve(N-1,K,Target-i,dp)%M) )%M;
            }
        }
        
        return dp[N][Target]%M;   
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
        return solve(n,k,target,dp);
    }
};