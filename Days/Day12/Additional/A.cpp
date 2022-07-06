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
    bool isBST = true;
    long long prev = -2147483649;
    
    void inOrder(TreeNode *current){
        if(current == NULL) return;
        inOrder(current->left);
        if(current->val <= prev) isBST = false;
        prev = current->val;
        inOrder(current->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return isBST;
    }
};