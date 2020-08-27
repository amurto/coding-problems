// https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k/0
// Largest Sum Subarray of Size at least K

import java.util.*;
import java.io.*;

public class p26 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int k = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            int[] s = new int[n];
            int sum=0;
            for (int i=0; i<n; i++) {
                a[i]= Integer.parseInt(line[i]);
                sum+=a[i];
                s[i] =sum;
            }
            sum=s[k-1];
            int max=sum;
            for (int i=k;i<n;i++) {
                sum+=a[i];
                if (s[i]-s[i-k] > sum) {
                    sum=s[i]-s[i-k];
                }
                max=Math.max(max, sum);
            }
            System.out.println(max);
        }
    }
}