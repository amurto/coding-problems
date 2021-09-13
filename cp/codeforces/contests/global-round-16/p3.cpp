#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<string> str(2);
    for (int i = 0; i < 2; i++)
        cin >> str[i];
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        string cur = "";
        for (int j = 0; j < 2; j++)
            cur.pb(str[j][i]);
        sort(cur.begin(), cur.end());
        if (cur == "00")
            arr[i] = 0;
        else if (cur == "01")
            arr[i] = 1;
        else
            arr[i] = 3;
    }
    for (int i = 0; i < n;)
    {
        if (arr[i] == 1)
        {
            res += 2;
            i++;
        }
        else if (i + 1 < n)
        {
            if (arr[i] + arr[i + 1] == 3)
            {
                res += 2;
                i += 2;
            }
            else
            {
                if (arr[i] == 0)
                    res++;
                i++;
            }
        }
        else
        {
            if (arr[i] == 0)
                res++;
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
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}