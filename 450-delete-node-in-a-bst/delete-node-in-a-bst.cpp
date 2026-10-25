/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  void another(TreeNode* root , int key)
  {
    if(root==NULL)return  ;
    // if(root->val == key) return del(root) ;
    if(key < root->val)
    {
        if(root->left && root->left->val == key)
        {
            root->left = del(root->left) ;
            return ;
        }
        another(root->left , key) ;
    }
    else{
         if(root->right && root->right->val == key)
        {
            root->right = del(root->right) ;
            return ;
        }
        another(root->right , key) ;
    }
    return ;
  }
    TreeNode* flag(TreeNode* root) {
        if (root->right == NULL)
            return root;
       return flag(root->right);
    }
    TreeNode* del(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        TreeNode* rt = root->right;
        TreeNode* rightmost = flag(root->left);
        rightmost->right = rt;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (root->val == key) {
            return del(root);
        }
        // TreeNode* temp = root;
        another(root,key) ;
        return root ;
        // while (root != NULL) {
        //     if (key < root->val) {
        //         if (root->left != NULL && root->left->val == key) {
        //             root->left = del(root->left);
        //             break ;
        //         }
        //         root = root->left;
        //     } else {
        //         if (root->right != NULL && root->right->val == key) {
        //             root->right = del(root->right);
        //             break ;
        //         }
        //         root = root->right;
        //     }
        // }
        // return temp;
    }
};