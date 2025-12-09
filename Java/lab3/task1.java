import java.util.function.Function;
public class task1{
    public static void main(String args[]){
        Function<Double, Double> CentToFah = new Function<Double, Double> (){
            @Override
            public Double apply(Double c){
                return c*9/5+32;
            }
        };

        System.out.println(CentToFah.apply(6.0));
    }
}