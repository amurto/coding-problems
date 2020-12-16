#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> start(n), fin(n);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> fin[i];
        arr[i].first = start[i];
        arr[i].second = fin[i];
    }
    sort(start.begin(), start.end());
    sort(fin.begin(), fin.end());
    int res = INT_MAX;
    for (pair<int, int> p : arr)
    {
        int low = (lower_bound(fin.begin(), fin.end(), p.first) - fin.begin());
        int high = n - (upper_bound(start.begin(), start.end(), p.second) - start.begin());
        res = min(res, low + high);
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