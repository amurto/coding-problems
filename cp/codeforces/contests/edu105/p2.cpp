#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(vector<int> arr, vector<vector<int>> &mat, int n)
{
    if (mat[0][0] == 1)
    {
        arr[0]--;
        arr[3]--;
    }
    if (mat[0][n - 1] == 1)
    {
        arr[0]--;
        arr[1]--;
    }
    if (mat[n - 1][n - 1] == 1)
    {
        arr[1]--;
        arr[2]--;
    }
    if (mat[n - 1][0] == 1)
    {
        arr[2]--;
        arr[3]--;
    }
    for (int a : arr)
        if (a < 0 || a > n - 2)
            return false;
    return true;
}

bool recur(vector<int> &arr, vector<vector<int>> &mat, vector<pair<int, int>> &st, int cur, int n)
{
    if (cur == 4)
        return check(arr, mat, n);
    if (recur(arr, mat, st, cur + 1, n))
        return true;
    mat[st[cur].first][st[cur].second] = 1;
    bool res = recur(arr, mat, st, cur + 1, n);
    mat[st[cur].first][st[cur].second] = 0;
    return res;
}

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(4);
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    vector<vector<int>> mat(n, vector<int>(n));
    vector<pair<int, int>> st = {{0, 0}, {0, n - 1}, {n - 1, n - 1}, {n - 1, 0}};
    return recur(arr, mat, st, 0, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}