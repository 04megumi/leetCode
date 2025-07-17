class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> edges(numCourses);
        vector<int> degree(numCourses,0);
        queue<int> q;
        for(auto& item : prerequisites) {
            edges[item[1]].push_back(item[0]);
            degree[item[0]]--;
        }
        for(int i=0;i<numCourses;i++) if(!degree[i]) q.push(i);
        while(q.size()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                int cur = q.front();
                ans.push_back(cur);
                q.pop();
                for(auto& num : edges[cur]) {
                    degree[num]++;
                    if(!degree[num]) q.push(num);
                }
            }
        }
        for(int i=0;i<numCourses;i++) if(degree[i]) return vector<int>{};
        return ans;
    }
};