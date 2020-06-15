import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String line = br.readLine();
            String s[] = line.split(" ");
            long a = Long.parseLong(s[0]);
            long b = Long.parseLong(s[1]);
            if (a>b) {
                long temp = a;
                a = b;
                b = temp;
            }
            if (b>2L*a) {
                b = 2L*a;
            }
            long d = b - a;
            a = a - d;
            b = b - d*2L;
            long q = a/3L;
            a = a - q*3L;
            b = b - q*3L;
            d = d + q*2L;
            while (a > 0 && b > 0) {
                if (a == 1 && b == 1) 
                    break;
                if (a > b) {
                    long temp = a;
                    a = b;
                    b = temp;
                }
                if (a > 0L && b > 1L) {
                    d++;
                    a--;
                    b=b-2L;
                }
            }            
            System.out.println(d);
            t--;
        }
    }
}