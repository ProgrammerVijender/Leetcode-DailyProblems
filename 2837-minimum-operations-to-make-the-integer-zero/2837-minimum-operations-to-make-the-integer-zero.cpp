class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int k=1; k<=60; k++)
        {
            long dif = (long) num1 - (long) k *  num2;

            if(dif < 0)
            {
                continue;
            }

            int bits = __builtin_popcountll(dif);

            if(bits <= k && dif >= k)
            {
                return k;
            }
        }

        return -1;
    }
};