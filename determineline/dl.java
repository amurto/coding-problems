import java.util.Scanner;

public class dl {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        int n = s;
        in.nextLine();
        int a[] = new int[n * 100];
        int i = 0, temp = 0, count = 0;
        while (s > 0) {
            String line = in.nextLine();
            String[] strs = line.split(" ");
            for (int j = 1; j < strs.length; j++) {
                a[i] = Integer.parseInt(strs[j]);
                i++;
            }
            s--;
        }
        in.close();

        // Count the number of occurences of each number
        for (int j = 0; j < i; j++) {
            if (a[j] != 0) {
                count = 0;
                temp = a[j];
                for (int k = j; k < i; k++) {
                    if (a[k] == temp) {
                        count++;
                    }
                }
                if (count == n) {
                    System.out.print(temp + " ");
                }
            }
        }
    }
}