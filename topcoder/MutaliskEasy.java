import java.util.*;
import java.lang.*;
import java.io.*;

class MutaliskEasy {
    final static int[] dmg = {9, 3, 1};
    public static Boolean HPremains(Integer[] arr) {
        int c = 0;
        for (int a: arr)
            if (a<=0)
                c++;
        if (c==arr.length)
            return false;
        return true;
    }
    public static void minimalAttacks(Integer[] x) {
        int attacks = 0;
        while (HPremains(x)) {
            attacks++;
            Arrays.sort(x, Collections.reverseOrder());
            for (int i=0; i<x.length; i++)
                x[i]-=dmg[i];
        }
        System.out.println(attacks);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        Integer[] arr = new Integer[s.length];
        for (int i=0; i<s.length; i++) 
            arr[i] = Integer.parseInt(s[i]);
        minimalAttacks(arr);
    }
}