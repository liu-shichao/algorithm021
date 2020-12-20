
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end) {
        if (p_start == p_end) {
            return NULL;
        }
        int root_val = preorder[p_start];
        TreeNode* root = new TreeNode(root_val);
        int i_root_idx = 0, l_num = 0;
        for(int i = 0; i < inorder.size(); i ++) {
            if (inorder[i] == root_val) {
                i_root_idx = i;
                l_num = i_root_idx - i_start;
            }
        }
        root->left = buildTreeHelper(preorder,p_start + 1, p_start + l_num + 1, inorder, i_start, i_root_idx);
        root->right = buildTreeHelper(preorder, p_start + l_num + 1, p_end, inorder, i_root_idx + 1, i_end);
        return root;
    }
};
