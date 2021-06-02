#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, k;
    cin >> n >> k;
    string res = "";
    int a = (n - k) / 2;
    for (int i = 0, p = 0; i < n; p ^= 1)
    {
        if (p == 0)
        {
            for (int j = 0; i < n && j < a; i++, j++)
                res.pb('0');
        }
        else
        {
            res.pb('1');
            i++;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}