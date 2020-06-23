import java.util.*;
import java.lang.*;
import java.io.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int t = n+1;
        System.out.println(t*3 + 1);
        int x = 0, y=0;
        while (t>0) {
            System.out.println(x + " " + y);
            System.out.println(x + " " + (y+1));
            System.out.println((x+1) + " " + y);
            x++;y++;
            t--;
        }
        System.out.println(x + " " + y);
    }
}
