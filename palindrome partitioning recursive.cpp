class Solution{
public:
    
    bool ispalindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
            {   
                i++;
                j--;
                continue;
            }
            else
                return false;
        }
        return true;
    }
    int partition(string s,int i,int j)
    {
        if(i>=j)         // if string is ="" or string is equal to single character not partitioning possible so return 0;
            return 0;

            
        if(ispalindrome(s,i,j)==true) // is string is palindrome so no partition is needed
            return 0;
        
        int ans = INT_MAX; 
        for(int k=i;k<=j-1;k++)
        {
            int temp = partition(s,i,k)+partition(s,k+1,j)+1; // total partition from i to k + total partion from k+1 to j + 1 (for this partiton)
            ans= min(ans,temp);
        }
        return ans;
    }
    int palindromicPartition(string str)
    {
       return partition(str,0,str.size()-1);
    }
};
