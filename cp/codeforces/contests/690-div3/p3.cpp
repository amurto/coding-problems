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
        int x;
        cin >> x;
        int cur = 9;
        vector<int> num;
        while (x > 0 && cur > 0)
        {
            if (x >= cur)
            {
                x -= cur;
                num.pb(cur);
            }
            cur--;
        }
        if (x > 0)
        {
            cout << "-1\n";
            continue;
        }
        reverse(num.begin(), num.end());
        for (int d : num)
            cout << d;
        cout << "\n";
    }
    return 0;
}