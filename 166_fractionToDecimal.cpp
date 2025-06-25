class Solution {
private:
    int computeGCD(int a, int b) {
        return b ? computeGCD(b, a % b) : a;
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string ans;
        // 符号判断
        if ((numerator < 0) ^ (denominator < 0)) ans += "-";
        // 转为正数
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        // 整数部分
        ans += to_string(n / d);
        n %= d;
        if (n == 0) return ans;
        ans += '.';
        // 小数部分，循环节不一定在首位所以需要记录位置
        unordered_map<long long, int> pos;
        string frac;
        for (; n; n %= d) {
            if (pos.count(n)) {
                frac.insert(pos[n], "(");
                frac += ")";
                break;
            }
            pos[n] = frac.size();
            n *= 10;
            frac += to_string(n / d);
        }
        return ans + frac;
    }
};