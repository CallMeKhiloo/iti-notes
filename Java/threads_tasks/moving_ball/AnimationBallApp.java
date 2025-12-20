import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class AnimationBallApp extends JFrame implements Runnable {

    private BallPanel ballPanel;
    private Thread animationThread;

    public AnimationBallApp() {
        setTitle("Moving Ball Application");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        ballPanel = new BallPanel();
        add(ballPanel);

        animationThread = new Thread(this);
        animationThread.start();
    }

    @Override
    public void run() {
        while (true) {
            ballPanel.moveBall();

            try {
                SwingUtilities.invokeAndWait(() -> ballPanel.repaint());
            } catch (Exception e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new AnimationBallApp().setVisible(true);
        });
    }

    private class BallPanel extends JPanel {
        private int x, y;
        private int dx, dy;
        private final int DIAMETER = 30;
        private final Color ballColor = Color.RED;

        public BallPanel() {
            setBackground(Color.WHITE);

            Random rand = new Random();
            x = rand.nextInt(400);
            y = rand.nextInt(250);
            dx = rand.nextInt(11) - 5;
            dy = rand.nextInt(11) - 5;

            if (dx == 0)
                dx = 1;
            if (dy == 0)
                dy = 1;
        }

        public void moveBall() {
            int width = getWidth();
            int height = getHeight();

            x += dx;
            y += dy;

            if (x < 0 || x + DIAMETER > width) {
                dx = -dx;
            }

            if (y < 0 || y + DIAMETER > height) {
                dy = -dy;
            }
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            Graphics2D g2d = (Graphics2D) g;
            g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            g2d.setColor(ballColor);
            g2d.fillOval(x, y, DIAMETER, DIAMETER);
        }
    }
}