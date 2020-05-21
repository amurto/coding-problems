import java.util.Scanner;

public class spa {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        in.nextLine();
        String line = in.nextLine();
        in.close();
        String[] strs = line.split(" ");
        int max=0,sec=0,i=0;
        for (int j = 0; j < strs.length; j++) {
            a[j] = Integer.parseInt(strs[j]);
            if (a[j]>max) {
                sec=max;
                max=a[j];
                i=j;
            } else if (a[j]>sec) {
                sec = a[j];
            }
        }
        System.out.println(i+1 + " " + sec);
    }
}