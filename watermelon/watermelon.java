import java.util.Scanner;  

public class watermelon {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in); 
    int weight = in.nextInt(); 
    in.close(); 
    if (weight % 2 == 1 || weight == 2) {
      System.out.println("NO"); 
    } else {
      System.out.println("YES"); 
    }
  }
}
