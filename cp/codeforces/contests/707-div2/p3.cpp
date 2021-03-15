#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e6 + 5;
vector<pair<int, int>> ids[N];

bool safe(int x, int y, int z, int w)
{
    return x != z && z != w && y != z && y != w;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int sum = arr[i] + arr[j];
            if (!ids[sum].empty() && safe(ids[sum][0].first, ids[sum][0].second, j, i))
            {
                cout << "YES\n";
                cout << ids[sum][0].first + 1 << " " << ids[sum][0].second + 1 << " ";
                cout << j + 1 << " " << i + 1 << " ";
                return;
            }
            if (ids[sum].empty())
                ids[sum].pb({j, i});
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}