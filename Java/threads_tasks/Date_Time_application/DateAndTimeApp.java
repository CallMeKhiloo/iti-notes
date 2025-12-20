import javax.swing.*;
import java.awt.*;
import java.util.Date;
import java.text.SimpleDateFormat;

public class DateAndTimeApp extends JFrame implements Runnable {

    private JLabel timeLabel;

    public DateAndTimeApp() {
        setTitle("Time & Date Application Thread");
        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        timeLabel = new JLabel("Initializing...", SwingConstants.CENTER);

        Font font = new Font("Arial", Font.BOLD, 24);
        timeLabel.setFont(font);

        Container contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());
        contentPane.add(timeLabel, BorderLayout.CENTER);

        setVisible(true);
    }

    @Override
    public void run() {
        SimpleDateFormat dateFormat = new SimpleDateFormat("EEE MMM dd HH:mm:ss z yyyy");

        try {
            while (true) {
                Date now = new Date();
                String formattedTime = dateFormat.format(now);

                SwingUtilities.invokeLater(() -> {
                    timeLabel.setText(formattedTime);
                });

                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Time update thread interrupted.");
            Thread.currentThread().interrupt();
        }
    }

    /**
     * Main method to start the application.
     */
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            DateAndTimeApp app = new DateAndTimeApp();

            Thread updateThread = new Thread(app);
            updateThread.start();
        });
    }
}
