// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum/0
// Max Circular Subarray Sum

import java.util.*;
import java.io.*;

public class p3 {
    public static int KadaneAlgo(int[] a, int n) {
        int max=a[0], sum=0;
        for (int i=0; i<n; i++) {
            sum=Math.max(sum+a[i], a[i]);
            max=Math.max(max, sum);
        }
        return max;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
            int sum=0;
            int max=KadaneAlgo(a, n);
            for (int i=0;i<n;i++) {
                sum+=a[i];
                a[i]=-a[i];
            }
            sum+=KadaneAlgo(a, n);
            if (sum==0)
                sum=max;
            System.out.println(Math.max(sum,max));
        }
    }
}