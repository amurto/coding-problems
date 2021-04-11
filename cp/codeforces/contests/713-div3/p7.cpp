#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e7 + 5;
vector<int> d(N, 1), occ(N);
void init()
{
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            d[j] += i;
    for (int i = 1; i < N; i++)
    {
        if (d[i] < N && occ[d[i]] == 0)
            occ[d[i]] = i;
    }
}

int solve()
{
    int c;
    cin >> c;
    return occ[c] == 0 ? -1 : occ[c];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}