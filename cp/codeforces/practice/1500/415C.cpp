// https://codeforces.com/contest/415/problem/C
// Mashmokh and Numbers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
int seq[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k < n / 2)
    {
        cout << "-1\n";
        return;
    }
    if ((n == 1 && k > 0) || (n > 1 && k == 0))
    {
        cout << "-1\n";
        return;
    }
    int slots = n / 2;
    slots--;
    int req = k - slots, cur = 1;
    seq[0] = req * 2, seq[1] = req * 3;
    for (int i = 2; i < n; i += 2)
    {
        while (cur == seq[0] || cur == seq[1] || cur + 1 == seq[0] || cur + 1 == seq[1])
            cur++;
        seq[i] = cur;
        seq[i + 1] = cur + 1;
        cur += 2;
    }
    for (int i = 0; i < n; i++)
        cout << seq[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}