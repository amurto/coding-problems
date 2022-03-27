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

const int N = 1e5 + 5, B = 320;
int st1[N * B], st2[N * B];
int calc(vector<int> arr, int n)
{
    int res = n - 1;
    for (int diff = 0; diff <= B; diff++)
    {
        for (int i = 0; i < n; i++)
        {
            int t = arr[i] - diff * i;
            if (t < 0)
            {
                t = abs(t);
                st1[t]++;
                res = min(res, n - st1[t]);
            }
            else
            {
                st2[t]++;
                res = min(res, n - st2[t]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int t = arr[i] - diff * i;
            if (t < 0)
                st1[abs(t)] = 0;
            else
                st2[t] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= min(n - 1, i + B); j++)
        {
            if (arr[j] >= arr[i] && (arr[j] - arr[i]) % (j - i) == 0)
            {
                int t = (arr[j] - arr[i]) / (j - i);
                st2[t]++;
                res = min(res, n - st2[t] - 1);
            }
        }
        for (int j = i + 1; j <= min(n - 1, i + B); j++)
            if (arr[j] >= arr[i] && (arr[j] - arr[i]) % (j - i) == 0)
                st2[(arr[j] - arr[i]) / (j - i)] = 0;
    }
    return res;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = n - 1;
    for (int t = 0; t < 2; t++)
    {
        res = min(res, calc(arr, n));
        reverse(arr.begin(), arr.end());
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(st1, 0, sizeof(st1));
    memset(st2, 0, sizeof(st2));
    cout << solve() << "\n";
    return 0;
}