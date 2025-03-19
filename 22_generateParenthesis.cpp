class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp, stack;
        n *= 2;
        dfs(n,0,temp,stack,ans);
        return ans;
    }
    void dfs(const int& n, int cur, string& temp, string&stack, vector<string>&ans) {
        if(cur==n) {
            ans.push_back(temp);
            return;
        }
        string temp1 = temp, stack1 = stack;
        if(stack.size()==(n-cur)) {
            for(int i=stack.size()-1;i>=0;i--) temp += ')';
            ans.push_back(temp);
            return;
        }
        if(stack.size()) {
            temp += ')';
            stack.pop_back();
            dfs(n,cur+1,temp,stack,ans);
            temp = temp1, stack = stack1;
        }
        temp += '(';
        stack += '(';
        dfs(n,cur+1,temp,stack,ans);
        temp = temp1, stack = stack1;
    }
};
