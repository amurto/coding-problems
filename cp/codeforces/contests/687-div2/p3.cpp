#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, p, k, x, y;
        string str;
        cin >> n >> p >> k >> str >> x >> y;

        vector<int> plat(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (str[i] == '1')
                plat[i]++;
            if (i + k < n)
                plat[i] += plat[i + k];
        }
        int sec = INT_MAX;
        for (int i = p - 1; i < n; i++)
        {
            int rem = (i + 1 - p) * y;
            int need = (n - i - 1) / k + 1;
            int add = (need - plat[i]) * x;
            sec = min(sec, rem + add);
        }
        cout << sec << "\n";
    }
    return 0;
}