import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        System.out.println("How many element do you want to add? : ");

        Dictionary dict = new Dictionary();
        Scanner scanner = new Scanner(System.in);

        int size;
        while (true) {
            try {
                size = Integer.parseInt(scanner.nextLine()); // unboxing
                break;
            } catch (Exception e) {
                System.out.println("Enter a valid enteger ya 3am !!");
            }
        }

        for (int i = 0; i < size; i++) {
            System.out.println("Enter the element no." + (i + 1) + " : ");
            String s = scanner.nextLine();
            while (!isOnlyLetters(s)) {
                System.out.println("Invalid string ya negm, enter tany : ");
                s = scanner.nextLine();
            }
            dict.add(s);
        }

        dict.printAll();

        scanner.close();
    }

    public static boolean isOnlyLetters(String s) {
        for (char c : s.toCharArray()) {
            if (!Character.isLetter(c))
                return false;
        }
        return true;
    }
}