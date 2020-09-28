#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, TL, TR, BL, BR, ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> TL >> TR >> BL >> BR;
            if (TL == BR && TR == BL)
                ans = 1;
        }
        if (m % 2 == 0 && ans == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}