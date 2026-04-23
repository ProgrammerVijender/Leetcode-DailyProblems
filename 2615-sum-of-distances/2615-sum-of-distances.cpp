// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         unordered_map <long long ,vector<long long>> mp;
//         vector <long long> v;
//         for(int i=0; i<mp.size(); i++)
//         {
//             mp[nums[i]].push_back(i);
//         }

//         for(auto& i:nums)
//         {   long long ans = 0;
//             vector <long long > temp;
//             if(mp.find(i) != mp.end())
//             {
//                 temp = mp[i];

                
//             }

//             if(temp.size() >=2)
//             {
//                 for(int j=1; j<temp.size(); j++)
//                 {
//                     ans += abs(temp[j] - temp[0]);
//                 }
//             }

//             v.push_back(ans);
//         }

//         return v;
//     }
// };

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // Step 1: store indices of each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> res(n, 0);

        // Step 2: process each group
        for (auto &it : mp) {
            vector<int> v = it.second;
            int m = v.size();

            // prefix sum array
            vector<long long> prefix(m, 0);
            prefix[0] = v[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }

            // calculate answer for each index
            for (int i = 0; i < m; i++) {

                long long left = 0;
                long long right = 0;

                // left side distance
                if (i > 0) {
                    left = (long long)i * v[i] - prefix[i - 1];
                }

                // right side distance
                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - (long long)(m - i - 1) * v[i];
                }

                res[v[i]] = left + right;
            }
        }

        return res;
    }
};