class Info{
    public:

    int data;
    int dataRow;
    int dataCol;

    Info(int data , int r , int c)
    {
        this->data = data;
        this->dataRow = r;
        this->dataCol = c;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b)
    {
        return a->data > b-> data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<Info* , vector<Info*> ,compare> pq;

        int maxi = INT_MIN;
        // row push
        for(int i=0; i<nums.size(); i++)
        {
            int val = nums[i][0];
            maxi = max(maxi , val);
            Info* temp = new Info(val,i ,0);
            pq.push(temp);
        }
        int start = INT_MIN;
        int end = INT_MIN;

        int mini = INT_MAX;
        int diff;
        int maxdiff = INT_MAX;
        while(!pq.empty())
        {
            Info* temp = pq.top();
            pq.pop();

            int data = temp->data;
            int row = temp->dataRow;
            int col = temp->dataCol;

            mini = data;
            diff = maxi - mini;

            if(maxdiff > diff)
            {
                start = mini;
                end = maxi;
                
                maxdiff = diff;
            }
            if(col + 1 < nums[row].size())
            {   
                Info* temp2 = new Info(nums[row][col+1],row,col+1);
                pq.push(temp2);

                maxi = max(nums[row][col+1],maxi);
            }
            else
            {
                break;
            }
        }

        return {start,end};
    }
};