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
    TreeNode* constructTree(vector<int>&in, int s, int e){
        if(s>e){
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = constructTree(in, s, mid-1);
        root->right = constructTree(in, mid+1, e);
        return root;
    }
    void inorder(TreeNode* root, vector<int>&in){
        if(root == NULL){
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root, in);
        return constructTree(in, 0, in.size()-1);
    }
};