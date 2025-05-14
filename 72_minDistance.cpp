/**     ros, horse
 * 
 *      |       | ""  | "r"  | "ro" | "ros" |
 *      |""     |  0  |  1   |   2  |   3   |
 *      |"h"    |  1  |  1   |      |       |
 *      |"ho"   |  2  |      |      |       |
 *      |"hor"  |  3  |      |      |       |
 *      |"hors" |  4  |      |      |       |
 *      |"horse"|  5  |      |      |       |
 * 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        dp[0][0] = 0;
        for(int i=0;i<dp.size();i++) {
            for(int j=0;j<dp[0].size();j++) {
                if(!i) {
                    dp[i][j] = j;
                    continue; 
                }
                if(!j) {
                    dp[i][j] = i;
                    continue; 
                }
                int a = dp[i-1][j]+1;
                int b = dp[i][j-1]+1;
                int c = dp[i-1][j-1]+1;
                if(word1[i-1]==word2[j-1]) c--;
                dp[i][j] = min(min(a,b),min(a,c));
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};