class Solution {
public:
    bool isSubsequence(string s, string t) {

        int j= 0;

        if(s == "") return 1;
        for(int i=0; i<t.length(); i++)
        {
            if(t[i] == s[j])
            {
                j++;
            }
            if(j==s.length())
            {
                return 1;
            }
        }

        return 0;
    }
};