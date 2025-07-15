class Solution {
public:
    bool isValid(string word) {
        
        bool vowel = 0;
        bool cons = 0;
        bool checkchars = 1;
        bool nonvo =0;

        if(word.length() > 2)
        {
            for(int i=0; i<word.size(); i++)
            {
                if( isdigit(word[i]))
                {
                    cons =1;
                }
                bool check = word[i] == 'a' ||  word[i] == 'e' ||  word[i] == 'i' ||  word[i] == 'o' ||  word[i] == 'u' || word[i] == 'A' ||  word[i] == 'E' ||  word[i] =='I' ||  word[i] == 'O' ||  word[i] == 'U' ;
                if( check)
                {
                    vowel =1;
                }
                if(!check && !isdigit(word[i]))
                {
                    cout<<check<<endl;
                    nonvo = 1;
                }


                if(!isalpha(word[i]) && !isdigit(word[i]) )
                {
                    checkchars = 0;
                    break;
                }
            }
        }

        if( (vowel && checkchars && nonvo) )
        {
            return 1;
        }
            return 0;
        
    }
};