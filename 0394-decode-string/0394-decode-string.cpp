class Solution {
public:
    string decodeString(string s) {
        stack <string > st;

        int i =0;

        string ans;
        while(i<s.length())
        {
            if(s[i] == ']')
            {
                string temp; 
                while(!st.empty() && st.top() != "[")
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                // reverse(temp.begin() , temp.end());
                
                if (!st.empty() && st.top() == "[") {
                    st.pop();
                }

                string num;

                while(!st.empty() && isdigit(st.top()[0]))
                {
                    num = st.top() + num;
                    st.pop();
                }

                int n = stoi(num);

                string val;
                for(int j=0; j<n; j++)
                {
                    val +=temp;
                }
                st.push(val);

            }
            else
            {
                st.push(string(1, s[i]));
            }
            i++;
        }

        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};