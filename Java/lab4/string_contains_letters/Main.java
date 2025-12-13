import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.nextLine();

        System.out.println(
                isOnlyLetters(s) ? "String has only letters" : "String has other characters other than letters");
    }

    public static boolean isOnlyLetters(String s) { // i need to make another method instead of this
        for (char c : s.toCharArray()) {
            if (!Character.isLetter(c))
                return false;
        }
        return true;
    }
}
