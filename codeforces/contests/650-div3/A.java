import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        Boolean f = true;
        while (t>0) {
            String line = br.readLine();
            char[] b = line.toCharArray();
            int i=0;
            while (i<b.length) {
                System.out.print(b[i] + "");
                i = i+2;
            }
            System.out.print(b[b.length - 1]);
            System.out.println();
            t--; 
        }
    }

}
