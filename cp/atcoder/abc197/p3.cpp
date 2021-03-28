#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = INT_MAX;
int solve(vector<int> &arr, int cur, int x)
{
    if (cur == arr.size())
        return x;
    int res = inf, e = 0;
    for (int i = cur; i < arr.size(); i++)
    {
        e |= arr[i];
        res = min(res, solve(arr, i + 1, x ^ e));
    }
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
    cout << solve(arr, 0, 0) << "\n";
    return 0;
}