class Solution {
public:
    bool binarySearch(vector<int>& arr, int l, int r, int x){
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return true;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
    return false;
    }
    bool searchMatrix_Method1(vector<vector<int>>& matrix, int target) {
        /*
            Time complexity of this solution is O(m * Log(n)).
        */
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++){
            if(target >= matrix[i][0] && target<=matrix[i][n-1]){
                if(target == matrix[i][0] || target == matrix[i][n-1] || binarySearch(matrix[i],0,n-1,target))
                    return true;
            }
        }
        return false;
    }
    bool searchMatrix_Method2(vector<vector<int>>& matrix, int target){
        /*
            Time Complexity of this solution is O(m+n)
        */
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m-1,j=0;
        while(i>=0 && j<n){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return searchMatrix_Method1(matrix, target);
        return searchMatrix_Method2(matrix, target);
    }
};