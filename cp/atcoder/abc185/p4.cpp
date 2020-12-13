#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve() {
    int n, m;
    cin >> n >> m;
    if (m==0)
        return 1;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int k = INT_MAX;
    if (arr[0] > 1)
        k = arr[0] - 1;
    for (int i = 1; i < m; i++)
    {
        if (arr[i] - arr[i - 1] == 1)
            continue;
        k = min(k, arr[i] - arr[i - 1] - 1);
    }
    if (arr[m - 1] < n)
        k = min(k, n - arr[m - 1]);
    int op = 0, last = 0, diff = 0;
    for (int i = 0; i < m; i++)
    {
        diff = arr[i] - last - 1;
        op += (diff / k);
        if (diff % k > 0)
            op++;
        last = arr[i];
    }
    diff = n - last;
    op += (diff / k);
    if (diff % k > 0)
        op++;
    return op;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}