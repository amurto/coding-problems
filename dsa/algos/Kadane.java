// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// Kadane's Algorithm
// Maximum sub-array

import java.util.*;
import java.io.*;

public class kadane {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n= Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
            int max=a[0], sum=0;
            for (int i=0; i<n; i++) {
                // Sum is max of sum so far + current element or current element 
                sum=Math.max(sum+a[i], a[i]);
                max=Math.max(max, sum);
            }
            System.out.println(max);
        }
    }
}