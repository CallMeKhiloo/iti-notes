import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class lab4{
    public static void main(String args[]){
        System.out.println("please enter an ip: ");

        Scanner scanner = new Scanner(System.in);
        String address = scanner.next();

        String regex = "(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(address);

        if (matcher.find()) {
            if(matcher.group(1).equals("0") || matcher.group(2).equals("0")){
                System.out.println("You can't use zeros with the first 2 octets");
                return;
            }
            System.out.println("Octet 1: " + matcher.group(1));
            System.out.println("Octet 2: " + matcher.group(2));
            System.out.println("Octet 3: " + matcher.group(3));
            System.out.println("Octet 4: " + matcher.group(4));
        } else {
            System.out.println("No IP address found or invalid format.");
        }
	scanner.close();
	// can i use reflections with immutalble string literals
	// how to make a class immutable ?
	// you should make the class attributes private and final in order to restrict the access
	// make the getters return a copy of the state of the object
    }
}
