#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<piii> op;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    int add = 1e6;
    for (int i = 0; i < n; i++)
        arr[i] = add;
    op.pb({2, {n, 1}});
    op.pb({1, {n, add}});
    op.pb({2, {1, 1}});
    arr[0] = 0;
    for (int i = 1, cur = 2; i < n - 1; i++, cur += 2)
    {
        int h = (arr[i] - cur) / 2;
        op.pb({2, {i + 1, h}});
        arr[i] %= h;
    }
    cout << op.size() << "\n";
    for (piii p : op)
        cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}