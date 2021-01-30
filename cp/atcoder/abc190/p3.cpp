#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 200;
int A[N], B[N], C[N], D[N], P[N];

int bd(int cur, int k, int m)
{
    if (cur == k)
    {
        int res = 0;
        for (int i = 0; i < m; i++)
            if (P[A[i]] > 0 && P[B[i]] > 0)
                res++;
        return res;
    }
    int res = 0;
    P[C[cur]]++;
    res = max(res, bd(cur + 1, k, m));
    P[C[cur]]--;
    P[D[cur]]++;
    res = max(res, bd(cur + 1, k, m));
    P[D[cur]]--;
    return res;
}

int solve()
{
    int n, m, k;
    cin >> n >> m;
    memset(P, 0, sizeof(P));
    for (int i = 0; i < m; i++)
        cin >> A[i] >> B[i];
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> C[i] >> D[i];
    return bd(0, k, m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}