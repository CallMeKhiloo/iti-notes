import javax.swing.*;
import java.awt.*;

public class MovingString extends JFrame implements Runnable {
    private int x = 0;
    private int y = 100;

    private String message = "Hello, World!";

    private DrawingPanel panel;

    public MovingString() {
        setTitle("Moving String Application");
        setSize(500, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        panel = new DrawingPanel();
        add(panel);

        setVisible(true);
    }

    private class DrawingPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            g.setFont(new Font("Arial", Font.BOLD, 20));
            g.setColor(Color.BLUE);
            g.drawString(message, x, y);
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                x += 5;

                if (x > panel.getWidth()) {
                    x = 0;
                }

                SwingUtilities.invokeLater(() -> {
                    panel.repaint();
                });

                Thread.sleep(10);

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            MovingString app = new MovingString();

            Thread animationThread = new Thread(app);
            animationThread.start();
        });
    }
}