class Solution {
public:

    bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
    }
    
    vector<int> closestPrimes(int left, int right) {
        
        vector <int> v;
        vector <int> ans(2,-1);
        int count = 0;
        int mini = INT_MAX;

        for(int i= left; i <= right; i++)
        {
            if(isPrime(i))
            {
                v.push_back(i);
                count++;
            }
            
            int diff=0;
            if(count > 1 )
            {
                diff = abs(v[count-2] - v[count-1] );
            }

            if( count > 1 && mini > diff)
            {
                mini = diff;
                ans[0] = v[count-2];
                ans[1] = v[count-1];

            }

        }
        return ans;
    }
};