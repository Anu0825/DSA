#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

// Optimized
/*we will use the binary search with the indices of the imaginary 1D array, ranging from 0 to (NxM)-1(total no. of elements in the
 1D array = NxM). When comparing elements, we will convert the index to the cell number and retrieve the element. Thus we can 
 apply binary search in the imaginary 1D array.*/

// If index = i, and no. of columns in the matrix = m, the index i corresponds to the cell with row = i / m and col = i % m. 
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix1(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    searchMatrix2(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

