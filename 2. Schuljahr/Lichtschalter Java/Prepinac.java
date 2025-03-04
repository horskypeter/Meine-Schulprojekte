import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Prepinac {
    private JPanel MojPanel;
    private JButton prepinacButton;
    private JLabel mojText;
    private JTextField palindromField;
    private JLabel vystup;
    private boolean isOn;

    private void turnOn() {
        this.isOn = true;
        mojText.setText("Svetlo je zapnute");
        prepinacButton.setText("Zhasni!");
        MojPanel.setBackground(Color.yellow);
//        palindromField.setBackground(Color.pink);
    }

    private void turnOff() {
        this.isOn = false;
        mojText.setText("Svetlo je zhasnute");
        prepinacButton.setText("Zazni");
        MojPanel.setBackground(Color.black);
//        palindromField.setBackground(Color.blue);
    }

    public Prepinac() {
        turnOff();
        prepinacButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String veta=palindromField.getText();
                vystup.setText(veta);
                String reverse = "";
                System.out.println("Zadaj retazec na kontrolu, ci ide o palindrom");
                int length = veta.length();
                for ( int i = length - 1; i >= 0; i-- )
                    reverse = reverse + veta.charAt(i);
                if (veta.equals(reverse))
                    vystup.setText("Zadany retazec je palindrom.");
                else
                    vystup.setText("Zadany retazec nie je palindrom.");


                if(isOn)
                {
                    turnOff();
                }
                else
                {
                    turnOn();
                }
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Moj prvy prepinac");
        frame.setSize(frame.getToolkit().getScreenSize());
        frame.setContentPane(new Prepinac().MojPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
