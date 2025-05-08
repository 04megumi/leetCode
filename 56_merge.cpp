class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        mergeSort(intervals, 0, intervals.size()-1);
        vector<vector<int>> ans;
        int p = 0;
        while(p < intervals.size()) {
            vector<int> t = intervals[p];
            p++;
            while(p < intervals.size() && t[1] >= intervals[p][0]) {
                t[1] = max(t[1], intervals[p][1]);
                p++;
            }
            ans.push_back(t);
        }
        return ans;
    }
    void mergeSort(vector<vector<int>>& intervals, int l, int r) {
        if(l>=r) return;
        int m = (l+r) >> 1;
        mergeSort(intervals, l, m);
        mergeSort(intervals, m+1, r);
        merge(intervals, l, m, r);
    }
    void merge(vector<vector<int>>& intervals, int l, int m, int r) {
        vector<vector<int>> temp;
        int p1 = l, p2 = m+1;
        for(int i=0;i<=(r-l);i++) {
            if(p2>r||p1<=m&&intervals[p1][0]<=intervals[p2][0]) {
                temp.push_back(intervals[p1]);
                p1++;
            } else {
                temp.push_back(intervals[p2]);
                p2++;
            }
        }
        for(int i=0;i<=(r-l);i++) intervals[l+i] = temp[i];
    }
};