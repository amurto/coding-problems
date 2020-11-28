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
        int a, b, i, j;
        cin >> a >> b;
        string str;
        cin >> str;
        int n = str.length(), ones = 0;

        i = 0;
        j = n - 1;
        while (str[i] == '0')
            i++;
        while (str[j] == '0')
            j--;

        vector<int> zeros;
        while (i <= j)
        {
            int cnt1 = 0;
            while (i <= j && str[i] == '1')
            {
                i++;
                cnt1++;
            }
            if (cnt1 > 0)
                ones++;
            if (i > j)
                break;
            int cnt2 = 0;
            while (i <= j && str[i] == '0')
            {
                i++;
                cnt2++;
            }
            if (cnt2 > 0)
                zeros.pb(cnt2);
        }
        sort(zeros.begin(), zeros.end());
        int res = ones * a, z = 0;
        for (int idx = 0; idx < zeros.size(); idx++)
        {
            z += zeros[idx];
            ones--;
            res = min(res, ones * a + z * b);
        }
        cout << res << "\n";
    }
    return 0;
}