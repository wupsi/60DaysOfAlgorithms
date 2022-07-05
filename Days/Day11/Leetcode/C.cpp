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
    vector<int> v;
    int mode = 1;
    int maxMode = 0;
    int previ = -999999;
    void inOrder(TreeNode *current){
        if(current == NULL) return;
        inOrder(current->left);
        if(current->val != previ){
            if(maxMode == 0) maxMode++;
            else if(mode > maxMode){
                maxMode = mode;
                v.clear();
                v.push_back(previ);
            }
            else if(mode == maxMode)
                v.push_back(previ);
                
            mode = 1;
        }
        else mode++;
        previ = current->val;
        inOrder(current->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        if(mode > maxMode){
            maxMode = mode;
            v.clear();
            v.push_back(previ);
        }
        else if(mode == maxMode)
            v.push_back(previ);

        return v;
    }
};