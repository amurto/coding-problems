import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        while (t>0) {
            int n = in.nextInt();
            ArrayList<Integer> arr = new ArrayList<Integer>();
            for (int i=0;i<n; i++) 
                arr.add(in.nextInt());
            ArrayList<Integer> arr2 = new ArrayList<Integer>();
            for (int i=0;i<n; i++) 
                arr2.add(arr.get(i)^1);
            
            System.out.println(arr);
            System.out.println(arr2);
            arr2.clear();
            t--;
        }
    }
}