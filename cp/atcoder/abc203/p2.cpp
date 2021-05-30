#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, sum = 0;
    cin >> n >> k;
    n *= 100;
    for (int i = 100; i <= n; i += 100)
    {
        sum += i * k;
        for (int j = 1; j <= k; j++)
            sum += j;
    }
    cout << sum << "\n";
    return 0;
}