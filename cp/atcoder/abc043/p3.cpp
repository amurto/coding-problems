#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, cost = INT_MAX;
    cin >> N;
    vector<int> arr(N);
    vector<int> cnt(201, INT_MAX);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i=0; i<201; i++) {
        int cur = i-100, sum=0;
        for (int num: arr)
            sum = sum + (num-cur)*(num-cur);
        cost = min(cost, sum);
    }
    cout << cost << "\n";
    return 0;
}