class Solution {
public:

    // recursion 
    // bool sol(string& s, int i , int count)
    // {
    //     if(count <0 )
    //     {
    //         return 0;
    //     }
    //     if( i == s.length() )
    //     {
    //         return count == 0;
    //     }

    

    //     bool check;
    //     if(s[i] == '(')
    //     {
    //         return sol(s , i+1 , count+1);
    //     }

    //     else if(s[i] == ')')
    //     {
    //         return sol(s , i+1 , count-1);
    //     }
    //     else
    //     {
    //         // bool a = sol(s , i+1 , count+1);
    //         // bool b = sol(s , i+1 , count-1);
    //         // bool c = sol(s, i+1 , count);
    //         return check = sol(s , i+1 , count+1) || sol(s , i+1 , count-1) || sol(s, i+1 , count);
    //     }
    // }

    // recursion + memoisation
    bool sol(string& s, int i , int count , vector <vector <int> > &dp)
    {
        if(count <0 )
        {
            return 0;
        }
        if( i == s.length() )
        {
            return count == 0;
        }

        if(dp[i][count] != -1)
        {
            return dp[i][count];
        }

    

        bool check;
        if(s[i] == '(')
        {
            return sol(s , i+1 , count+1, dp);
        }

        else if(s[i] == ')')
        {
            return sol(s , i+1 , count-1 , dp);
        }
        else
        {
            // bool a = sol(s , i+1 , count+1);
            // bool b = sol(s , i+1 , count-1);
            // bool c = sol(s, i+1 , count);
             dp[i][count] = sol(s , i+1 , count+1 , dp) || sol(s , i+1 , count-1 ,dp) || sol(s, i+1 , count ,dp);
        }
        return dp[i][count];
    }


    bool checkValidString(string s) {

        vector <vector<int> > dp(s.length()  , vector<int> (s.length() , -1 ));
        return sol(s , 0, 0 , dp);
    }
};
















// class Solution {
// public:
//     bool solve(const string &s, int i, int cnt) {
//         // If count goes negative, it's invalid
//         if (cnt < 0) return false;

//         // At the end, count must be zero
//         if (i == s.size()) {
//             return cnt == 0;
//         }

//         if (s[i] == '(') {
//             return solve(s, i + 1, cnt + 1);
//         } else if (s[i] == ')') {
//             return solve(s, i + 1, cnt - 1);
//         } else {
//             // s[i] == '*' -> Try all three:
//             // 1) Treat as '('
//             // 2) Treat as ')' 
//             // 3) Treat as empty
//             return solve(s, i + 1, cnt + 1) || solve(s, i + 1, cnt - 1) || solve(s, i + 1, cnt);
//         }
//     }

//     bool checkValidString(string s) {
//         return solve(s, 0, 0);
//     }
// };