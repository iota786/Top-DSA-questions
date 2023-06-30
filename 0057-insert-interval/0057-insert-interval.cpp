class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& n) {
        intervals.push_back(n);
        sort(intervals.begin(),intervals.end());
         vector<vector<int>> ans;
        
        int size = intervals.size();
        //starting condition  
		ans.push_back(intervals[0]);

		for(int i = 1; i < size; ++i){
            //previous ending time >= current starting time
			if((ans.back())[1] >= intervals[i][0]){ 
                //max ending time
				ans.back()[1] = max(intervals[i][1], ans.back()[1]);
			}
            else{
                //not overlapping  
				ans.push_back(intervals[i]);
			}
		} 
		return ans;
    }
};