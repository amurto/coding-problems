#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        ll res = 0;
        vector<ll> arr(n), score(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (ll i = 0; i < n; i++)
        {
            if (i + arr[i] < n)
                score[i + arr[i]] = max(score[i + arr[i]], score[i] + arr[i]);
            res = max(res, score[i] + arr[i]);
        }
        cout << res << "\n";
    }
    return 0;
}