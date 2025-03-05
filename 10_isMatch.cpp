class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s,p,0,0);
    }

    bool dfs (string s, string p, int cs, int cp) {
        // 终点
        if(cs==s.size()) {
            if(cp+2>=p.size())
                return cp==p.size()||cp+2==p.size()&&p[cp+1]=='*'||cp+1==p.size()&&p[cp]=='*';
            if(p[cp]=='*') return dfs(s,p,cs,cp+1);
            if(p[cp+1]=='*') return dfs(s,p,cs,cp+2);
            return false;
        }
        // 匹配
        if((p[cp]==s[cs]||p[cp]=='.') && dfs(s,p,cs+1,cp+1)) return true;
        if(p[cp]=='*') {
            for(int i=cs;i<s.size();i++) {
                if(p[cp-1]!='.' && p[cp-1]!=s[i]) break;
                if(dfs(s,p,i+1,cp+1)) return true;
            }
        }
        // 跳过
        if((p[cp]==s[cs]||p[cp]=='.') && cp+1<p.size() && p[cp+1]=='*' && dfs(s,p,cs+1,cp+2)) return true;
        if(cp+1<p.size() && p[cp+1]=='*' && dfs(s,p,cs,cp+2)) return true;
        // 失败
        return false;
    }
};
