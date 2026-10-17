/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
pair<int,int> func(TreeNode* root)
{
    if(root==NULL)return {0,0} ;
    auto left = func(root->left) ;
    auto right = func(root->right) ;
    pair<int,int> ans = {0,0} ;
    ans.first = root->val + left.second + right.second ;
    ans.second = max(left.first,left.second) + max(right.first,right.second) ;

    return ans ;
    
}
    int rob(TreeNode*  root) {
        auto ans = func(root) ;
         return max(ans.first,ans.second) ;
    }
};