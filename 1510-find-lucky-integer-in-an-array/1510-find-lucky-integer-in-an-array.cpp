class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector <int > v(501,0);

        int ans = -1;
        for(int i=0; i<arr.size(); i++)
        {
            int val = arr[i];
            v[val]++;
        }

        // int temp = 1;
        for(int i=500; i>0; i--)
        {
            if(v[i] == i)
            {
                return i;
            }
            // temp++;
        }

        return ans;
    }
};