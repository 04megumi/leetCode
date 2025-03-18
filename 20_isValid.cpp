class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;
        vector<char> stack(s.size()>>1);
        int top = 0;
        for(int i=0;i<s.size();i++) {
            char cur = s[i];
            if(!top&&(cur==')'||cur==']'||cur=='}')) return false;
            if(!top) {stack[top++]=cur; continue;}
            char pre = stack[top-1];
            if((cur==')'&&pre=='(')||(cur==']'&&pre=='[')||(cur=='}'&&pre=='{')) {
                top--;
            } else {
                if(top==stack.size()) return false;
                stack[top++] = cur;
            }
        }
        return !top;
    }
};
