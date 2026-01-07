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
 static const int MOD = 1000000007;

    long long totalSum = 0;
    long long maxProd = 0;

    long long Totalsum(TreeNode* root)
    {
        if (!root) return 0;
        return root->val + Totalsum(root->left) + Totalsum(root->right);
    }

    long long dfs(TreeNode* root)
    {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        maxProd = max(maxProd, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        if (!root) return 0;

        totalSum = Totalsum(root);
        dfs(root);

        return maxProd % MOD;
    }
};