// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1658
// 10717 - Mint

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

void dfs(set<int> &M, vector<int> &th, int LM, int cur, int len)
{
    if (len == 4)
    {
        M.insert(LM);
        return;
    }
    if (cur == th.size())
        return;
    dfs(M, th, LM, cur + 1, len);
    dfs(M, th, lcm(LM, th[cur]), cur + 1, len + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    while (true)
    {
        cin >> n >> t;
        if (n == 0 && t == 0)
            break;
        vector<int> th(n);
        int h;
        for (int i = 0; i < n; i++)
            cin >> th[i];
        set<int> M;
        dfs(M, th, 1, 0, 0);
        while (t-- > 0)
        {

            cin >> h;
            int L = h - h % *M.begin();
            int R = 0;
            if (L == h)
                R = h;
            else
                R = L + *M.begin();
            for (int m : M)
            {
                if (m <= h)
                {
                    L = max(L, h - h % m);
                    if (h % m == 0)
                        R = h;
                    else
                        R = min(R, h - h % m + m);
                }
                else
                    R = min(R, m);
            }
            cout << L << " " << R << "\n";
        }
    }
    return 0;
}