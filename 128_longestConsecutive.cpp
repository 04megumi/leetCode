class Solution {
private:
    unordered_map<int,int> hash;
    int ans = 0;
public:
    int longestConsecutive(vector<int>& nums) {
        for(auto& num : nums) {
            if(hash.find(num)!=hash.end()) continue;
            int len = 1; hash[num] = 1;
            if(hash.find(num+1)!=hash.end()&&hash.find(num-1)!=hash.end()) {
                len = 1+hash[num-1]+hash[num+1];
                hash[num-hash[num-1]] = len, hash[num+hash[num+1]] = len;
            } else {
                if(hash.find(num+1)!=hash.end()) {
                    len = 1+hash[num+1];
                    hash[num] = len, hash[num+hash[num+1]] = len;
                }
                if(hash.find(num-1)!=hash.end()) {
                    len = 1+hash[num-1];
                    hash[num] = len, hash[num-hash[num-1]] = len;
                }
            }
            ans = max(ans,len);
        }
        return ans;
    }
};