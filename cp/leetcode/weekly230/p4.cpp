#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<double> getCollisionTimes(vector<vector<int>> &cars)
{
    int n = cars.size();
    vector<double> res(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty())
        {
            int pi = cars[i][0], si = cars[i][1], j = st.top();
            int pj = cars[j][0], sj = cars[j][1];
            if (sj >= si || 1.0 * (pj - pi) / (si - sj) >= res[j] && res[j] > 0)
                st.pop();
            else
                break;
        }
        if (!st.empty())
            res[i] = 1.0 * (cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
        st.push(i);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(6) << fixed;
    int n, p, s;
    cin >> n;
    vector<vector<int>> cars(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p >> s;
        cars[i].pb(p);
        cars[i].pb(s);
    }
    vector<double> res = getCollisionTimes(cars);
    for (double r : res)
        cout << r << " ";
    cout << "\n";
    return 0;
}