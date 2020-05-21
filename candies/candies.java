import java.util.Scanner;

public class candies {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int a[] = new int[m];
        int q = n/m;
        int r = n%m;
        for (int i=0; i<m; i++) {
            if (r>0) {
                System.out.print(q+1 + " ");
                r--;
            } else 
                System.out.print(q + " ");
        }

    }
}