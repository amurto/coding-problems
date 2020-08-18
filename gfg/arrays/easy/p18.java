// https://practice.geeksforgeeks.org/problems/left-out-candies/0
// Left out candies

import java.util.*;
import java.io.*;

public class p18 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int m = Integer.parseInt(line[1]);
            int i=1;
            while (i<=m) {
                m=m-i;
                i=i%n+1;
            }
            System.out.println(m);
        }
    }
}
