#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> f1(26), f2(26);
    for (int i = 0; i < n; i++)
    {
        f1[a[i] - 'a']++;
        f2[b[i] - 'a']++;
    }

    for (int c = 25; c >= 0; c--)
    {
        if (f1[c] > f2[c])
            return false;
        if (f2[c] == 0)
            continue;
        int need = f2[c] - f1[c];
        f1[c] = 0;
        if (need % k > 0)
            return false;
        for (int j = c - 1; j >= 0; j--)
        {
            while (f1[j] >= k && need > 0)
            {
                f1[j] -= k;
                need -= k;
            }
        }
        if (need > 0)
            return false;
        f2[c] = need;
    }
    return true;
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
        solve() ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}