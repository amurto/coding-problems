// https://codeforces.com/contest/357/problem/C
// Knight Tournament

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
    cin >> n >> m;
    vector<int> L(m), R(m), X(m);
    for (int i = 0; i < m; i++)
        cin >> L[i] >> R[i] >> X[i];
    set<int> alive;
    for (int i = 1; i <= n; i++)
        alive.insert(i);
    vector<int> W(n + 1);
    for (int i = 0; i < m; i++)
    {
        auto lt = alive.lower_bound(L[i]);
        auto rt = alive.upper_bound(R[i]);
        for (auto it = lt; it != rt; it++)
        {
            int cur = *it;
            if (cur != X[i])
                W[cur] = X[i];
        }
        alive.erase(lt, rt);
        alive.insert(X[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << W[i] << " ";
    cout << "\n";
    return 0;
}