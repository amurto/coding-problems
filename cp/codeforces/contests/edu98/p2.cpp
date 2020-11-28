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
        ll MAX = 0, sum = 0;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            MAX = max(MAX, arr[i]);
            sum += arr[i];
        }
        ll target = sum;
        if (sum < MAX * (n - 1))
            target = MAX * (n - 1);
        if (target % (n - 1) != 0)
            target -= target % (n - 1) + n - 1;
        cout << target - sum << "\n";
    }
    return 0;
}