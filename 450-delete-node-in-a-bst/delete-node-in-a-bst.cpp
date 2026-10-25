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
void find(TreeNode* root , int key)
{
    if(root==NULL)return  ;
    if(root->val>key)
    {
        if(root->left && root->left->val==key)
        {
            root->left = del(root->left) ;
        }
         find(root->left,key) ;
    }
    else{
        if(root->right && root->right->val==key)
        {
            root->right = del(root->right) ;
        }
         find(root->right,key) ;
    }
}
TreeNode* func(TreeNode* root)
{
    if(root->left == NULL)return root ;
    return func(root->left) ;
}
TreeNode* del(TreeNode* root)
{
    if(root->left==NULL)return root->right ;
    if(root->right==NULL)return root->left ;

    TreeNode* right = root->right ;
        TreeNode* lm = func(root->right) ;
        lm->left = root->left ;
        return right ;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL ;
        if(root->val==key)
        {
            return del(root) ;
        }
        find(root,key);
        return root ;
    }
};