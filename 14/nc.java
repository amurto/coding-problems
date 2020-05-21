import java.util.Scanner;
import java.util.Arrays;

public class nc {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int a[] = new int[n];
        for (int i=0; i<n;i++) {
            a[i] = in.nextInt();
        }
        in.close();
        Arrays.sort(a);
        System.out.println(a[n-k]);
    }
}