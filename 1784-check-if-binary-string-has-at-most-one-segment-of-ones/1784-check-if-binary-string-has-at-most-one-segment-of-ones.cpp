class Solution {
public:
    bool checkOnesSegment(string s) {
        
        bool loopBreak = false;
        bool loop = false;

        for(char i:s)
        {
            if(i == '1' && !loopBreak)
            {
                
                loop = 1;
            }
            // else if(i == '1' && loop )
            // {
            //     return false;
            // }
            else if(i== '0' && loop)
            {
                loopBreak = 1;
            }
            else if(i == '1' && loopBreak)
            {
                
                return false;
            }
        }
        return loop;
    }
};