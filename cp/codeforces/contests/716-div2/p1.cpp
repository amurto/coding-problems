#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e4 + 5;
vector<bool> vis(N);
bool solve()
{
    int n,x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int a:arr)
        if (!vis[a])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i * i <= N; i++)
        vis[i * i] = true;
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "NO\n" : cout << "YES\n";
    return 0;
}