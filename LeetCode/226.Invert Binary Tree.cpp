/*
226. Invert Binary Tree

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode * pLeft = NULL, *pRight=NULL;
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        if(root->left != NULL) {
            pLeft = invertTree(root->left);
        }
        if(root->right != NULL) {
            pRight = invertTree(root->right);
        }
        root->left = pRight;
        root->right = pLeft;
        return root;
    }
};