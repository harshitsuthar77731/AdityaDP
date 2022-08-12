class Solution {
public:
    // like diameter
    int solve(Node* root,int& res){
        if(root==NULL)
            return -1e8;
        if(!root->left&&!root->right)
            return root->data;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        int temp = max(l,r)+root->data;
        res = max(res,l+r+root->data);
        return temp;
    }
    int maxPathSum(Node* root)
    {
       int res = INT_MIN;
       int x = solve(root,res);
       if(root->left==NULL||root->right==NULL)
            return max(res,x);
       return res;
    }
};
