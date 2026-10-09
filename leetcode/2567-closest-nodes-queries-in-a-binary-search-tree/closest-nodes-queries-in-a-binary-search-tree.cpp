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

    void inorder(TreeNode* root, vector<int>& arr) {
        if(!root) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        vector<int> arr;
        inorder(root, arr);

        vector<vector<int>> ans;

        for(int key : queries) {

            auto it = lower_bound(arr.begin(), arr.end(), key);

            int ceil = -1;
            int floor = -1;

            // ceil
            if(it != arr.end()) {
                ceil = *it;
            }

            // floor
            if(it != arr.end() && *it == key) {
                floor = key;
            }
            else if(it != arr.begin()) {
                --it;
                floor = *it;
            }

            ans.push_back({floor, ceil});
        }

        return ans;
    }
};