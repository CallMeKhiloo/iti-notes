package models;

import java.util.ArrayList;
import utils.ItemNotFoundException;

public class Library<T extends LibraryItem> {
    private ArrayList<T> items;

    public Library() {
        items = new ArrayList<>();
    }

    public boolean addItem(T t) {
        String new_id = t.getItemDetails()[0];
        T item = items.stream().filter(x -> x.getId().equals(new_id)).findFirst().orElse(null);
        if (item != null)
            return false;
        return items.add(t);
    }

    public T retrieveItem(String id) {
        T item = items.stream().filter(x -> x.getId().equals(id)).findFirst().orElse(null);
        if (item == null)
            throw new ItemNotFoundException("The id Is not found");
        return item;
    }

    public void updateItemTitle(String id, String title) {
        T item = retrieveItem(id);
        item.setTitle(title);
    }

    public boolean deleteItem(String id) {
        T item = retrieveItem(id);
        return items.remove(item);
    }

    public void displayItems() {
        for (T item : items) {
            String[] tokens = item.getItemDetails();
            String availability = tokens[2] == "true" ? " and is available" : " and isn't available";
            System.out.println("This item has id: " + tokens[0] + " and title: " + tokens[1] + availability);
        }
    }
}
