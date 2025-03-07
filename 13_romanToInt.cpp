#include <iostream>
#include "math.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, unsigned char> hashMap = 
        {{'I',0},{'V', 1},{'X',2},{'L',3},{'C',4},{'D',5},{'M',6}};
        int ans = 0;

        for(int i=0;i<s.size()-1;i++){
            if(hashMap[s[i]]>=hashMap[s[i+1]]) {
                ans += pow(10,hashMap[s[i]]/2)*(hashMap[s[i]]%2?5:1);
            } else {
                ans += pow(10,hashMap[s[i+1]]/2)*(hashMap[s[i+1]]%2?5:1);
                ans -= pow(10,hashMap[s[i]]/2)*(hashMap[s[i]]%2?5:1);
                i++;
                if(i==s.size()-1) return ans;
            }
        }

        ans += pow(10,hashMap[s[s.size()-1]]/2)*(hashMap[s[s.size()-1]]%2?5:1);
        return ans;
    }
};

int main() {

    string s = "LVIII";
    Solution solution;
    cout << solution.romanToInt(s) << endl;

    return 0;
}
