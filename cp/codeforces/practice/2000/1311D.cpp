// https://codeforces.com/contest/1311/problem/D
// Three Integers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 12000;
void solve()
{
    int sum = 1e6;
    vector<int> abc(3), res(3), seq(3);
    for (int i = 0; i < 3; i++)
        cin >> abc[i];
    for (int i = 1; i <= N; i++)
    {
        seq[0] = i;
        for (int j = i; j <= N; j += i)
        {
            seq[1] = j;
            if (seq[1] <= abc[2])
            {
                seq[2] = abc[2] - abc[2] % j;
                int cur = 0;
                for (int c = 0; c < 3; c++)
                    cur += abs(abc[c] - seq[c]);
                if (cur < sum)
                {
                    sum = cur;
                    res = seq;
                }
            }
            seq[2] = ((abc[2] + j - 1) / j) * j;
            int cur = 0;
            for (int c = 0; c < 3; c++)
                cur += abs(abc[c] - seq[c]);
            if (cur < sum)
            {
                sum = cur;
                res = seq;
            }
        }
    }
    cout << sum << "\n";
    for (int i = 0; i < 3; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}