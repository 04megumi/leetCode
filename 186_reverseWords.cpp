class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size(), remind = 0;
        reverse(s.begin(),s.end());
        for(int i=0;i<=n;i++) {
            if(i==n||s[i]==' ') {
                reverse(s.begin()+remind,s.begin()+i);
                remind = i+1;
            }
        }
    }
};