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
struct value{
    int left = 0  ;
    int right = 0 ;
    int nt = 0 ;
} ;
value func(TreeNode* root)
{
    if(root==NULL)return {0,0,0} ;
    value left = func(root->left) ;
    value right = func(root->right) ;
    value ans ;
    int lmax=max(left.nt,left.right) ;
    lmax = max(lmax,left.left) ;
    int rmax=max(right.nt,right.left) ;
    rmax = max(rmax,right.right) ;
    ans.nt = max(lmax,rmax) ;
    ans.left = 1+ left.right ;
    ans.right = 1+ (right.left) ;

    return ans ;
}
    int longestZigZag(TreeNode* root) {
        value ans =func(root) ;
        return(max(ans.nt,max(ans.left,ans.right)))-1 ;
    }
};