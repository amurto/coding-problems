#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double dist(double a, double b)
{
    return a * a + b * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<double, double>> p(1005);
    double X, Y, d, e;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    X /= n;
    Y /= n;
    double P = 0.01;
    for (int i = 0; i < 30000; i++)
    {
        int f = 0;
        d = dist(X - p[0].first, Y - p[0].second);
        for (int j = 1; j < n; j++)
        {
            e = dist(X - p[j].first, Y - p[j].second);
            if (d < e)
            {
                d = e;
                f = j;
            }
        }
        X += (p[f].first - X) * P;
        Y += (p[f].second - Y) * P;
        P *= 0.999;
    }
    cout << setprecision(9) << sqrt(d) << "\n";
    return 0;
}