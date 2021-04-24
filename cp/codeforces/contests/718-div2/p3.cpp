#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool valid(vector<vector<int>> &mat, int i, int j, int n)
{
    if (i < 0 || i >= n || j < 0 || j >= n || mat[i][j] > 0)
        return false;
    return true;
}

void display(vector<vector<int>> &mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // as soon as you can turn left, do it
    for (int i = 0; i < n; i++)
    {
        int x = arr[i] - 1, r = i, c = i;
        mat[i][i] = arr[i];
        while (x > 0)
        {
            // try left
            if (valid(mat, r, c - 1, n))
            {
                c -= 1;
                mat[r][c] = arr[i];
            }
            // else down
            else if (valid(mat, r + 1, c, n))
            {
                r += 1;
                mat[r][c] = arr[i];
            }
            else
            {
                cout << "-1\n";
                return;
            }
            x--;
        }
    }
    display(mat, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}