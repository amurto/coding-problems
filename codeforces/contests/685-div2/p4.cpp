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
        ll d, k, m = 0;
        cin >> d >> k;
        string winner = "Ashish";
        // both players move to (m, m) after which (m+k, m) or (m+k, m+k) is invalid
        // winner is first player if (m+k, m) and (m, m+k) are valid
        // winner is second player if (m+k, m) and (m, m+k) are invalid
        while (2 * m * m <= d * d)
        {
            if ((m + k) * (m + k) + m * m > d * d)
                winner = "Utkarsh";
            m += k;
        }
        cout << winner << "\n";
    }
    return 0;
}