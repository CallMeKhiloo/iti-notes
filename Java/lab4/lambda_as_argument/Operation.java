package lambda_as_argument;

@FunctionalInterface
public interface Operation {
    boolean apply(String x, String y);
}
