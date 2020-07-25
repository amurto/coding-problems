import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            long p = Long.parseLong(br.readLine());
            p = p-4;
            if (p%4 == 0)
                System.out.println("YES");
            else 
                System.out.println("NO");
            t--;
        }
    }
}
