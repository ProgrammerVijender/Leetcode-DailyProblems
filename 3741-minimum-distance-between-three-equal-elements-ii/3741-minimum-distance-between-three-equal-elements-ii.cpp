

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;

        for(auto &it : mp) {
            vector<int> &v = it.second;

            if(v.size() >= 3) {
                for(int i = 0; i <= v.size() - 3; i++) {
                    mini = min(mini, 2 * (v[i+2] - v[i]));
                }
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};