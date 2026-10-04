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
    void getPath(TreeNode* node, string path, vector<string>& ans) {
        if(node == NULL) return;

        path += to_string(node->val);

        if(node->left == NULL && node->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";

        getPath(node->left, path, ans);
        getPath(node->right, path, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;

        getPath(root, "", ans);
        return ans;
    }
};