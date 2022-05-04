class Solution{
public:

    int Solve(int arr[], int i,int j )
    {
        if(i>=j)
            return 0;
            
        int ans = INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int temp = Solve(arr,i,k)+Solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            ans = min(ans,temp);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return Solve(arr,1,N-1);
    }
};
