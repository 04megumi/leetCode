class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        vector<int> used1(52, 0); // 窗口52个字母出现次数
        vector<int> used2(52, 0); // t中字母出现次数
        for(int i=0;i<t.size();i++) {
            if(t[i]>='a' && t[i]<='z') {
                used2[t[i]-'a'+26]++;
            } else {
                used2[t[i]-'A']++;
            }
        }
        string ans = ""; int pre = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i]>='a' && s[i]<='z') {
                used1[s[i]-'a'+26]++;
            } else {
                used1[s[i]-'A']++;
            }
            if(contains(used1,used2)) {
                while(pre<=i && contains(used1,used2)) {
                    if(ans=="" || ans.size()>i-pre+1) ans = s.substr(pre,i-pre+1);
                    if(s[pre]>='a' && s[pre]<='z') {
                        used1[s[pre++]-'a'+26]--;
                    } else {
                        used1[s[pre++]-'A']--;
                    }
                }
            } else {
                int index = (s[pre]>='a' && s[pre]<='z') ? s[pre]-'a'+26 : s[pre]-'A';
                while(pre<=i && isExtra(used1,used2,index)) {
                    if(s[pre]>='a' && s[pre]<='z') {
                        used1[s[pre++]-'a'+26]--;
                    } else {
                        used1[s[pre++]-'A']--;
                    }
                    index = (s[pre]>='a' && s[pre]<='z') ? s[pre]-'a'+26 : s[pre]-'A';
                }
            }
        }
        return ans;
    }
    bool contains(vector<int>& used1, vector<int>& used2) {
        for(int i=0;i<52;i++) if(used2[i] && used2[i]>used1[i]) return false;
        return true;
    }
    bool isExtra(vector<int>& used1, vector<int>& used2, int pre) {
        return used1[pre] > used2[pre];
    }
};