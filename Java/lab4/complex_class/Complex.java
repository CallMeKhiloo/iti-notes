public class Complex<T extends Number> { // Number abstract class
    private Double real;
    private Double imag;

    public Complex(T real, T imag) {
        this.real = real.doubleValue();
        this.imag = imag.doubleValue();
    }

    public Complex add(Complex other) {
        double r = real;
        double i = imag;

        return new Complex<Double>(r + other.real, i + other.imag);
    }

    public Complex subtract(Complex other) {
        double r = real;
        double i = imag;

        return new Complex<Double>(r - other.real, i - other.imag);
    }

    public Complex multiply(Complex other) {
        double r = real;
        double i = imag;

        return new Complex<Double>(r * other.real, i * other.imag);
    }

    public Complex divide(Complex other) {
        double r = real;
        double i = imag;

        return new Complex<Double>(r / other.real, i / other.imag);
    }

    public void print(){
        System.out.println(real+"+"+imag+"i");
    }

}