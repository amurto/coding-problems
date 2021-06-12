// https://codeforces.com/contest/1363/problem/D
// Guess The Maximums

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(vector<int> arr)
{
    cout << "? " << arr.size() << " ";
    for (int a : arr)
        cout << a << " ";
    cout << endl;
    int x;
    cin >> x;
    if (x == -1)
        exit(0);
    return x;
}

void solve()
{
    int n, k, c, v;
    cin >> n >> k;
    vector<vector<int>> arr(k + 1);
    vector<int> ids(n + 1), seq, res(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            cin >> v;
            ids[v] = i;
            arr[i].pb(v);
            seq.pb(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (ids[i] == 0)
            seq.pb(i);
    vector<int> all_ids;
    for (int i = 1; i <= n; i++)
        all_ids.pb(i);
    int mx = query(all_ids);
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        vector<int> tmp = vector<int>(seq.begin(), seq.begin() + mid + 1);
        int q = query(tmp);
        if (q == mx)
            high = mid;
        else
            low = mid + 1;
    }
    int j = seq[low];
    for (int i = 1; i <= k; i++)
        if (i != ids[j])
            res[i] = mx;
    if (ids[j] > 0)
    {
        vector<int> tmp;
        vector<bool> u(n + 1);
        for (int i : arr[ids[j]])
            u[i] = true;
        for (int i = 1; i <= n; i++)
            if (!u[i])
                tmp.pb(i);
        res[ids[j]] = query(tmp);
    }
    cout << "! ";
    for (int i = 1; i <= k; i++)
        cout << res[i] << " ";
    cout << endl;
    string ans;
    cin >> ans;
    if (ans == "Incorrect")
        exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}