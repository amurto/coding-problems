#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int m = i;
        ll sf = 0;
        sum += arr[i];
        bool possible = true;
        for (int j = i + 1; j < n; j++)
        {
            if (sf + arr[j] > sum)
            {
                possible = false;
                break;
            }
            if (sf > 0)
                m++;
            sf += arr[j];
            if (sf == sum)
                sf = 0;
        }
        if (possible && sf == 0)
            res = min(res, m);
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