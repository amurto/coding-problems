#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
    {
        map<int, int> mp;
        int mx = 0, c = 0;
        for (int j = i; j < n; j += k)
        {
            mp[arr[j]]++;
            mx = max(mx, mp[arr[j]]);
            c++;
        }
        res += c - mx;
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