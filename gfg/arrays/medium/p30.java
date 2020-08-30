// https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0
// Maximum Tip Calculator

import java.util.*;
import java.io.*;

public class p30 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int x = Integer.parseInt(params[1]);
            int y = Integer.parseInt(params[2]);
            ArrayList<List<Integer>> arr = new ArrayList<List<Integer>>();
            String[] line1 = br.readLine().split(" ");
            String[] line2 = br.readLine().split(" ");
            for (int i = 0; i < n; i++)
                arr.add(Arrays.asList(Integer.parseInt(line1[i]), Integer.parseInt(line2[i])));
            Collections.sort(arr, (o1, o2) -> (Math.abs(o2.get(0) - o2.get(1))) - (Math.abs(o1.get(0) - o1.get(1))));
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (x > 0 && (arr.get(i).get(0) >= arr.get(i).get(1) || y == 0)) {
                    sum += arr.get(i).get(0);
                    x--;
                } else if (y > 0 && (arr.get(i).get(0) < arr.get(i).get(1) || x == 0)) {
                    sum += arr.get(i).get(1);
                    y--;
                }
            }
            System.out.println(sum);
        }
    }
}