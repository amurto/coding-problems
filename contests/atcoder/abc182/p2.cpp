#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, MAX = 2;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> gcd(1001);
    for (int val : arr)
    {
        unordered_set<int> factors;
        for (int i = 2; i * i <= val; i++)
        {
            if (val % i == 0)
            {
                factors.insert(i);
                while (val % i == 0)
                    val /= i;
            }
        }
        if (val > 1)
            factors.insert(val);
        for (auto f : factors)
            gcd[f]++;
    }
    for (int i = 2; i <= 1000; i++)
        if (gcd[i] >= gcd[MAX])
            MAX = i;
    cout << MAX << "\n";
    return 0;
}