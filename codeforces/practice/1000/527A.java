import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        long a = Long.parseLong(line[0]);
        long b = Long.parseLong(line[1]);
        long count = 0L;
        while (a > 0 && b > 0) {
            long max  = Math.max(a, b);
            long min  = Math.min(a, b);
            a = max;
            b = min;
            count+=a/b;
            a = a%b;
        }
        System.out.println(count);
    }
}