class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(char i:s)
        {
            if( i == 'a')
            {
                st.push(i);
            }
            else if(i == 'b')
            {
                if(!st.empty()  &&  st.top() == 'a' )
                {
                    st.push(i);
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(!st.empty()  &&   st.top() == 'b')
                {
                    st.pop();
                    if(!st.empty()  &&  st.top() == 'a')
                    {
                        st.pop();
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
           
        }

        return (st.empty() ) ? 1:0;

    }
};