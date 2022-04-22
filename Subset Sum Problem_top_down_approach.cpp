//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // top_down
        // initialization
        // here we are setting 1st row and 1st column 
        // i denotes the size of the array 
        // j denotes the target sum (subset sum)
        int n = arr.size()+1;
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)  // itereate as long it is less then length of the array
        {
            for(int j = 0; j<sum+1;j++)
            {
                if(i == 0)      // when array(i) is empty than there is no meaning of sum of elements so return false
                    dp[i][j] = false;
                else if(j==0)       // when sum(j) is zero and there is always a chance of empty subset so return it as true;
                    dp[i][j] = true;
            }
        }
        // start from 1 since 1st row and column is already considerd 
        for(int i=1;i<=n;i++)
        {
            for(int j = 1; j<=sum;j++)
            {
                // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array 
               if(arr[i-1]==j)          
               {
                   dp[i][j] = true;
               }
               else if(arr[i-1]<j)
              {
                  bool take  = dp[i-1][j-arr[i-1]];
                  bool not_take = dp[i-1][j];
                  dp[i][j] = take||not_take;
              }
               else if(arr[i-1]>j) // if sum is less than array size just leave and increment
               {
                   bool check_for_next = dp[i-1][j] ;
                   dp[i][j] = check_for_next ; // storing last element;
               }
            }
        }
        return dp[n][sum];  // at last return T/F where we will ruch sum value wether we meet our requirement or not
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
  // } Driver Code Ends
