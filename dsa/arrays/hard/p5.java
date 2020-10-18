// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k/0
// Count the subarrays having product less than k

import java.util.*;
import java.io.*;

public class p5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            long k = Long.parseLong(params[1]);
            String[] line = br.readLine().split(" ");
            long[] a = new long[n];
            for (int i=0; i<n; i++)
                a[i]= Long.parseLong(line[i]);
            
            long prod=1, count=0;
            for (int prev=0, i=0; i<n; i++) {
                prod*=a[i];
                while (prod>=k && prev<i)
                    prod/=a[prev++];
                if (prod<k)
                    count+=i-prev+1;
            }
            System.out.println(count);
        }
    }
}