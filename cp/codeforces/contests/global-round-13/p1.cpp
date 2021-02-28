#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, t, k;
    cin >> n >> q;
    vector<int> arr(n), cnt(2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> t >> k;
        if (t == 1)
        {
            k--;
            cnt[arr[k]]--;
            arr[k] ^= 1;
            cnt[arr[k]]++;
        }
        else
            cnt[1] >= k ? cout << "1\n" : cout << "0\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}