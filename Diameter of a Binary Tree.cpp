class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node* root,int &res){
        if(root==NULL)
            return 0;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        int temp = max(l,r)+1; // max till now to send to next node
        int ans = max(temp,l+r+1); // if that node is our answer
        res = max(ans,res);
        return temp;
    }
    int diameter(Node* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
