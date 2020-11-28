// https://codeforces.com/contest/371/problem/B
// Fox Dividing Cheese

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int a, b;
    cin >> a >> b;

    int div[3] = {2, 3, 5};
    vector<int> A(6), B(6);
    for (int d = 0; d < 3; d++)
    {
        while (a % div[d] == 0)
        {
            A[div[d]]++;
            a /= div[d];
        }
        while (b % div[d] == 0)
        {
            B[div[d]]++;
            b /= div[d];
        }
    }
    if (a != b)
        return -1;
    return abs(A[2] - B[2]) + abs(A[3] - B[3]) + abs(A[5] - B[5]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}