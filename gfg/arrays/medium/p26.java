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
            int sum=0, start=-1, max = 0;
            for (int i=0; i<n; i++) {
                if (i-prev)
                if (sum+a[i] < a[i]) {
                    sum=a[i];
                    start=i-1;
                } else
                    sum+=a[i];
            }
                a[i]= Integer.parseInt(line[i]);

            System.out.println(max);
        }
    }
}