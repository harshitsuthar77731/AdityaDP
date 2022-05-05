class Solution{
public:
    int dp[1001][1001];
    
    bool ispalindrome(string& s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int partition(string& s,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(i>=j||ispalindrome(s,i,j))         // if string is ="" or string is equal to single character not partitioning possible so return 0;
            return 0;
            
        int ans = INT_MAX; 
        
        for(int k=i;k<=j-1;k++)
        {
            int left,right;
            if(dp[i][k]==-1)
                left = partition(s,i,k);
            else
                left = dp[i][k];
            
            if(dp[k+1][j])
                right= partition(s,k+1,j);
            else
                right = dp[k+1][j];
            
            int temp = left+right+1; 
            ans= min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
       return partition(str,0,str.size()-1);
    }
};
