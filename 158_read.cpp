/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    char buf4[4];  // 缓冲区
    int l = 0;     // 当前读取指针
    int r = 0;     // 缓冲有效长度
public:
    int read(char *buf, int n) {
        int total = 0;
        while (total < n) {
            if (l == r) {
                r = read4(buf4); // 重新填充缓存
                l = 0;
                if (r == 0) break; // 文件读完
            }
            while (l < r && total < n) {
                buf[total++] = buf4[l++];
            }
        }
        return total;
    }
};