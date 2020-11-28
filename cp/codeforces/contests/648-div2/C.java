import java.util.*;
import java.io.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        int[] offset = new int[n+1];
        int[] shift = new int[n];
        for (int i=0; i<n; i++) {
            a.add(in.nextInt());
            offset[a.get(i)] = i;
        }

        for (int i=0; i<n; i++) {
            b.add(in.nextInt());
            int shifted = offset[b.get(i)] - i;
            if (shifted<0)
                shifted+= n;
            shift[shifted]++;
        }
        
        in.close();
        int max = 0;
        for (int s: shift) {
            if (s>max)
                max=s;
        }

        System.out.println(max);

    }
}