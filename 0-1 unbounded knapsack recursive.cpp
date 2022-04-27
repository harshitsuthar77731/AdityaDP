class Solution{
public:
    int fun(int n, int w, int val[], int wt[])
    {
        if(n<=0||w<=0)
            return 0;
        
        //recursive case
        
        if(wt[n-1]<=w)
        {
            int take = val[n-1]+fun(n,w-wt[n-1],val,wt); // passing n means we are taking same value again and again until our requirement this is the only change in code
            int not_take = fun(n-1,w,val,wt);
            return max(take,not_take);
        }
        else
            return fun(n-1,w,val,wt);
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        return fun(N,W,val,wt);
    }
};
