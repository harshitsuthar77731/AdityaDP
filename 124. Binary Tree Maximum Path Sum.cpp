class Solution {
public:
    int solve(TreeNode* root, int &res){
        if(root==NULL)
            return 0;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        int temp =max(max(l,r)+root->val,root->val); // max till now to nsend to next node
        int ans = max(temp,l+r+root->val);// if this is our root for answer
        res = max(ans,res);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
