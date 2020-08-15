// Buildings receiving sunlight
// https://practice.geeksforgeeks.org/problems/buildings-receiving-sunlight/0
import java.util.*;
import java.io.*;

public class p9 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            int max=0, c=0;
            for (int i=0;i<n;i++) {
                int v = Integer.parseInt(line[i]);
                if (v >= max) {
                    max=v;
                    c++;
                }
            }
            System.out.println(c);
        }
    }
}