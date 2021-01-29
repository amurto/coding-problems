#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<vector<int>> p(100, vector<int>(10));

void init()
{
    for (int i = 1; i < 100; i++)
    {
        int tmp = i;
        while (tmp > 0)
        {
            p[i][tmp % 10] = 1;
            tmp /= 10;
        }
    }
}
void solve()
{
    int n, v, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (v >= 100)
            cout << "YES\n";
        else
        {
            int tmp = v % d;
            bool f = false;
            while (tmp <= v)
            {
                if (p[tmp][d])
                {
                    cout << "YES\n";
                    f = true;
                    break;
                }
                tmp += d;
            }
            if (!f)
                cout << "NO\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}