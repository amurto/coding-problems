import java.util.*;
import java.io.*;

public class p4 {
    public static void swap(int[] a, int[] b, int i, int j) {
        int temp=a[i];
        a[i]=b[j];
        b[j]=temp;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int x = Integer.parseInt(params[0]);
            int y = Integer.parseInt(params[1]);
            String[] A = br.readLine().split(" ");
            String[] B = br.readLine().split(" ");
            int[] a = new int[x];
            for (int i=0; i<x; i++)
                a[i]= Integer.parseInt(A[i]);
            int[] b = new int[y];
            for (int i=0; i<y; i++)
                b[i]= Integer.parseInt(B[i]);
            int ptr1=x-1, ptr2=0;
            while (ptr1>=0 && ptr2<y) {
                if (b[ptr2]<a[ptr1]) {
                    swap(a, b, ptr1, ptr2);
                }
                ptr1--;
                ptr2++; 
            }
            Arrays.sort(a);
            Arrays.sort(b);
            StringBuffer sb = new StringBuffer();
            for (int v: a)
                sb.append(v+" ");
            for (int v: b)
                sb.append(v+" ");
            System.out.println(sb);
        }
    }
}