#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nc2(int n)
{
    return n * 1ll * (n + 1) / 2;
}

ll solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), cnt(2);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
        cnt[arr[i]]++;
    int mn = cnt[1];
    for (int i = k; i < n; i++)
    {
        cnt[arr[i - k]]--;
        cnt[arr[i]]++;
        mn = min(mn, cnt[1]);
    }
    int ones = count(arr.begin(), arr.end(), 1);
    return nc2(mn) + ones - mn;
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