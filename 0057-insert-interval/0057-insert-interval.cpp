class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>>result;
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        int idx=0;
        for(int i=0;i<n;i++){
            if(intervals[i][1]<newInterval[0]){
                result.push_back(intervals[i]);
                idx++;
            }
            else break;
        }
        while(idx<n && intervals[idx][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[idx][0]);
            newInterval[1]=max(newInterval[1],intervals[idx][1]);
            idx++;
        }
        result.push_back(newInterval);
        while(idx<n)result.push_back(intervals[idx++]);
        return result;
    }
};