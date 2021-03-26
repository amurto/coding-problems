#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 55;
int dp[N][N][N];

int query(int x, int l, int r)
{
    int i;
    vector<int> seq = {x, l, r};
    sort(seq.begin(), seq.end());
    if (dp[seq[0]][seq[1]][seq[2]] == -1)
    {
        cout << x << " " << l << " " << r << "\n";
        fflush(stdout);
        cin >> dp[seq[0]][seq[1]][seq[2]];
        if (dp[seq[0]][seq[1]][seq[2]] == -1)
            exit(0);
    }
    return dp[seq[0]][seq[1]][seq[2]];
}

void solve(int n)
{
    vector<int> arr(n);
    memset(dp, -1, sizeof(dp));
    iota(arr.begin(), arr.end(), 1);
    int x = 1, y = 2, v;
    for (int i = 2; i < n; i++)
    {
        int cur = arr[i];
        int idx = query(cur, x, y);
        if (idx == x)
            swap(cur, x);
        else if (idx == y)
            swap(cur, y);
    }
    auto cmp = [&](int &i1, int &i2) {
        if (i1 == x)
            return true;
        if (i2 == x)
            return false;
        int i = query(x, i1, i2);
        return i1 == i;
    };
    sort(arr.begin(), arr.end(), cmp);
    for (int a : arr)
        cout << a << " ";
    cout << "\n";
    fflush(stdout);
    cin >> v;
    if (v == -1)
        exit(0);
}

int main()
{
    int t, n, q;
    cin >> t >> n >> q;
    while (t-- > 0)
        solve(n);
    return 0;
}