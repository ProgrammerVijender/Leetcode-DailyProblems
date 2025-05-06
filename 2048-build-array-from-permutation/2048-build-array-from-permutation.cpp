class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        // int size =size();
        vector<int> ans;
        for (int i = 0; i <  nums.size(); i++) {
           
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }
};