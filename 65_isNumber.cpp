class Solution {
public:
    bool isNumber(string s) {
        bool seenDot = false, seenE = false, seenDigit = false, digitAfterE = true;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
                if (seenE) digitAfterE = true;
            } else if (c == '+' || c == '-') {
                // '+' or '-' must be at start or after 'e' or 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
                if (i == s.size() - 1) return false;
            } else if (c == '.') {
                // dot must not appear after e, and only once
                if (seenDot || seenE) return false;
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                // e must only appear once and after at least one digit
                if (seenE || !seenDigit || i == s.size() - 1) return false;
                seenE = true;
                digitAfterE = false; // must have digit after e
            } else {
                // any other character is invalid
                return false;
            }
        }
        return seenDigit && digitAfterE;
    }
};