public class task3 {
    public static void main(String [] args){
        if(args.length < 2){
            System.out.println("please enter a number and a string !!!");
            return;
        }

        int times = 0;

        try{
            times = Integer.parseInt(args[0]);
        }
        catch(NumberFormatException e){
            System.out.println("First argument must be a number.");
            return;
        }

        for(int i = 0 ; i < times ; i++)
            System.out.println(args[1]);
    }
}
