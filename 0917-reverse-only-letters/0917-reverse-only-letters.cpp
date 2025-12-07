class Solution {
public:
    string reverseOnlyLetters(string s) {

        string temp = s;
        int e = s.size() -1;
        int i=0;
        while(i<e)
        {
            char c = temp[i];
            char d = s[e];
            if(isalpha(c) && isalpha(d))
            {
                char t = temp[i];
                temp[i] = s[e];
                temp[e] = t;
                i++;
                e--;
            }
            else if(!isalpha(c) )
            {
                i++;
            }
            else if(!isalpha(d))
            {
                e--;
            }
        }
        return temp;
    }
};