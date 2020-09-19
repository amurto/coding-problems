#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    vector<int> ANS;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int a[n], even_evens = 0, odd_odds = 0, ans = 0;
        for (int i = 0; i < n; i++)
            a[i] = str[i] - 48;
        for (int i = 0; i < n; i++)
        {
            // even evens
            if (i % 2 == 1 && a[i] % 2 == 0)
                even_evens++;

            // odd odds
            if (i % 2 == 0 && a[i] % 2 == 1)
                odd_odds++;
        }
        if (n % 2 == 1)
            ans = (odd_odds >= 1) ? 1 : 2;
        else
            ans = (even_evens >= 1) ? 2 : 1;
        cout << ans << endl;
    }
    return 0;
}