#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, m;
    string str;
    cin >> n >> m >> str;
    if (count(str.begin(), str.end(), '1') == 0)
        return str;
    string res = str;
    for (int i = 0; i < n;)
    {
        if (str[i] == '1')
        {
            i++;
            continue;
        }
        int j = i;
        while (j < n && str[j] == '0')
            j++;
        if (i == 0)
        {
            for (int t = 1, r = j - 1; t <= m && r >= i; t++, r--)
                res[r] = '1';
        }
        else if (j == n)
        {
            for (int t = 1, l = i; t <= m && l < j; t++, l++)
                res[l] = '1';
        }
        else
        {
            for (int t = 1, l = i, r = j - 1; t <= m && l < r; t++, l++, r--)
            {
                res[l] = '1';
                res[r] = '1';
            }
        }
        i = j;
    }
    return res;
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