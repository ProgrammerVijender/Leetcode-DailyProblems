class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() == 0)
        {
            return 1;
        }

        int f = s.find("abc");
        if(f != string::npos)
        {
        string left = s.substr(0, f);
        string right = s.substr(f+3);
        
            return isValid(left+right);
        }
        return 0;

    }
};