#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n, cnt=0, p=0;
    cin >> n;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    do
    {
        p++;
        int last = arr[0];
        cnt++;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > last)
            {
                last = arr[i];
                cnt++;
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
    d(cnt, p);
    double res= (1.0*cnt)/(1.0*p);
    d(res);
    return 1.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}