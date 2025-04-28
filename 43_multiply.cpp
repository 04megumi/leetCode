class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() > num2.size()) return multiply(num2, num1);
            
        string ans(num1.size() + num2.size(), '0');
            
        for(int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0') + carry + (ans[i + j + 1] - '0');
                carry = mul / 10;
                ans[i + j + 1] = (mul % 10) + '0';
            }
            ans[i] += carry;
        }
            
        int start = 0;
        while(start < ans.size() && ans[start] == '0') start++;
        return start == ans.size() ? "0" : ans.substr(start);
    }
};