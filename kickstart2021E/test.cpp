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

const int N = 1e6 + 5;
int fac(int n)
{
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}
double solve(int n)
{
    int cnt = 0, p = 0;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    // do
    // {
    //     p++;
    //     int last = arr[0];
    //     cnt++;
    //     for (int i = 1; i < n; i++)
    //     {
    //         if (arr[i] > last)
    //         {
    //             last = arr[i];
    //             cnt++;
    //         }
    //     }
    // } while (next_permutation(arr.begin(), arr.end()));
    // // d(n, cnt, p);
    // d(cnt);
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = i * dp[i - 1] + fac(i - 1);
    }
    d(dp);
    double res = (1.0 * cnt) / (1.0 * p);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    solve(t);
    return 0;
}