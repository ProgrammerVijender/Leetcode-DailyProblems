class Solution {
public:

    double calc(int pass , int total)
    {
        return (double)(pass+1) / (total +1 ) - (double) pass/total;
    }


    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue <pair <double, pair<int,int>>> maxHeap;

        for(auto clas : classes)
        {
            maxHeap.push({calc(clas[0] , clas[1]) , {clas[0] , clas[1] }});
        }

        while(extraStudents--)
        {
            auto topElement = maxHeap.top();
            maxHeap.pop();

            int pass = topElement.second.first;
            int total = topElement.second.second;

            maxHeap.push({calc(pass+1, total+1),{ pass+1,total+1 }});

        }

        double val = 0;
        while(!maxHeap.empty())
        {
            auto heap = maxHeap.top();

            maxHeap.pop();

            val += (double) heap.second.first / heap.second.second;

        }

        return val / classes.size();
    }
};