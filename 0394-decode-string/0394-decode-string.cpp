class Solution {
public:
    string decodeString(string s) {
        stack<string> st;  
        string curr = "";
        int num = 0;

        for(char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');   // form number
            }

            else if (ch == '[') {
                // push number and current string on stack
                st.push(curr);
                st.push(to_string(num));
                curr = "";
                num = 0;
            }

            else if (ch == ']') {
                // top is number
                int repeat = stoi(st.top());
                st.pop();

                // next is previous string
                string prev = st.top();
                st.pop();

                // build repeated string
                string temp = "";
                while(repeat--) temp += curr;

                // append to previous part
                curr = prev + temp;
            }

            else {
                curr += ch;      // add character to current string
            }
        }

        return curr;
    }
};