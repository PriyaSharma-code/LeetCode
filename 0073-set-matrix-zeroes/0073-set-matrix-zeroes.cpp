class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;

        int i,j;
        for( i=0;i<matrix.size();i++){
            for(j=0;j<matrix[0].size();j++){
                    if(matrix[i][j]==0){
                        matrix[i][0] =0;
                    
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{ col0 = 0;}
                }
            }
        }
        for( i=1;i<matrix.size();i++){
            for(j=1;j<matrix[0].size();j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if(matrix[0][0] == 0){
            for(j = 0; j <matrix[0].size() ; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 ==0){
            for(i = 0 ; i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
     }
};