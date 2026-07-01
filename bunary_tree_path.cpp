class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* root, string path) {
        if (!root) return;

        if (!path.empty())
            path += "->";

        path += to_string(root->val);

        // Leaf node
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};