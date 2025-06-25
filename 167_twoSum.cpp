class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left + 1, right + 1};
            // 右边都拉满了还小 左边需要增加
            else if (sum < target) left++;
            // 同理
            else right--;
        }
        return {};
    }
};