class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector <int> v(10001,0);

        for(auto i: nums)
        {
            if(v[i] == 0)  v[i]++;
            else    return i;
        }
        return 0;
    }
    
};