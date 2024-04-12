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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        int countPath = 0;
        long sum = 0;//使用int有可能产生溢出，可以选择更长的long int 型
        postorderTraversal(root, countPath, sum, targetSum);//求root为起点的树中路径数目
        //以root为根的树的路径数目等于左子树的路径数+右子树的路径数+以root为起点的树中节点值之和等于 targetSum的路径数
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + countPath;
    }

    void postorderTraversal(TreeNode* root, int& countPath, long& sum, int targetSum){
        if(!root){
            return;
        }
        if((sum += root->val) == targetSum){
            countPath++;
        }
        postorderTraversal(root->left, countPath, sum, targetSum);
        postorderTraversal(root->right, countPath, sum, targetSum);
        sum -= root->val;//回溯，回到上一个节点和
    }
};