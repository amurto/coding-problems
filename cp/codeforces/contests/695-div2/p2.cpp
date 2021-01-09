#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bad(vector<int> &arr, int n, int i)
{
    if (i - 1 < 0 || i + 1 >= n)
        return 0;
    if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
        return 1;
    return 0;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    vector<bool> h(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n <= 2)
        return 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            h[i] = true;
        else if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
            v[i] = true;
        if (h[i] || v[i])
            res++;
    }
    int og = res, mx = 0;
    if (h[1] || v[1])
        res = min(res, og - 1);
    if (h[n - 2] || v[n - 2])
        res = min(res, og - 1);
    for (int i = 1; i < n - 1; i++)
    {
        int inc = h[i] + v[i] + h[i - 1] + v[i - 1] + h[i + 1] + v[i + 1];

        int c1 = 0, c2 = 0, tmp = arr[i];
        arr[i] = arr[i - 1];
        c1 = bad(arr, n, i) + bad(arr, n, i - 1) + bad(arr, n, i + 1);
        arr[i] = arr[i + 1];
        c2 = bad(arr, n, i) + bad(arr, n, i - 1) + bad(arr, n, i + 1);
        arr[i] = tmp;
        res = min({res, og - inc + c1, og - inc + c2});
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}