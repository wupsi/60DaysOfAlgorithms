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
    int sum = 0;
    void inOrder(TreeNode *current, int low, int high){
        if(current == NULL) return;
        inOrder(current->left, low, high);
        if(current->val >= low and current->val <= high) sum += current->val;
        inOrder(current->right, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        inOrder(root, low, high);
        return sum;
    }
};