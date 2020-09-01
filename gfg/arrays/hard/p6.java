// Number of subarrays having sum exactly equal to k
// https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

import java.util.*;
import java.io.*;

public class p6 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
            int k = Integer.parseInt(br.readLine());
            HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
            h.put(0, 1);
            int sum=0, count=0;
            for (int i=0; i<n; i++) {
                sum+=a[i];
                if (h.containsKey(sum-k)) {
                    count+=h.get(sum-k);
                }
                if (h.containsKey(sum)) {
                    h.put(sum, h.get(sum)+1);
                } else {
                    h.put(sum, 1);
                }
            }
            System.out.println(count);
        }
    }
}