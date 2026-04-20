class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int ans  = -1;

        if(colors.size() <= 1) return -1;

        int start = colors[0];

        for(int i=colors.size() - 1; i >=1; i-- )
        {
            if(colors[i] != start)
            {
                    ans = max( ans , i - 0);
            }
        }


        int end = colors[colors.size() - 1];

        for(int i=0; i <=colors.size() - 2; i++ )
        {
            int temp =colors.size() - i;
            if(colors[i] != end)
            {
                    ans = max( ans , temp-1 );
            }
        }
        return ans;
    }
};