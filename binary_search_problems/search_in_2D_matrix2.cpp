/*Optimized Approach: Cell (0, m-1): Assume we are starting traversal from (0, m-1) and we are searching for 14. Now, in this case, 
the row is in decreasing order and the column is in increasing order. Therefore, if we start traversal from (0, m-1), 
in the following way, we can easily determine how we should move.
If matrix[0][m-1] > target: We should move row-wise.
If matrix[0][m-1] < target: We need bigger elements and so we should move column-wise.
*/
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchElement1(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        bool flag =  binarySearch(matrix[i], target);
        if (flag) return true;
    }
    return false;
}

// optimized
bool searchElement2(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchElement1(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    searchElement2(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}



