#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k, cur = 0, fol = 1;
    cin >> n >> k;
    string res = "";
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            res.pb('a');
        cout << res << "\n";
        return;
    }
    res.pb('a');
    for (int i = 1; i < n; i += 2)
    {
        res.pb(char(cur + 'a'));
        res.pb(char(fol + 'a'));
        fol++;
        if (fol == k)
        {
            cur++;
            res.pb(char(cur + 'a'));
            i++;
            if (cur == k - 1)
            {
                cur = 0;
                res.pb('a');
                i++;
            }
            fol = cur + 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i];
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}