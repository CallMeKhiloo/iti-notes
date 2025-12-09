import java.util.Scanner;

public class lab1 {
    public static void main(String args[]){
        int count = 0;
        System.out.println("please enter a word: ");

        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();

        System.out.println("please enter the sentence: ");

        scanner.nextLine();
        String sentence = scanner.nextLine();

        /*
        0 -> 12
        khalil khalil
        */
        
        for(int i = 0 ; i < (sentence.length()-word.length()); i++){
            String curr = sentence.substring(i, i+word.length());

            if(curr.equals(word)) count++;
        }

        System.out.println("the number of occurrences are: "+count);
        
        scanner.close();
    }
}
