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
    TreeNode *newRoot = new TreeNode(-1001);
    
    TreeNode *insert(TreeNode *current, int x){
        if(current == NULL){
            current = new TreeNode(x);
            return current;
        }
        if(x > current->val) current->right = insert(current->right, x);
        else if(x < current->val) current->left = insert(current->left, x);

        return current;
    }
    
    void inOrder(TreeNode *current){
        if(current == NULL) return;
        inOrder(current->left);
        newRoot = insert(newRoot, current->val);
        inOrder(current->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        return newRoot->right;
    }
};