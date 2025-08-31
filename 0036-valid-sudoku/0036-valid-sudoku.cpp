class Solution {
public:


    bool validbox(vector<vector<char>>& board , int s , int s2 , int er, int ec )
    {
        set<char> st2;
        for(int i=s; i<er; i++)
        {
            for(int j =s2; j<ec; j++ )
            {
                if(board[i][j] == '.')  continue;

                else if(st2.find(board[i][j]) != st2.end())
                {
                   return false;
                }
                st2.insert(board[i][j]);
            }
        }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // set<char> st;

        for(int i=0; i<9; i++)
        {
            set<char> st;
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')  continue;

                else if(st.find(board[i][j]) != st.end())
                {
                   return false;
                }
                st.insert(board[i][j]);
            }

        }
        
        cout<<"1"<<endl;
        for(int i=0; i<9; i++)
        {
            set<char> st;
            for(int j=0; j<9; j++)
            {
                if(board[j][i] == '.')  continue;

                else if(st.find(board[j][i]) != st.end())
                {
                   return false;
                }
                st.insert(board[j][i]);
            }

        }

        for(int i=0; i<9; i += 3)
        {
            int er = i + 3;
            for(int j=0; j<9; j += 3)
            {
            // cout<<"2"<<endl;

                int ec = j+3;
                if(!validbox(board , i , j , er,ec ))
                {
                    return false;
                }
                
            }

        }


        


        return 1;
    }
};