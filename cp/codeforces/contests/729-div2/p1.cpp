#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n), cnt(2);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
        cnt[arr[i] & 1]++;
    }
    return cnt[0] == cnt[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}