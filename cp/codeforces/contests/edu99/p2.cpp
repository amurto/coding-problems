#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e6;
int f[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f[0] = 0;
    for (int i = 1; i < N; i++)
        f[i] = i + f[i - 1];
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int x;
        cin >> x;
        int i = 1;
        while (f[i] < x)
            i++;
        if (f[i] - x == 1)
            cout << i + 1 << "\n";
        else
            cout << i << "\n";
    }
    return 0;
}