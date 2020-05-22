import java.util.Scanner;

public class bn {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n+1];
        int path[] = new int[100];
        int j=0;
        for (int i=2;i<=n;i++) {
            a[i] = in.nextInt();
        }
        in.close();
        for (int i=1;i<=n;i++) {
            a[i] = in.nextInt();
        }
    }
}