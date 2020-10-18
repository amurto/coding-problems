// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0
// Array Subset of another array

import java.util.*;
import java.io.*;

public class p25 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int m = Integer.parseInt(params[0]);
            int n = Integer.parseInt(params[1]);
            String[] line1 = br.readLine().trim().replaceAll("  "," ").split(" ");
            String[] line2 = br.readLine().trim().replaceAll("  "," ").split(" ");
            int[] a = new int[n];
            HashSet<Integer> h = new HashSet<Integer>();
            for (String v: line1)
                h.add(Integer.parseInt(v));
            Boolean ans=true;
            for (String v: line2) {
                if (!h.contains(Integer.parseInt(v))) {
                    ans=false;
                    break;
                }
            }
            System.out.println(ans ? "Yes" : "No");
        }
    }
}