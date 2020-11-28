import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String[] line = br.readLine().split(" ");
            long x, y, n, q, r;
            x = Long.parseLong(line[0]);
            y = Long.parseLong(line[1]);
            n = Long.parseLong(line[2]);
            q = n/x;
            r = n%x;
            if (r<y) {
                q--;
            }
            System.out.println(q*x+y);
            t--; 
        }
    }

}
