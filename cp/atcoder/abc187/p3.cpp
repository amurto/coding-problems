#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n;
    string s;
    cin >> n;
    vector<pair<string, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s[0] != '!')
            s = '!' + s;
        else
            arr[i].second = 1;
        arr[i].first = s;
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
        if (arr[i].second > arr[i - 1].second && arr[i].first == arr[i - 1].first)
            return arr[i].first.substr(1, arr[i].first.length() - 1);
    return "satisfiable";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}