#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string op[3] = {"AND", "OR", "XOR"};
int query(int c, int i, int j)
{
    cout << op[c] << " " << i << " " << j << "\n";
    fflush(stdout);
    int x;
    cin >> x;
    if (x == -1)
        exit(0);
    return x;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<int>> st(n);
    arr[1] = -1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = query(2, 1, i);
        st[arr[i]].pb(i);
    }
    if (!st[0].empty())
        arr[1] = query(0, 1, st[0][0]);
    for (int i = 1; arr[1] == -1 && i < n; i++)
    {
        if (st[i].size() >= 2)
        {
            int x = query(0, st[i][0], st[i][1]);
            arr[1] = arr[st[i][0]] ^ x;
        }
        else
        {
            if (!st[i].empty() && !st[n - i - 1].empty())
            {
                int x1 = query(0, 1, st[i][0]), x2 = query(0, 1, st[n - i - 1][0]);
                arr[1] = x1 | x2;
            }
        }
    }
    for (int i = 2; i <= n; i++)
        arr[i] ^= arr[1];
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    fflush(stdout);
}

int main()
{
    solve();
    return 0;
}