/*
104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Subscribe to see which companies asked this question

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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
			return 0;
		int m_Ldepth = 1;
		int m_Rdepth = 1;
		if(root->left != NULL){
			m_Ldepth += maxDepth(root->left);	
		}
		if(root->right != NULL){
			m_Rdepth += maxDepth(root->right);
		}
		return m_Ldepth >= m_Rdepth ? m_Ldepth : m_Rdepth;
    }
};