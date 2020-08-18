// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

import java.util.*;
import java.io.*;

public class p2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            int[] count = new int[10000];
            String[] arr = br.readLine().split(" ");
            int max=0, c=0;
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(arr[i]);
                count[a[i]]++;
                max=Math.max(a[i], max);
            }
            int k = Integer.parseInt(br.readLine());
            
            for (int i=1; i<=max;i++) {
                if (count[i] == 1)
                    c++;
                if (c==k) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }
}