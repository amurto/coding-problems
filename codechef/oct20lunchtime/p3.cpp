#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t-->0) {
        int n, q;
        cin>>n>>q;
        vector<int> arr(n+2);
        arr[0] = arr[n+1] = -1;
        for (int i=1; i<=n; i++) 
            cin>>arr[i];

        int res=0;
        for (int i=1; i<=n;i++)
            if (arr[i] != arr[i-1])
                res++;
        while (q-->0) {
            int x,y;
            cin >> x >> y;
            if (arr[x] != y || n==1) {
                if (arr[x] == arr[x+1])
                    res++;
                if (arr[x] == arr[x-1])
                    res++;
                if (arr[x+1] == y)
                    res--;
                if (arr[x-1] == y)
                    res--;
            }
            arr[x] = y;
            cout << res << "\n";
        }
    }
    return 0;
}