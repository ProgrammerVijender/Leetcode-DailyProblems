class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;


        for(const char& i:s)
        {
            if(!st.empty() && !isdigit(st.top()) && isdigit(i) )
            {
                st.pop();
            }
            else 
            {
                st.push(i);
            }
            
        }

        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

    
         reverse(ans.begin() , ans.end());
    
        return ans;    
    }
};