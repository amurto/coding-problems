// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0
// Largest Number formed from an Array

import java.util.*;
import java.io.*;

public class p17 {
    public static class Greatest implements Comparator<Integer> {
        public int compare(Integer a1, Integer a2) {
            String s1 = String.valueOf(a1);
            String s2 = String.valueOf(a2);
            if (Integer.parseInt(s1 + s2) > Integer.parseInt(s2 + s1))
                return -1;
            return 1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            ArrayList<Integer> arr = new ArrayList<Integer>();
            for (String s : line)
                arr.add(Integer.parseInt(s));
            Collections.sort(arr, new Greatest());
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < n; i++)
                sb.append(arr.get(i));
            System.out.println(sb);
        }
    }
}