class Solution {
public:
    string intToRoman(int num) {
        vector<string> maps = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> keys = {1,4,5,9};
        string ans;
        for(int i=12;i>=0;i--) {
            int key = int(pow(10,i/4))*keys[i%4];
            for(int j=0;j<num/key;j++) ans += maps[i];
            num %= key;
        }
        return ans;
    }
};
