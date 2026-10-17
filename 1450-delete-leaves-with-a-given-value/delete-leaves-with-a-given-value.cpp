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
TreeNode* func(TreeNode* root , int target , TreeNode* par)
{
    if(root==NULL)return NULL ;
   root->left =  func(root->left,target,par) ;
    root->right =func(root->right,target,par) ;
    if(root->left==NULL && root->right == NULL && root->val == target)
    {
        root = NULL ;
        return root ;
    }
    return root ;
}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       return func(root,target,NULL) ;
        
    }
};