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
    int minAbs = 100001;
    int prev = -100001;
    
    void inOrder(TreeNode *current){
        if(current == NULL) return;
        inOrder(current->left);
        int diff = current->val - prev;
        if(diff < minAbs) minAbs = diff;
        prev = current->val;
        inOrder(current->right);
    }

    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return minAbs;
    }
};