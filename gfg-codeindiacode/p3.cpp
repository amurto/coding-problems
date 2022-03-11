#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = -1;
    string A, B;
    cin >> n >> A >> B;
    array<int, 2> cnt{0, 0}, cntA{0, 0}, cntB{0, 0};
    for (char ch : A)
        cntA[ch - '0']++;
    for (char ch : B)
        cntB[ch - '0']++;
    if ((cntA[0] & 1) != (cntB[0] & 1))
        return res;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            if (A[i] == '0')
                cnt[0]++;
            else
                cnt[1]++;
        }
    }
    if (cnt[0] % 2 == 0)
        res = cnt[0] / 2 + cnt[1] / 2;
    else
    {
        res = cnt[0] / 2 + cnt[1] / 2;
        for (int i = 1; i < n; i++)
            if (A[i - 1] != B[i - 1] && A[i] != B[i] && A[i - 1] != A[i])
                return res + 1;
        res += 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}