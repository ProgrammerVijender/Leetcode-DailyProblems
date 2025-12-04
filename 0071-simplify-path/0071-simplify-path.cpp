class Solution {
public:
    string simplifyPath(string path) {

        int i=0;
        stack <string> st;

        while(i<path.size() )
        {
            while(i<path.size() &&  path[i] == '/')
            {
                i++;
            }


            string temp;
            while(i<path.size() &&  path[i] != '/')
            {
                temp +=path[i];
                i++;
            }


            if(temp == ".." )
            { 
                if(!st.empty())
                {st.pop();}
            }
            else if(temp != "." && !temp.empty())
            {st.push(temp);}

        }

        string sol;
        while(!st.empty())
        {
        sol = "/" + st.top()+ sol;
                       st.pop();
        }



    return sol.empty() ? "/" : sol;

  }
};



