import java.util.Scanner;
import java.util.StringTokenizer;

public class lab3 {
    public static void main(String args[]){
        int count = 0;
        System.out.println("please enter a word: ");

        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();

        System.out.println("please enter the sentence: ");

        scanner.nextLine();
        String sentence = scanner.nextLine();

        StringTokenizer tokenizer = new StringTokenizer(sentence, word);

        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            System.out.println("Token: " + token);
            count++;
        }

        System.out.println("the number of occurrences are: "+count);
        
        scanner.close();
	// try with resources && closable interface
    }
}
