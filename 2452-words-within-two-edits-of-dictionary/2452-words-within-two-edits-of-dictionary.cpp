class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector <string> ans;
        for(string & i:queries)
        {
            for(string & j:dictionary)
            {
                int diff=0;
                for(int k=0; k<i.size(); k++)
                {
                    if( i[k] != j[k]) diff++;
                    if(diff > 2) break;
                }
                if(diff <= 2) {

                ans.push_back(i);
                break;
                }

            }
        }
        return ans;
    }
};