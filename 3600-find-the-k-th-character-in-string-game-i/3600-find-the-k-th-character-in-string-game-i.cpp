class Solution {
public:
    char kthCharacter(int k) {
        string s = "abbcbccd";

        while(s.length() < k)
        {
            string temp;
            for(char i:s)
            {
                char t = i+1;
                temp +=t;
            }
            s +=temp;
        }


        return s[k-1];
    }
};