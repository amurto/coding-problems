// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=691
// 750 - 8 Queens Chess Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sol;
bool valid(vector<vector<bool>> &board, int row, int col)
{
    for (int i = row - 1, off = 1; i >= 0; i--, off++)
    {
        if (board[i][col])
            return false;
        if (col - off >= 0 && board[i][col - off])
            return false;
        if (col + off < 8 && board[i][col + off])
            return false;
    }
    return true;
}

void display(vector<vector<bool>> &board)
{
    vector<int> res;
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (board[i][j])
            {
                res.pb(i + 1);
                break;
            }
        }
    }
    sol.pb(res);
}

void dfs(vector<vector<bool>> &board, int row, int si, int sj)
{
    if (row == 8)
    {
        if (board[si][sj])
        {
            display(board);
            return;
        }
        return;
    }
    for (int col = 0; col < 8; col++)
    {
        if (valid(board, row, col))
        {
            board[row][col] = true;
            dfs(board, row + 1, si, sj);
            board[row][col] = false;
        }
    }
}

void solveNQueens()
{
    sol.clear();
    int si, sj;
    cin >> si >> sj;
    si--;
    sj--;
    vector<vector<bool>> board(8, vector<bool>(8));
    dfs(board, 0, si, sj);
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl
         << endl;
    for (int j = 0; j < sol.size(); j++)
    {
        cout << setw(2) << j + 1 << "      " << sol[j][0] << " " << sol[j][1] << " " << sol[j][2] << " " << sol[j][3] << " " << sol[j][4] << " " << sol[j][5] << " " << sol[j][6] << " " << sol[j][7] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solveNQueens();
        if (tc - t)
            cout << endl;
    }
    return 0;
}
