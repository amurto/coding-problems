#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, v;
    cin >> n;
    vector<int> p(2);
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        p[v % 2]++;
    }
    return min(p[0], p[1]);
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