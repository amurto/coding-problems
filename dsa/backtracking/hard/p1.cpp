// N-queen

#include <bits/stdc++.h>
using namespace std;

bool valid(vector<string> &board, int n, int row, int col)
{
    for (int i = row - 1, off = 1; i >= 0; i--, off++)
    {
        if (board[i][col] == 'Q')
            return false;
        if (col - off >= 0 && board[i][col - off] == 'Q')
            return false;
        if (col + off < n && board[i][col + off] == 'Q')
            return false;
    }
    return true;
}

void dfs(vector<vector<string>> &ans, vector<string> &board, int &n, int row)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < board[row].length(); col++)
    {
        if (valid(board, n, row, col))
        {
            board[row][col] = 'Q';
            dfs(ans, board, n, row + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    string dots(n, '.');
    vector<string> board(n, dots);
    vector<vector<string>> ans;
    dfs(ans, board, n, 0);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << "\n";
        cout << "\n";
    }
    return 0;
}