// https://practice.geeksforgeeks.org/problems/sum-of-lengths-of-non-overlapping-subarrays/0
// Sum of Lengths of Non-Overlapping SubArrays

import java.util.*;
import java.io.*;

public class p12 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0;i<n;i++) 
                a[i] = Integer.parseInt(line[i]);
            int k = Integer.parseInt(br.readLine());
            Boolean hasK = false;
            int sum = 0, cur = 0;
            for (int i=0;i <n; i++) {
                if (a[i] > k) {
                    if (hasK)
                        sum+=cur;
                    cur = 0;
                    hasK = false;
                } else {
                    if (a[i] == k) {
                        hasK = true;
                    }
                    cur++;
                }
            }
            if (hasK)
                sum+=cur;
            System.out.println(sum);
        }
    }
}