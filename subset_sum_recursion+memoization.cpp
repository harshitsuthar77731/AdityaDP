class Solution{   
public:
    int dp[101][10001];
    Solution() //constructor 
    { memset(dp,-1,sizeof(dp));}
    bool helper(vector<int>arr,int n, int sum)
    {
        if(sum==0&&(sum==0||arr.size()==0)) // if sum become zero return true
          return true;
        else if(arr.size()==0||n<=0||sum<0)
               return false;
               
        if(dp[n][sum]!=-1)
        {
            if(dp[n][sum]==0)
                return false;
            else 
                return true;
        }
        
        if(arr[n-1]<=sum)
        {
            bool take = helper(arr,n-1,sum-arr[n-1]);  // take
            bool not_take = helper(arr,n-1,sum);       // not take
            bool res = take||not_take;
            if(res)
             dp[n][sum] = 1;
            else
             dp[n][sum] = 0;
            return (take||not_take);
        }
        else if(arr[n-1]>sum)
        {
            bool check_for_next = helper(arr,n-1,sum);
            if(check_for_next)
             dp[n][sum] = 1;
            else
             dp[n][sum] = 0;
            return check_for_next;
        }
        return false;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        return helper(arr,arr.size(),sum);
    }
};
