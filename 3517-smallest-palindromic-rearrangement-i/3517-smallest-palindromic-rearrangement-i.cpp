// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         vector <int> v(26,0);

//         for(int i=0; i<s.length(); i++)
//         {
//             int val = s[i] - 'a';

//             v[val]++;
//         }

//         string temp="";
//         for(int& i:v)
//         {
//             if(v[i] %2 == 0)
//             {
//                 int t = v[i] / 2;
//                 while(t>0)
//                 {
//                 char n = char(i+'a');
//                 temp +=n;
//                 t--;
//                 }
//             }
//             else
//             {

//             }
//         }
//         return temp;
//     }
// };

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        string firstHalf = "";
        string middle = "";

        // Build first half and find middle character
        for (int i = 0; i < 26; i++) {
            firstHalf.append(freq[i] / 2, char('a' + i));

            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
            }
        }

        // Build second half
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + middle + secondHalf;
    }
};