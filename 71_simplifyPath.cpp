class Solution {
public:
    string simplifyPath(string path) {
        vector<string> temp;
        int p = 0;
        while(p<path.size()) {
            if(p+1==path.size()) break;
            if(path[p+1]=='/') {
                p++;
                continue;
            }
            int j=p+1;
            string t = "/";
            while(j<path.size()&&path[j]!='/') {
                t+=path[j];
                j++;
            }
            if(t!="/.."&&t!="/.") temp.push_back(t);
            if(t=="/.." && temp.size()) temp.pop_back();
            p=j;
        }
        string ans;
        for(int i=0;i<temp.size();i++) ans+=temp[i];
        return temp.size()? ans : "/";
    }
};

