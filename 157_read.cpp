/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ret = 0;
        char temp[4];

        while(ret < n) {
            int count = read4(temp);
            for(int i=0;i<count&&ret<n;i++) buf[ret++] = temp[i];
            if(count<4) break;
        }

        return ret;
    }
};