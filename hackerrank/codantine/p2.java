import java.util.*;
import java.math.*;
import java.io.*;

public class p2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        long d[] = new long[m+1];
        for (int i=0; i<n; i++) {
            String[] newline = br.readLine().split(" ");
            int day = Integer.parseInt(newline[0]);
            long runs = Long.parseLong(newline[1]);
            d[day] = Math.max(d[day], runs);
        }
        Arrays.sort(d);
        System.out.println(d[m-1] +d[m]);
    }
}
