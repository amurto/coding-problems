// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Largest subarray with 0 sum

import java.util.*;
import java.io.*;

public class p17 {
    public static int maxLen(int arr[], int n) {
        HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
        int s=0, max=0;
        h.put(0, -1);

        for (int i=0; i<n; i++) {
            s+=arr[i];
            if (h.get(s) == null)
                h.put(s, i);
            else {
                int v= h.get(s);
                max = Math.max(max, i-v);
            }
        }
        return max;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] arr =new int[n];
            for (int i=0; i<n; i++) 
                arr[i] =Integer.parseInt(line[i]);

            System.out.println(maxLen(arr, n));
        }
    }
}