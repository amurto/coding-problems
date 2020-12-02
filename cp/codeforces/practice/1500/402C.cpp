// https://codeforces.com/contest/402/problem/C
// Searching for Graph

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
        int n, p;
        cin >> n >> p;
        int e = 2 * n + p, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (cnt == e)
                break;
            for (int j = i + 1; j <= n; j++)
            {
                if (cnt == e)
                    break;
                cout << i << " " << j << "\n";
                cnt++;
            }
        }
    }
    return 0;
}