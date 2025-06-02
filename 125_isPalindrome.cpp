class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l<r) {
            while(!(s[l]>='a'&&s[l]<='z'||s[l]>='A'&&s[l]<='Z'||s[l]>='0'&&s[l]<='9')&&l<r) l++;
            while(!(s[r]>='a'&&s[r]<='z'||s[r]>='A'&&s[r]<='Z'||s[r]>='0'&&s[r]<='9')&&l<r) r--;
            if(l>=r) break;
            if(s[l]>='0'&&s[l]<='9') {
                if(s[l]!=s[r]) return false;
            } else {
                if(s[l]!=s[r]&&s[l]!=s[r]+'A'-'a'&&s[l]+'A'-'a'!=s[r]) return false;
            }
            l++, r--;
        }
        return true;
    }
};