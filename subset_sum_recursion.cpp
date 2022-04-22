
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(vector<int>arr,int n, int sum)
    {
        if(sum==0&&(sum==0||arr.size()==0)) // if sum become zero return true
            return true;
        else if(arr.size()==0||n<=0||sum<0)
            return false;
        
        if(arr[n-1]<=sum)
        {
            bool take = helper(arr,n-1,sum-arr[n-1]);  // take
            bool not_take = helper(arr,n-1,sum);       // not take
            return (take||not_take);
        }
        else if(arr[n-1]>sum)
        {
            bool check_for_next = helper(arr,n-1,sum);
            return check_for_next;
        }
        return false;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        return helper(arr,arr.size(),sum);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
