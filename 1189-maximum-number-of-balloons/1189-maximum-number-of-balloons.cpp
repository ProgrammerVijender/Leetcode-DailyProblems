class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(5,0);

        for(auto i:text)
        {
            if(i == 'b') v[0]++;
            if(i == 'a') v[1]++;
            if(i == 'l') v[2]++;
            if(i == 'o') v[3]++;
            if(i == 'n') v[4]++;
        }

        int mini = INT_MAX;
        for(int i=0; i<v.size(); i++)
        {
            int val;
            if(i == 2 || i == 3)
            {
                val = v[i] / 2;
            }
            else
            {
                val = v[i];
            }

            if(val <mini)
            {
                mini = val;
            }
        }

        return mini;
    }
};