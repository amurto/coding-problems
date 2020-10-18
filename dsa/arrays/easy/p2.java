// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum/0
// Count pairs with given sum

import java.util.*;
import java.io.*;

public class p2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int k = Integer.parseInt(params[1]);
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            int[] count = new int[102];
            for (int i=0;i<n;i++) {
                int v = Integer.parseInt(line[i]);
                a[i] = v;
                count[v]++;
            }
            int pairs=0;
            for (int i=0;i<n;i++) {
                if (a[i] < k) {
                    if (count[k-a[i]]>0)
                        pairs+=count[k-a[i]];
                    if (a[i] == k-a[i])
                        pairs--;
                }
            }
            System.out.println(pairs/2);
        }
    }
}