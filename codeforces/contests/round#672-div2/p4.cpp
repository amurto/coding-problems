#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void insert(vector<ll> &arr, int cur, ll &ans)
{
    if (cur == 0 || cur == arr.size() - 1)
        return;
    if (arr[cur - 1] < arr[cur] && arr[cur] > arr[cur + 1])
        ans += arr[cur];
    if (arr[cur - 1] > arr[cur] && arr[cur] < arr[cur + 1])
        ans -= arr[cur];
}

void remove(vector<ll> &arr, int cur, ll &ans)
{
    if (cur == 0 || cur == arr.size() - 1)
        return;
    if (arr[cur - 1] < arr[cur] && arr[cur] > arr[cur + 1])
        ans -= arr[cur];
    if (arr[cur - 1] > arr[cur] && arr[cur] < arr[cur + 1])
        ans += arr[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n + 2);
        arr[0] = arr[n + 1] = -1;
        ll low = 0, high = 0, temp;
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            temp = low;
            low = max(low, high - arr[i]);
            high = max(high, temp + arr[i]);
        }
        ll ans = max(low, high);
        cout << ans << "\n";
        while (q-- > 0)
        {
            int L, R;
            cin >> L >> R;
            remove(arr, L-1, ans);
            remove(arr, L, ans);
            remove(arr, L+1, ans);
            if (L!=R) {
                if (R-1 != L+1 && R-1 != L) remove(arr, R-1, ans);
                if (R != L+1) remove(arr, R, ans);
                remove(arr, R+1, ans);
            }
            swap(arr[L], arr[R]);
            insert(arr, L-1, ans);
            insert(arr, L, ans);
            insert(arr, L+1, ans);
            if (L!=R) {
                if (R-1 != L+1 && R-1 != L) insert(arr, R-1, ans);
                if (R != L+1) insert(arr, R, ans);
                insert(arr, R+1, ans);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

