class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto i:nums)
        {
            cout<<i<<" ";
            int temp = 0;
            int divCount = 0;
            for(int j=1; j <=i; j++)
            {
                
                if(i%j == 0)
                {
                    divCount++;
                temp += j;
                }
                if (divCount > 4) break;
            }
            if(divCount == 4)
            {
                ans += temp;
            }
        }
        return ans;
    }
};