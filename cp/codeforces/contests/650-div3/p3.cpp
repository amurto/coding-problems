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
        int n, k, c = 0, tables = 0;
        bool beg = false, end = false;
        string str;
        cin >> n >> k >> str;
        vector<int> arr;
        for (char ch : str)
            arr.pb(ch - '0');
        arr.pb(1);
        for (int i = 0; i <= n; i++)
        {
            if (arr[i] == 0)
            {
                if (i == 0)
                    beg = true;
                if (i == n - 1)
                    end = true;
                c++;
            }
            else
            {
                if (c > 0)
                {
                    int m = c % (k + 1);
                    int tb = c / (k + 1);
                    if (beg && end)
                    {
                        tables = tables + tb;
                        if (m > 0)
                            tables++;
                    }
                    else if (beg || end)
                        tables = tables + tb;
                    else
                    {
                        if (m < k)
                            tb--;
                        tables += tb;
                    }
                }
                c = 0;
                beg = false;
                end = false;
            }
        }
        cout << tables << "\n";
    }
    return 0;
}