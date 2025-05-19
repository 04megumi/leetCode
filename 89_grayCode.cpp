class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = 1 << n;

        for (int i=0;i<size;i++) {
            int gray = i ^ (i >> 1);
            result.push_back(gray);
        }

        return result;
    }
};