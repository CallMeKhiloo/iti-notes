package models;

import java.util.ArrayList;

public class Client {
    private String id;
    private String name;
    private String email;
    private ArrayList<LibraryItem> borrowedItems;

    public Client(String id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.borrowedItems = new ArrayList<>();
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

    public void showBorrowedItems() {
        if (borrowedItems.isEmpty())
            System.out.println("This client hasn't borrowed any items");
        System.out.println("Client " + getName() + " has borrowed: ");
        for (LibraryItem item : borrowedItems) {
            System.out.println("    " + item.getTitle() + " with id: " + item.getId());
        }
    }

    public boolean borrowItem(LibraryItem item) {
        item.setAvailability(false);
        return borrowedItems.add(item);
    }

    public boolean returnItem(String item_id) {
        LibraryItem borrowed_item = borrowedItems.stream().filter(x -> x.getId().equals(item_id)).findFirst()
                .orElse(null);
        if (borrowed_item == null)
            return false;
        borrowed_item.setAvailability(true);
        return borrowedItems.remove(borrowed_item);
    }

    public void getClientDetails() {
        System.out
                .println("Client with id: " + getId() + " has name: " + getName() + " and has an email: " + getEmail());
    }
}
