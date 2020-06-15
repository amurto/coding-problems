import java.util.*;
import java.io.*;

class xystr {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while (t>0) {
            String s = in.next();
            char[] xy = s.toCharArray();
            int c = 0;
            for (int i=0; i<xy.length - 1; i++) 
                if (xy[i] != xy[i+1]) {
                    c++;
                    i++;
                }
            System.out.println(c);
            t--;
        }
        in.close();
    }
}