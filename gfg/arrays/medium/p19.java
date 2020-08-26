// https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0
// Boolean Matrix Problem

import java.util.*;
import java.io.*;

public class p19 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] rc = br.readLine().split(" ");
            int r = Integer.parseInt(rc[0]);
            int c = Integer.parseInt(rc[1]);
            int[][] a = new int[r+1][c+1];
            for (int i = 0; i < r; i++) {
                String[] line = br.readLine().split(" ");
                for (int j = 0; j < c; j++)
                    a[i][j] = Integer.parseInt(line[j]);
            }

            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    if (a[i][j] == 1) {
                        a[i][c] = 1;
                        a[r][j] = 1;
                    }

            for (int i = 0; i < r; i++) {
                StringBuffer sb  =new StringBuffer();
                for (int j = 0; j < c; j++) {
                    if (a[i][c] == 1 || a[r][j] == 1)
                        a[i][j] = 1;
                    sb.append(a[i][j] + " ");
                }
                System.out.println(sb);
            }
        }
    }
}