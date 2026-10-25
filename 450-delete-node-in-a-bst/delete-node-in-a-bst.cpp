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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val>key)root->left=deleteNode(root->left,key);
        if(root->val<key)root->right=deleteNode(root->right,key);
        if(root->val==key){
            if(!root->left && !root->right)return NULL;
            if(!root->left)return root->right;
            if(!root->right)return root->left;
            auto temp =root;
            root=root->left;
            while(root->right)root=root->right;
            temp->val=root->val;
            temp->left=deleteNode(temp->left,temp->val);
        return temp;
        }
        return root ;
    }
};