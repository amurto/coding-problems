// https://codeforces.com/contest/1285/problem/D
// Dr. Evil Underscores

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int b = 31;
int dfs(vector<int> &arr, int l, int r, int k)
{
    if (l == r || k < 0)
        return 0;
    int low = l, high = r, id = -1, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (((arr[mid] >> k) & 1) == 0)
        {
            id = max(id, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (id == -1 || id == r)
        res = dfs(arr, l, r, k - 1);
    else
        res = (1 << k) | min(dfs(arr, l, id, k - 1), dfs(arr, id + 1, r, k - 1));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << dfs(arr, 0, n - 1, b) << "\n";
    return 0;
}