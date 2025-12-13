package models;
public class Client {
    private String id;
    private String name;
    private String email;

    public Client(String id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getEmail() {
        return this.email;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void getClientDetails(String id) {
        System.out
                .println("Client with id: " + getId() + " has name: " + getName() + " and has an email: " + getEmail());
    }
}
