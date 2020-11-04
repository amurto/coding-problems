import java.util.Scanner;

public class nr {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int[] scores = new int[n];
        for (int i = 0; i < n; i++) {
            scores[i] = in.nextInt();
        }
        in.close();
        int ps = scores[k - 1];
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (scores[i] > 0 && scores[i] >= ps) {
                c++;
            }
        }
        System.out.println(c);
    }
}