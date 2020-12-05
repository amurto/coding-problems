// https://www.spoj.com/problems/FUNPROB/
// FUNPROB - Yanu in Movie theatre

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        double p = 0;
        if (n <= m)
            p = (double)(m - n + 1) / (m + 1);
        cout << fixed << setprecision(6) << p << "\n";
    }
    return 0;
}