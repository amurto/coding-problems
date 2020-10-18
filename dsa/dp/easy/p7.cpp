// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
// Count number of hops

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int NOW(int *DP, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (DP[n] < 0)
        DP[n] = NOW(DP, n - 1) + NOW(DP, n - 2) + NOW(DP, n - 3);
    return DP[n];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int DP[n + 1];
        memset(DP, -1, sizeof(DP));
        cout << NOW(DP, n) << endl;
    }
    return 0;
}