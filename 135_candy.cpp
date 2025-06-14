class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0, t = 1;
        vector<int> right(ratings.size(),1);
        for(int i=ratings.size()-2;i>=0;--i) if(ratings[i]>ratings[i+1]) right[i]=right[i+1]+1;
        for(int i=0;i<ratings.size();i++) {
            if(!i) {ans += max(t,right[i]);continue;}
            t = ratings[i]>ratings[i-1]?t+1:1;
            ans += max(t,right[i]);
        }
        return ans;
    }
};