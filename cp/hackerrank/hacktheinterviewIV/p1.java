import java.util.*;
import java.io.*;

public class problem1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        String s = in.next();
        char num[] = s.toCharArray();
        int d = in.nextInt();
        int t = 0, c = 0;
        for (char token : num) {
            if (token == '0')
                c++;
            else
                c = 0;
            if (c == d) {
                c = 0;
                t++;
            }
        }
        System.out.println(t);
    }
}