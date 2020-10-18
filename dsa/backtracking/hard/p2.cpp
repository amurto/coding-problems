// Knights Tour

#include <bits/stdc++.h>
using namespace std;

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid(int row, int col, int n)
{
    if (row < 0 || row >= n || col < 0 || col >= n)
        return false;
    return true;
}

void printBoard(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void dfs(vector<vector<int>> &board, int row, int col, int vis, int n)
{
    if (vis == n * n)
    {
        board[row][col] = vis;
        printBoard(board);
        board[row][col] = 0;
    }
    board[row][col] = vis;
    for (int dir = 0; dir < 8; dir++)
        if (valid(row + dr[dir], col + dc[dir], n) && board[row + dr[dir]][col + dc[dir]] == 0)
            dfs(board, row + dr[dir], col + dc[dir], vis + 1, n);
    board[row][col] = 0;
}

int main()
{
    int n, row, col;
    cin >> n >> row >> col;
    vector<vector<int>> board(n, vector<int>(n, 0));
    dfs(board, row, col, 1, n);
    return 0;
}