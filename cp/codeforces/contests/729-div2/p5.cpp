#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> seq;
    iota(arr.begin(), arr.end(), 1);
    do
    {
        vector<int> tmp = arr;
        seq.pb(tmp);
    } while (next_permutation(arr.begin(), arr.end()));
    sort(seq.begin(), seq.end());
    int sz = seq.size();
    vector<int> inv(sz);
    for (int id = 0; id < sz; id++)
    {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                inv[id] += (seq[id][i] > seq[id][j]);
    }
    int res = 0;
    for (int i = 0; i < sz; i++)
        for (int j = i + 1; j < sz; j++)
            res += (inv[i] > inv[j]);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}