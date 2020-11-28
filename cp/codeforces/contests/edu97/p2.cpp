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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> oz(n), zo(n);
        oz[0] = 0;
        zo[0] = 1;
        for (int i = 1; i < n; i++)
        {
            oz[i] = zo[i - 1];
            zo[i] = oz[i - 1];
        }
        int p1 = 0, p2 = 0;
        int itr = 0;
        while (itr < n)
        {
            int olditr = itr;
            while (itr < n && s[itr] - '0' != oz[itr])
                itr++;
            if (itr != olditr)
                p1++;
            itr++;
        }
        itr = 0;
        while (itr < n)
        {
            int olditr = itr;
            while (itr < n && s[itr] - '0' != zo[itr])
                itr++;
            if (itr != olditr)
                p2++;
            itr++;
        }
        cout << min(p1, p2) << "\n";
    }
    return 0;
}