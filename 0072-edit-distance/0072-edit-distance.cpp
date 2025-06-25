class Solution {
public:

int sol(string &a, string &b , int i , int j)
    {
        int m = a.size();
        int n = b.size();

        if(i == m)
        {
            return n-j;
        }
        if(j == n )
        {
            return m -i;
        }

        int mini = 0;
        if(a[i] == b[j])
        {
                return sol(a,b,i+1 , j+1);
        }
        // else
        // {

        int replace = 1 + sol(a ,b,i+1 ,j+1);
        int remove1 = 1 + sol(a,b,i+1 , j);
        int remove2 = 1 + sol(a,b,i , j+1);
        
        mini = min({ replace , remove1, remove2});
        // }

        return mini;
    }

int solUsingMEM(string &a, string &b , int i , int j ,vector < vector <int> >& dp )
    {
        int m = a.size();
        int n = b.size();

        if(i == m)
        {
            return n-j;
        }
        if(j == n )
        {
            return m -i;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int mini = 0;
        if(a[i] == b[j])
        {
                return solUsingMEM(a,b,i+1 , j+1 , dp);
        }
        // else
        // {

        int replace = 1 + solUsingMEM(a ,b,i+1 ,j+1 , dp);
        int remove1 = 1 + solUsingMEM(a,b,i+1 , j , dp);
        int remove2 = 1 + solUsingMEM(a,b,i , j+1 , dp);
        
         dp[i][j] = min({ replace , remove1, remove2});
        // }

        return dp[i][j];
    }

    int minDistance(string &word1, string &word2 ) {

        vector < vector <int> > dp(word1.size() , vector <int> (word2.size() , -1) );
        
        return solUsingMEM(word1 ,word2 , 0 , 0 , dp);


    }
};