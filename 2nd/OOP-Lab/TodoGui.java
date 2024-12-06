import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TodoGui {
  public static void main(String[] args) {
    // prepare frame
    JFrame frame = new JFrame();
    PrepareFrame(frame);
    SetTitle(frame);
    DefaultListModel<String> demoList = new DefaultListModel<>();
    SetList(frame, demoList);
    SetInput(frame, demoList);

    // avoid issues
    frame.setVisible(true);
  }

  static void PrepareFrame(JFrame frame) {
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setLayout(new BorderLayout());
    frame.setSize(400, 600);
  }

  static JTextField input;

  static void SetInput(JFrame frame, DefaultListModel<String> demoList) {
    input = new JTextField(20);
    input.setPreferredSize(new Dimension(300, 30));

    JButton addButton = new JButton("Add");
    addButton.setPreferredSize(new Dimension(80, 30));

    // Add functionality to the button
    // Instead of implementing the ActionListener interface in a new class we make use of the
    // anonymous class system
    // In a real class input and defaultListModel would be constructor input
    addButton.addActionListener(
        new ActionListener() {
          @Override
          public void actionPerformed(ActionEvent e) {
            String text = input.getText().trim();
            if (!text.isEmpty()) {
              demoList.addElement(text); // Add the text to the list
              input.setText(""); // Clear the input field
            }
          }
        });

    JPanel panel1 = new JPanel();
    panel1.setLayout(new FlowLayout(FlowLayout.LEFT));
    panel1.add(input);
    panel1.add(addButton);
    panel1.setPreferredSize(new Dimension(300, 40));
    panel1.setBackground(new Color(Paint.OFFWHITE));

    frame.add(panel1, BorderLayout.SOUTH);
  }

  static void SetList(JFrame frame, DefaultListModel<String> demoList) {
    JList<String> list = new JList<>(demoList);
    list.setFont(new Font("Figtree", Font.PLAIN, 20));
    list.setBackground(new Color(Paint.OFFWHITE));
    // wrap the list in a scroll pane
    JScrollPane scrollPane = new JScrollPane(list);

    // add functionality to delete items on click
    list.addMouseListener(
        new MouseAdapter() {
          @Override
          public void mouseClicked(MouseEvent e) {
            int index = list.locationToIndex(e.getPoint());
            if (index != -1) {
              demoList.remove(index); // remove the clicked item
            }
          }
        });

    JPanel panel1 = new JPanel();
    panel1.setLayout(new BorderLayout());
    panel1.add(scrollPane, BorderLayout.CENTER);
    panel1.setBackground(new Color(Paint.OFFWHITE));

    frame.add(panel1, BorderLayout.CENTER);
  }

  static void SetTitle(JFrame frame) {
    JLabel label1 = new JLabel("ToDo App");
    label1.setFont(new Font("Figtree", Font.PLAIN, 30));
    label1.setForeground(Color.BLACK);

    JPanel panel1 = new JPanel();
    panel1.setLayout(new FlowLayout(FlowLayout.LEFT));
    panel1.add(label1);
    panel1.setBackground(new Color(Paint.OFFWHITE));
    panel1.setPreferredSize(new Dimension(100, 60));
    frame.add(panel1, BorderLayout.NORTH);
  }
}

class Paint {
  static int BLACK = 0x414141;
  static int OFFWHITE = 0xfffaf1;
}
