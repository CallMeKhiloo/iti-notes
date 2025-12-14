package models;

public abstract class LibraryItem {
    private String id;
    private String title;
    private boolean available;

    public LibraryItem(String id, String title) {
        this.id = id;
        this.title = title;
        this.available = true;
    }

    public String getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public boolean getAvailability() {
        return this.available;
    }

    public void setAvailability(boolean available) {
        this.available = available;
    }

    public abstract String[] getItemDetails();
}