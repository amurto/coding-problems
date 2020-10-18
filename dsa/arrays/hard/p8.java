// https://practice.geeksforgeeks.org/problems/minimum-number-to-make-median-x/0
// Minimum number to make median X

import java.util.*;
import java.io.*;

public class p8 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int x = Integer.parseInt(params[1]);
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            int l = 0, e = 0, g = 0, gs = -1, sg = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(line[i]);
                if (a[i] < x) {
                    gs = Math.max(gs, a[i]);
                    l++;
                } else if (a[i] > x) {
                    sg = Math.min(sg, a[i]);
                    g++;
                } else
                    e++;
            }
            int ans = Math.abs(l - g);
            if (n % 2 == 0) {
                ans += (e > 0 ? 0 : (gs + sg == 2 * x ? 0 : 1));
            } else {
                if (e == 0 && gs + sg != 2 * x) {
                    if (gs + sg > 2 * x) {
                        if (l < g)
                            ans++;
                    } else {
                        if (g < l)
                            ans++;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}