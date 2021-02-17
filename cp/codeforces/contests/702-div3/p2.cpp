#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 0, cur = 0;
    cin >> n;
    vector<int> arr(n), tr(3);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        tr[arr[i] % 3]++;
    }
    int req = n / 3;
    while (min({tr[0], tr[1], tr[2]}) != max({tr[0], tr[1], tr[2]}))
    {
        int nxt = (cur + 1) % 3;
        if (tr[cur] > req)
        {
            tr[nxt] += tr[cur] - req;
            res += tr[cur] - req;
            tr[cur] = req;
        }
        cur = nxt;
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