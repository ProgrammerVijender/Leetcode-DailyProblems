#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool checkvolwel(string s)
    {
        int n = s.length();
       if((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s[n-1] == 'a' || s[n-1] == 'e' || s[n-1] == 'i' || s[n-1] == 'o' || s[n-1] == 'u') )
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> temp;
        int val = 0;
        for(int i=0; i<words.size(); i++)
        {
            bool check = checkvolwel(words[i]);
            if(check == 1)
            {
                val++;
            }
            temp.push_back(val);
        } 
        
        for(auto j:queries)
        {
            int start = j[0];
            int end = j[1];
            if(start <= 0)
            {

            ans.push_back(temp[end]);
            }
            else
            {
            int value =  temp[end] - temp[start-1];
            ans.push_back(value);
            }
        }

        return ans;
    }
};

// Main function to test the code
int main() {
    Solution sol; // Create an instance of the Solution class

    // Input data
    vector<string> words = {"apple", "banana", "orange", "umbrella", "ace"};
    vector<vector<int>> queries = {{0, 2}, {1, 3}, {0, 4}};

    // Get the result
    vector<int> result = sol.vowelStrings(words, queries);

    // Print the results
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0; // Indicate successful execution
}