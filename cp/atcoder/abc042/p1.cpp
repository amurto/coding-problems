#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[3], five = 0, seven = 0;
    cin >> arr[0] >> arr[1] >> arr[2];
    for (int v : arr)
        if (v == 5)
            five++;
        else if (v == 7)
            seven++;
    if (five == 2 && seven == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}