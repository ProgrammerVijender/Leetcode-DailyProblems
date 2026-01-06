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

    vector<long long> levelSum;
    void sol_DFS(TreeNode* root , int level)
    {
        if (!root) return;

        if (level == levelSum.size())
            levelSum.push_back(0);

        levelSum[level] += root->val;

        sol_DFS(root->left, level + 1);
        sol_DFS(root->right, level + 1);

    }

    int maxLevelSum(TreeNode* root) {
        
        sol_DFS(root, 0);

        long long maxSum = LLONG_MIN;
        int ansLevel = 0;

        for (int i = 0; i < levelSum.size(); i++) {
            if (levelSum[i] > maxSum) {
                maxSum = levelSum[i];
                ansLevel = i;
            }
        }

        return ansLevel + 1;
    }
};