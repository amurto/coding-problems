#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int>> piii;
#define pb push_back

ll solve()
{
    int n, r, c;
    ll res = 0;
    cin >> n >> r >> c;
    vector<int> visR(r + 1), visC(c + 1);
    vector<piii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
    sort(arr.rbegin(), arr.rend());
    for (piii p : arr)
    {
        int x = p.second.first, y = p.second.second;
        if (visR[x] < 2 && visC[y] < 2)
        {
            visR[x]++;
            visC[y]++;
            res += p.first;
            cout << p.first << "\n";
        }
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