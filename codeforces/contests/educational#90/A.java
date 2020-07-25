import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String[] line = br.readLine().split(" ");
            long a = Long.parseLong(line[0]);
            long b = Long.parseLong(line[1]);
            long c = Long.parseLong(line[2]);
            long ans1 = 0L, ans2 = 0L;
            if (a>=c)
                ans1 = -1L;
            else {
                long count1 = 1L, box1 = 1L, x11 = a, x12 = c;
                while (true) {
                    x11 = count1 * a;
                    while (count1 > box1*b) box1++;
                    x12 = box1*c;
                    if (x11 < x12) break;
                    count1++;
                }
                ans1 = count1;
            }
            if (a*b <= c)
                ans2 = -1L;
            else {
                long count2 = 1L, box2 = 1L, x21 = a, x22 = c;
                while (true) {
                    x21 = count2 * a;
 
                    while (count2 > box2*b) 
                        box2++;
                    x22 = box2*c;
                    if (x22 < x21) break;
                    count2++;
                }
                ans2 = count2;
            }
            System.out.println(ans1 + " " + ans2);
            t--;
        }
    }
}
