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
    TreeNode* markParents(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) t = node;
            if(node->left) {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
        return t;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        TreeNode* target = markParents(root, start, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int d = 0;
        while(!q.empty()) {
            int size = q.size();
            d++;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent_track[node] && !visited[parent_track[node]]) {
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }
        if(root->left == NULL && root->right == NULL) return 0;
        return d-1;
    }
};