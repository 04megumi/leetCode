class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses); 
        vector<int> inEdge(numCourses,0);
        for(auto& item : prerequisites) {
            edges[item[0]].push_back(item[1]);
            inEdge[item[1]]--;
        }
        queue<int> poss;
        for(int i=0;i<numCourses;i++) if(inEdge[i]==0) poss.push(i);
        if(poss.size()==numCourses) return true;

        while(poss.size()) {
            int n = poss.size();
            for(int i=0;i<n;i++) {
                int cur = poss.front();
                poss.pop();
                for(auto& num : edges[cur]) {
                    inEdge[num]++;
                    if(!inEdge[num]) poss.push(num);
                }
            }
        }
        for(int i=0;i<numCourses;i++) if(inEdge[i]) return false;
        return true;
    }
};