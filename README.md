## Coding Problems

```java
import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
        }
    }
}
```

```c++
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> LineToArray(char delimeter, string unwanted) {
    vector<int> nodes;
    string S, T;
    // Empty character
    getline(cin, S);
    getline(cin, S);
    stringstream X(S);
    while (getline(X, T, delimeter))
        if (T != unwanted)
            nodes.push_back(stoi(T));
    return nodes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) 
            cin>>arr[i];
    }
    return 0;
}
```
## Behavioral questions
### Leadership Principles
* [Part 1](https://www.1point3acres.com/bbs/thread-307462-1-1.html)
* [Part 2](https://kraftshala.com/what-questions-to-expect-in-amazon-interview/)

### [DSA Guide](https://drive.google.com/file/d/15PWBaBk54RXkkduleBSSPuTHWcKWcaqW/view)

### [DP is EASY](https://leetcode.com/discuss/general-discussion/822189/DP-IS-EASY!-5-Steps-to-Think-Through-DP-Questions.)

### Modulo 10^9 + 7

```cpp
const int MOD = 1000000007;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}
```
