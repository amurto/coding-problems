#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n), r(m);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<double> p(m);
        for (int i = 0; i < m; i++)
            cin >> r[i] >> p[i];
        double res = 1.0;
        int correct = n - 1;
        while (correct >= 0 && arr[correct] == correct + 1)
            correct--;
        if (correct < 0)
            res = 0.0;
        for (int i = 0; i < m; i++)
            if (r[i] - 1 >= correct)
                res *= (1.0 - p[i]);
        res = 1 - res;
        cout << fixed << setprecision(6) << res << "\n";
    }
    return 0;
}