// https://codeforces.com/contest/378/problem/B
// Semifinals

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(2 * n);
    for (int i = 0, j = 0; i < n; i++, j += 2)
    {
        cin >> arr[j].first;
        arr[j].second = 0;
        cin >> arr[j + 1].first;
        arr[j + 1].second = 1;
    }
    sort(arr.begin(), arr.end());
    vector<int> cnt(2);
    vector<vector<int>> str(2);
    for (int i = 0; i < 2 * n; i++)
    {
        int cur = arr[i].second;
        cnt[cur]++;
        if (cnt[cur] <= n / 2)
        {
            str[cur].pb(1);
            continue;
        }
        if (i < n)
            str[cur].pb(1);
        else
            str[cur].pb(0);
    }
    for (int j = 0; j < 2; j++)
    {
        for (int v : str[j])
            cout << v;
        cout << "\n";
    }
    return 0;
}