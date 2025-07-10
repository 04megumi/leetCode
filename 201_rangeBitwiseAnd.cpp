class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int mask = 1 << i;
            // 检查当前位在 left 和 right 是否相同
            if ((left & mask) != (right & mask)) {
                // 一旦某位不同，后面的位全部都不能保留（因为中间一定会有 0）
                break;
            }
            // 如果该位在 left 和 right 都是 1，保留
            if (left & mask) {
                ans |= mask;
            }
        }
        return ans;
    }
};