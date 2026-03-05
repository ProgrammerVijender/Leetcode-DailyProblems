class Solution {
public:
    int minOperations(string s) {
        

        int count1 = 0;
        int count2 = 0;

        for(int i=0; i < s.size(); i++)
        {
            char expect1 = (i%2 == 0) ? '1':'0';
            char expect2 = (i%2 == 0) ? '0':'1';

            if(expect1 != s[i]) count1++;
            if(expect2 != s[i]) count2++;
        }

        return min(count1 , count2);
    }
};