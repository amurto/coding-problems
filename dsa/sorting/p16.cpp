// https://leetcode.com/problems/search-a-2d-matrix-ii/
// Search a 2D Matrix II

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() == 0)
        return false;
    int n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;
    while (i >= 0 && i < n && j >= 0 && j < m && matrix[i][j] != target)
        if (target < matrix[i][j])
            j--;
        else
            i++;
    if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] != target)
        return false;
    return true;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 5;
    searchMatrix(matrix, target) ? cout << "true\n" : cout << "false\n";
    return 0;
}