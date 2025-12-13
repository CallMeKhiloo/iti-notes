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
        for (T item : items) {
            String curr_id = item.getItemDetails()[0];
            if (curr_id.equals(new_id)) {
                return false;
            }
        }
        return items.add(t);
    }

    public T retrieveItem(String id) {
        for (T item : items) {
            String x = item.getItemDetails()[0];
            if (id.equals(x))
                return item;
        }
        throw new ItemNotFoundException("The id Is not found");
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
            System.out.println("This item has id: " + tokens[0] + " and title: " + tokens[1]);
        }
    }
}
