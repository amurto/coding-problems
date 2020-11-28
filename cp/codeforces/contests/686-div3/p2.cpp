#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int N = 2e5 + 1;
void solve()
{
    int n, v, MAX = 0;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    for (int i=0; i<n; i++) {
        if ((i-1 < 0 || arr[i-1].first != arr[i].first) && (i+1 >= n || arr[i+1].first != arr[i].first)) {
            cout << arr[i].second << "\n";
            return;
        }
    }
    cout << "-1\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}