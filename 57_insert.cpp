class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l=-1, r=intervals.size(), p=0;
        while(p<intervals.size()&&newInterval[0]>intervals[p][1]) p++;
        l = p-1;
        while(p<intervals.size()&&newInterval[1]>=intervals[p][0]) p++;
        r = p-1;
        if(!intervals.size()||newInterval[0]>intervals[intervals.size()-1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval[1]<intervals[0][0]) {
            vector<vector<int>> ans;
            ans.push_back(newInterval);
            for(int i=0;i<intervals.size();i++) ans.push_back(intervals[i]);
            return ans;
        }
        vector<int> t(2);
        t[0] = min(newInterval[0],intervals[l+1][0]);
        t[1] = max(newInterval[1],intervals[r][1]);
        vector<vector<int>> ans;
        for(int i=0;i<=l;i++) ans.push_back(intervals[i]);
        ans.push_back(t);
        for(int i=r+1;i<intervals.size();i++) ans.push_back(intervals[i]);
        return ans;
    }   
};