#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    sort(S.begin(), S.end());
    for (string s : S)
        cout << s;
    cout << "\n";
    return 0;
}