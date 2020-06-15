import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String line = br.readLine();
            String s[] = line.split(" ");
            long n = Long.parseLong(s[0]);
            long x = Long.parseLong(s[1]);
            int m = Integer.parseInteger(s[2]);
            for (int i=0; i<m; i++) {
                String newline = br.readLine();
                String si[] = newline.split(" ");
                long li = si[0];
                long ri = si[1];
                
            }
            System.out.println(d);
            t--;
        }
    }
}