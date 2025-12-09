package custom_exception;

import java.util.Scanner;

public class Main {
    public static void main(String args []){
        Customer c = new Customer();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter your name: ");
        String name = scanner.nextLine();

        System.out.println("Enter your balance: ");
        double balance = scanner.nextDouble();
        scanner.nextLine();

        scanner.close();

        try {
            c.setBalance(balance);
            c.setName(name);
        } catch (Exception e) {
            System.out.println("Caught an exception: " + e.getMessage());
        }

        System.out.println("customer is: "+c.getName()+" and has balance= "+c.getBalance());
    }
}
