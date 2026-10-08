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
    // MORRIS TRAVERSAL
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;
        while(cur) {
            if(cur->left == NULL) {
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }

    // Iterative
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(root == NULL) return ans;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()) {
    //         TreeNode* node = st.top();
    //         st.pop();
    //         ans.push_back(node->val);
    //         if(node->right) {
    //             st.push(node->right);
    //         }
    //         if(node->left) {
    //             st.push(node->left);
    //         }
    //     }
    //     return ans;
    // }
};