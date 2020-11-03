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
        for (int cur = 4 * n; cur > 2 * n; cur -= 2)
            cout << cur << " ";
        cout << "\n";
    }
    return 0;
}