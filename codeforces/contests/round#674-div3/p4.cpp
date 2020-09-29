#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_set<ll> SET;
    SET.insert(0);
    ll sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (SET.count(sum))
        {
            count++;
            SET = unordered_set<ll>{0};
            sum=a[i];
        }
        SET.insert(sum);
    }
    cout << count << endl;
    return 0;
}