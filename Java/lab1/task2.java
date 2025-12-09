public class task2 {
    public static void main(String [] args){
        if(args.length == 0){
            System.out.println("you entered nothing !!!");
            return;
        }

        if(args[0].equals("Hello")){
            for(int i = 0; i<args.length; i++){
                System.out.println("You entered: "+args[i]);
            }
        }
    }
}
