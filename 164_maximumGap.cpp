class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        // 1. 基数排序（LSD：从个位到最高位）
        int maxVal = *max_element(nums.begin(), nums.end());
        // 每一位排序
        long long exp = 1;
        vector<int> buf(n);
        while (maxVal / exp > 0) {
            vector<int> count(10, 0); // 10 个桶（0~9）
            // 计数排序：统计每个桶的数量
            for (int i = 0; i < n; i++) {
                int digit = (nums[i] / exp) % 10;
                count[digit]++;
            }
            // 计数转换为前缀和 -> 变为稳定排序的“位置”
            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }
            // 倒序填桶（稳定排序关键步骤）
            for (int i = n - 1; i >= 0; i--) {
                int digit = (nums[i] / exp) % 10;
                buf[--count[digit]] = nums[i];
            }
            // 拷贝回原数组
            nums = buf;
            // 下一位（十位 -> 百位）
            exp *= 10;
        }
        int maxGap = 0;
        for (int i = 1; i < n; i++) maxGap = max(maxGap, nums[i] - nums[i - 1]);
        return maxGap;
    }
};