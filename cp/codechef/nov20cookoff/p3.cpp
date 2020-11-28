#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int hw(int merge, vector<int> arr)
{
    if (merge == 0)
    {
        int sum = 0;
        for (int val : arr)
            sum += val;
        return sum;
    }
    int sum = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            vector<int> farr;
            farr.pb(arr[i] * arr[j]);
            for (int k = 0; k < arr.size(); k++)
                if (k != i && k != j)
                    farr.pb(arr[k]);
            sum = min(sum, hw(merge - 1, farr));
        }
    }
    return sum;
}

int solve()
{
    int k, x;
    cin >> k >> x;

    vector<int> fact;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int temp = 1;
            while (x % i == 0)
            {
                x /= i;
                temp *= i;
            }
            fact.pb(temp);
        }
    }
    if (x > 1)
        fact.pb(x);
    if (fact.size() <= k)
    {
        int sum = 0;
        for (int val : fact)
            sum += val;
        sum += k - fact.size();
        return sum;
    }
    return hw(fact.size() - k, fact);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}
