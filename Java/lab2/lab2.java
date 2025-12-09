import java.util.Scanner;

public class lab2 {
    public static void main(String args[]){
        int count = 0, curr = 0;
        System.out.println("please enter a word: ");

        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();

        System.out.println("please enter the sentence: ");

        scanner.nextLine();
        String sentence = scanner.nextLine();

        curr = sentence.indexOf(word, curr);
        while(curr != -1){
            count++;
            curr += word.length();
            curr = sentence.indexOf(word, curr);
        }

        System.out.println("the number of occurrences are: "+count);
        
        scanner.close();
    }
}
