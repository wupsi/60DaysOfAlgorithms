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
    bool isFind = false;
    TreeNode *mainRoot = new TreeNode();
    TreeNode *find(TreeNode *current, int x){
        if(current == NULL) return NULL;
        if(x > current->val) current = find(current->right, x);
        else if(x < current->val) current = find(current->left, x);
        return current;
    }

    void inOrder(TreeNode *current, int k){
        if(current == NULL) return;
        inOrder(current->left, k);
        TreeNode *finded = find(mainRoot, k - current->val);
        TreeNode *secondFinded = find(mainRoot, current->val - k);
        if(finded != NULL)
            if(finded->val + current->val == k and finded != current) isFind = true;
        if(secondFinded != NULL)
            if(secondFinded->val + current->val == k and secondFinded != current) isFind = true;
        inOrder(current->right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root->left == NULL and root->right == NULL) return false;
        mainRoot = root;
        inOrder(root, k);
        return isFind;
    }
};