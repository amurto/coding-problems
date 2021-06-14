#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(vector<int> arr)
{
    cout << "? ";
    for (int a : arr)
        cout << a << " ";
    cout << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    if (n % k == 0)
    {
        for (int i = 0; i < n; i += k)
        {
            vector<int> tmp;
            for (int j = i; j < i + k; j++)
                tmp.pb(j + 1);
            res ^= query(tmp);
        }
        return res;
    }
    int mn = 501, c = 0, tm = 0;
    for (int p = 1; p < k; p++)
    {
        int rem = n - p, u = k - p;
        for (int j = 1; j <= 500; j += 2)
        {
            int w = rem - u * j;
            if (w >= 0 & w % k == 0)
            {
                int op = j + w / k;
                if (op < mn)
                {
                    mn = op;
                    c = p;
                    tm = j;
                }
            }
        }
    }
    if (mn == 501)
        return -1;
    int cur = c;
    for (int i = 0; i < tm; i++)
    {
        int u = k - c;
        vector<int> tmp;
        for (int j = 0; j < c; j++)
            tmp.pb(j + 1);
        for (int j = cur; j < cur + u; j++)
            tmp.pb(j + 1);
        cur += u;
        res ^= query(tmp);
    }
    while (cur < n)
    {
        vector<int> tmp;
        for (int j = cur; j < cur + k; j++)
            tmp.pb(j + 1);
        res ^= query(tmp);
        cur += k;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = solve();
    if (ans != -1)
        cout << "! ";
    cout << ans << endl;
    return 0;
}