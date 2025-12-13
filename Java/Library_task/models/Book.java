package models;

public class Book extends LibraryItem {
    public Book(String id, String title) {
        super(id, title);
    }

    @Override
    public String[] getItemDetails() {
        return new String[] { getId(), getTitle() };
    }
}
