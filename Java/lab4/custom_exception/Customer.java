package custom_exception;

public class Customer{
    private String name;
    private Double balance;

    public void setName(String name) throws InvalidInputException{
        if(name.matches(".*\\d+.*")){
            throw new InvalidInputException("you entered numbers in your name!!!");
        }
        this.name = name;
    }

    public void setBalance(Double balance) throws InvalidInputException{
        if(balance < 0){
            throw new InvalidInputException("you entered a negative number in you balance!!!");
        }
        this.balance = balance;
    }

    public void withdraw(int amount) throws InvalidInputException{
        if(amount > balance){
            throw new InvalidInputException("You entered an amount greater than your balance!!!");
        }
    }

    public String getName(){
        if(name == null) return "no name";
        return name;
    }

    public Double getBalance(){
        if (balance == null) return 0.0;
        return balance;
    }
}