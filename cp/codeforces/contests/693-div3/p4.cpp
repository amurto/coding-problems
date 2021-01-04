#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string play()
{
    int n;
    cin >> n;
    vector<ll> arr(n), score(2);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    for (int i = 0, cur = 0; i < n; i++, cur ^= 1)
    {
        if (arr[i] % 2 == cur)
            score[cur] += arr[i];
    }
    if (score[0] > score[1])
        return "Alice";
    else if (score[0] < score[1])
        return "Bob";
    return "Tie";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << play() << "\n";
    return 0;
}