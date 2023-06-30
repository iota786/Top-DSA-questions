class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        bool flag=false;
        int start=newInterval[0];;
        int end=newInterval[1];
// Insert all the intervals which are strictly lesser than the new Interval.
        while(i<intervals.size() && intervals[i][1]<newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }
// Overlapping intervals
        while(i<intervals.size() && intervals[i][0]<=newInterval[1])
        {
            
            start=min(intervals[i][0],start);
            end=max(intervals[i][1],end);
            i++;
        }
//Strictly Greater intervals
        result.push_back({start,end});
        while(i<intervals.size())
        {
            result.push_back(intervals[i]);
            i++;
        }
       
        return result;
        
    }
};