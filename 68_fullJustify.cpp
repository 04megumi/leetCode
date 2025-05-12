class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int p=0;
        while(p<words.size()) {
            int w = words[p].size(), l = p;
            string temp;
            while(p+1<words.size()&&w+words[p+1].size()+p+1-l<=maxWidth) {p++; w+=words[p].size();}
            if(p!=words.size()-1) {
                int blankWidth = !(p-l) ? maxWidth-w : (maxWidth-w)/(p-l);
                int extra = !(p-l) ? 0 : (maxWidth-w)%(p-l);
                for(int j=l;j<=p;j++) {
                    temp += words[j];
                    if(j==p && p!=l) break;
                    for(int z=0;z<blankWidth;z++) temp+=" ";
                    if(extra) {temp+=" ";extra--;}
                }
            } else {
                int blankWidth = (maxWidth-w-p+l);
                for(int j=l;j<=p;j++) {
                    temp += words[j];
                    if(j!=p) temp+=" ";
                    if(j==p) for(int z=0;z<blankWidth;z++) temp+=" ";
                }
            }
            ans.push_back(temp);
            p++;
        }
        return ans;
    }
};