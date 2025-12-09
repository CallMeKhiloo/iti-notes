import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        Double r;
        while (true) {
            try {
                System.out.println("Enter the real number value : ");
                r = Double.parseDouble(scanner.nextLine());
                break;
            } catch (Exception e) {
                System.out.println("Invalid Number!! try again");
            }
        }
        Double i;
        while (true) {
            try {
                System.out.println("Enter the imaginary number value : ");
                i = Double.parseDouble(scanner.nextLine());
                break;
            } catch (Exception e) {
                System.out.println("Invalid Number!! try again");
            }
        }
        scanner.close();

        Complex c1 = new Complex(r, i);
        Complex c2 = new Complex(r, i);

        Complex addition = c1.add(c2);
        Complex subtraction = c1.subtract(c2);
        Complex multiplication = c1.multiply(c2);
        Complex division = c1.divide(c2);

        addition.print();
        subtraction.print();
        multiplication.print();
        division.print();
    }
}