class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;

        for(char i:s)
        {
            if(i == '(')
            {
                st.push(i);
            }
            else{
                if(!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                   st.push(i);
                }
            }
        }
        return st.size();
    }
};