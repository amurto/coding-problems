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
        int n, m, v, sum = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            sum += v;
        }
        if (sum == m)
            cout << "YES \n";
        else
            cout << "NO \n";
    }
    return 0;
}