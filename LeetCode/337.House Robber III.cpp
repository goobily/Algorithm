/*
337. House Robber III
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

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
    struct money
    {
    	int pre; //当前节点不偷，收益为子节点偷的情况的收益和
    	int curr; //当前节点偷，收益为加上两子节点不偷的收益
    	money() : pre(0), curr(0){}
    };
    
    money dfs(TreeNode * root)
    {
    	if(root == NULL) return money();
    	money leftMoney = dfs(root->left);
    	money rightMoney = dfs(root->right);
    	money sumMoney;
    	sumMoney.pre = leftMoney.curr + rightMoney.curr;
    	sumMoney.curr = max(sumMoney.pre, root->val + leftMoney.pre + rightMoney.pre);
    	return sumMoney;
    }
    int rob(TreeNode* root) {
        money sum = dfs(root);
	    return sum.curr;
    }
};