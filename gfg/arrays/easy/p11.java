// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0
// Smallest subarray with sum greater than x

import java.util.*;
import java.io.*;

public class p11 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0;i<n;i++) 
                a[i] = Integer.parseInt(line[i]);
            int in = a[0], ex = 0;
            for (int i=1; i<n; i++) {
                ex = ex + a[i];
                int temp = Math.max(in, ex);
                ex = in;
                in = temp;
            }
            System.out.println(Math.max(in, ex));
        }
    }
}