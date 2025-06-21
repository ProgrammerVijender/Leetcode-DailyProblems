class Solution {
public:

    int lcs(string &s1, string &s2 , int i, int j ,vector< vector <int> > &dp )
    {
        if( i >= s1.length() || j >= s2.length())
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if(s1[i] == s2[j])
        {
            ans = 1 + lcs(s1 , s2, i+1, j+1 , dp);
        }

        else
        {
            ans  = max( lcs(s1,s2,i,j+1,dp) , lcs(s1,s2,i+1,j,dp) );
        }
        dp[i][j] = ans;

        return dp[i][j];
    }



    int lcsTab(string &s1, string &s2 ,vector< vector <int> > &dp )
    {
        int ans = 0;
        for(int i_index = s1.length()-1; i_index >=0; i_index--)
        {
            for(int j_jndex = s2.length()-1; j_jndex >=0; j_jndex--)
            {
                if(s1[i_index] == s2[j_jndex])
                {
                    dp[i_index][j_jndex] = 1 + dp[i_index +1][j_jndex +1];
                }
                else
                {
                    dp[i_index][j_jndex] = max(dp[i_index][j_jndex +1] , dp[i_index+1][j_jndex ]);
                }

            
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {

        vector< vector <int> > dp(text1.length() +1 ,vector <int>(text2.length() +1, 0) );
        //  int i = 0,j = 0;
        return lcsTab(text1 , text2 , dp);
    }
};