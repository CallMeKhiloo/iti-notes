@FunctionalInterface
interface Trifunction<T, U, V, R>{
    R apply(T t, U u, V v);
}
public class task2 {
    public static void main(String args[]){
        Trifunction<Double, Double, Double, Double[]> quadratic_eq = new Trifunction<Double, Double, Double, Double[]>(){
            @Override
            public Double[] apply(Double a, Double b, Double c){
                Double d = b * b - 4 * a * c;
                if (d < 0) return new Double[]{};
                double sqrtD = Math.sqrt(d);
                return new Double[]{ (-b + sqrtD) / 2 * a, (-b - sqrtD) / 2 * a};
            } 
        };

        Double [] roots = quadratic_eq.apply(1.0, -3.0, 2.0);
        System.out.println("first root : " + roots[0] + " ,second root : " + roots[1]);
    }

    public static class khalil{
        public static void sayhello(){
            System.out.println("sdfsd");
        }
    }
}