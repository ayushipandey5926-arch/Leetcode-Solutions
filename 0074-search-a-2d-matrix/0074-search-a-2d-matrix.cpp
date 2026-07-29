class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix.empty() ? 0 : matrix[0].size();

        int total_elements = rows*cols;
        int low = 0;
        int high = total_elements - 1;
        while(low<=high) {
        int mid =  low + (high-low)/2;
        int m = mid/cols;
        int n = mid%cols;

        if(matrix[m][n] == target){return true;}
        else if(matrix[m][n] < target) {low = mid+1;}
        else {high = mid-1;} 
        }       

        return false;
    }
};