#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double f(vector<int> &arr, int n, double x)
{
    double ev = x * n;
    for (double a : arr)
        ev += 1.0 * a - min(1.0 * a, 2.0 * x);
    ev = ev / (1.0 * n);
    return ev;
}

double solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = *max_element(arr.begin(), arr.end());
    double l = 0, r = 2.0 * mx;
    double eps = 1e-9; //set the error limit here
    for (int op = 0; op < 200; op++)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(arr, n, m1); //evaluates the function at m1
        double f2 = f(arr, n, m2); //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(arr, n, l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12) << solve() << "\n";
    return 0;
}