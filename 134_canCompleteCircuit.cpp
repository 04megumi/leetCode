class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int s = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) {
                // 如果不成立, 结果一定属于下一个到结束这个区间
                start = i + 1;
                curr = 0;
            }
        }
        // 如果total < 0, 必然无解
        return total < 0 ? -1 : start;
    }
};