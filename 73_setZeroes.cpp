class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++) for(int j=0;j<matrix[0].size();j++) if(!matrix[i][j]) matrix[i][j] = 21473647;
        for(int i=0;i<matrix.size();i++) for(int j=0;j<matrix[0].size();j++) if(matrix[i][j]==21473647) modify(matrix,i,j);
        for(int i=0;i<matrix.size();i++) for(int j=0;j<matrix[0].size();j++) if(matrix[i][j]==21473647) matrix[i][j] = 0;
    }
    void modify(vector<vector<int>>& matrix, int I, int J) {
        for(int j=0;j<matrix[0].size();j++) if(matrix[I][j]!=21473647) matrix[I][j]=0;
        for(int i=0;i<matrix.size();i++) if(matrix[i][J]!=21473647) matrix[i][J]=0;
    }
};