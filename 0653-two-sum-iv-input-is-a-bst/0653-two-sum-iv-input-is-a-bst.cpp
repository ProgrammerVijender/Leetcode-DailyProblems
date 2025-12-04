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

    void sol(TreeNode* root , vector<int>& ans)
    {
        if(root == NULL) return ;

        // LNR
        // L
        sol(root->left , ans);

        // N
        ans.push_back(root->val);

        // R
        sol(root->right , ans);

    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        sol(root , ans);

        int s = 0;
        int e = ans.size() -  1;

        while(s<e)
        {
            int sum = ans[s] + ans[e];

            if(sum == k)  return 1;
            else if(sum > k) e--;
            else if(sum < k) s++;
        }

        return 0;
    }
};