class Solution {
public:
    int dp[1001][10001];
        
    Solution()
    {memset(dp,-1,sizeof(dp));}
    
    bool helper(vector<int>& nums,int n,int target)
    {
        if(target==0||(target==0&&nums.size()==0))
            return true;
        else if(nums.size()==0||target<0||n<=0)
            return false;
        if(dp[n][target]!=-1)  // means we already have result of that target and n
        {
            if(dp[n][target]==1)
                return true;
            else
                return false;
        }
        
        // recursive case
        if(nums[n-1]<=target) // n-1 because nums index start's from 0
        {
            bool take = helper(nums,n-1,target-nums[n-1]);
            bool not_take = helper(nums,n-1,target);
            bool flag = take||not_take;
            if(flag)
                dp[n][target] = 1;
            else 
                dp[n][target] = 0;
            return flag;
        }
        else if(nums[n-1]>target)
        {
            bool check_for_next = helper(nums,n-1,target);
            if(check_for_next)
                dp[n][target] = 1;
            else 
                dp[n][target] = 0;
            return check_for_next;
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
     // equal summ partition first we will sum up all the array value and then 
     //   by dividing it we will find a target sum if it's odd means equal partition is        //not possible so we will return false if even then we will check it's sum
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2)
            return false;
        else
            return helper(nums,nums.size(),sum/2);
    }
};
