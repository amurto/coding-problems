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
        ll d, k;
        cin >> d >> k;
        ll m = 0, p = 0;
        while (m<= 2*d)
        {
            m += k;
            p = p ^ 1;
        }
        if (p == 0)
            cout << "Ashish\n";
        else
            cout << "Utkarsh\n";
    }
    return 0;
}