class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()/2;i++) {
            // 换下边和左边
            for(int j=0;j<matrix.size()-2*i;j++) swap(matrix,i+j,matrix.size()-1-i,i,i+j);
            // 对换下边
            for(int j=i+1;j<matrix.size()/2;j++) swap(matrix,j,matrix.size()-i-1,matrix.size()-1-j,matrix.size()-i-1);
            // 换下边和上边
            for(int j=0;j<matrix.size()-2*i-1;j++) swap(matrix,i+1+j,matrix.size()-1-i,i+1+j,i);
            // 换下边和右边
            for(int j=0;j<matrix.size()-2*i-2;j++) swap(matrix,i+1+j,matrix.size()-1-i,matrix.size()-1-i,i+1+j);
            // 对换下边
            for(int j=i+1;j<matrix.size()/2;j++) swap(matrix,j,matrix.size()-i-1,matrix.size()-1-j,matrix.size()-i-1);
        }
    }
    void swap(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2) {
        int temp = matrix[y1][x1];
        matrix[y1][x1] = matrix[y2][x2];
        matrix[y2][x2] = temp;
    }
};