import java.util.Scanner;
import java.text.DateFormatSymbols;

public class cciii {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        DateFormatSymbols dfs = new DateFormatSymbols();
        String[] months = dfs.getMonths();
        String input = in.next();
        int k = in.nextInt();
        for(int i=0;i<12;i++) {
            if (months[i].equals(input)) {
                System.out.println(months[(i+k)%12]);
                break;
            }
        }

    }
}