import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import javax.swing.*;

class App extends Store {

  private static DefaultListModel<String> listModel = new DefaultListModel<>();
  private static JList<String> todoList;
  private static String uiFont = "Figtree";

  public static void main(String[] args) {
    JFrame mainFrame = new JFrame("Todo List");
    mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    mainFrame.setSize(500, 500);

    // create a menubar
    JMenuBar menubar = new JMenuBar();
    JMenu menu = new JMenu("Actions");

    // create the menus
    JMenuItem createItem = new JMenuItem("Create Todo");
    createItem.addActionListener(e -> TodoCreateWindow());
    JMenuItem editItem = new JMenuItem("Edit Todo");
    editItem.addActionListener(e -> TodoEditWindow());
    JMenuItem deleteItem = new JMenuItem("Delete Todo");
    deleteItem.addActionListener(e -> TodoDeleteWindow());

    // add the items to the menu
    menu.add(createItem);
    menu.add(editItem);
    menu.add(deleteItem);

    // add menu to the menubar
    menubar.add(menu);
    mainFrame.setJMenuBar(menubar);

    // create a Jlist with the defaultlistmodel and assign to the todolist var
    todoList = new JList<>(listModel);
    todoList.setFont(new Font(uiFont, Font.PLAIN, 15));

    todoList.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);

    // wrap the Jlist in a scrollpane
    JScrollPane scrollPane = new JScrollPane(todoList);
    mainFrame.add(scrollPane, BorderLayout.CENTER);

    refreshTodoList();
    mainFrame.setVisible(true);
  }

  // clear the list model and readd the items
  private static void refreshTodoList() {
    listModel.clear();
    for (Task todo : ReadTasks()) {
      listModel.addElement(todo.ID + " |  " + todo.description);
    }
  }

  private static void TodoCreateWindow() {
    JFrame createFrame = new JFrame("Create Todo");
    createFrame.setSize(400, 200);
    createFrame.setLocationRelativeTo(null);
    createFrame.setFont(new Font(uiFont, Font.PLAIN, 5));

    // create a label for form
    JLabel taskLabel = new JLabel("Task:");
    JTextField taskField = new JTextField(20);
    JButton createButton = new JButton("Create Todo");

    // button action listener override with anonymous class
    // Here we directly create a new interface object and override a method
    createButton.addActionListener(
        new ActionListener() {
          @Override
          public void actionPerformed(ActionEvent e) {
            // create task if input is not empty
            String task = taskField.getText().trim();
            if (!task.isEmpty()) {
              Task ctask = CreateTask(task);
              System.out.println("[INF] created " + ctask);
              refreshTodoList();
              createFrame.dispose(); // close the create window
            } else {
              JOptionPane.showMessageDialog(
                  createFrame, "Please enter a task.", "Error", JOptionPane.ERROR_MESSAGE);
            }
          }
        });

    // add the form to a lable
    JPanel panel = new JPanel();
    panel.add(taskLabel);
    panel.add(taskField);
    panel.add(createButton);

    createFrame.add(panel, BorderLayout.CENTER);
    createFrame.setVisible(true);
  }

  private static void TodoEditWindow() {
    int selectedIndex = todoList.getSelectedIndex();
    if (selectedIndex != -1) {
      JFrame editFrame = new JFrame("Edit Todo");
      editFrame.setSize(400, 200);
      editFrame.setLocationRelativeTo(null);
      editFrame.setFont(new Font(uiFont, Font.PLAIN, 5));

      // get ID
      String itemText = todoList.getModel().getElementAt(selectedIndex);
      String itemID = itemText.split("\\|", 2)[0].trim(); // regex
      System.out.println("[INF] editing " + itemID);

      // get Task
      Task toEdit = ReadTask(itemID);

      // Create form components
      JLabel taskLabel = new JLabel("Task:");
      JTextField taskField = new JTextField(toEdit.description);
      JButton editButton = new JButton("Save");

      editButton.addActionListener(
          new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
              String taskText = taskField.getText().trim();
              if (!taskText.isEmpty()) {
                // save edit
                UpdateTask(itemID, taskText);
                refreshTodoList();
                editFrame.dispose(); // Close the edit window
              } else {
                JOptionPane.showMessageDialog(
                    editFrame, "Please enter a task.", "Error", JOptionPane.ERROR_MESSAGE);
              }
            }
          });

      // Layout for the edit window
      JPanel panel = new JPanel();
      panel.add(taskLabel);
      panel.add(taskField);
      panel.add(editButton);
      editFrame.add(panel, BorderLayout.CENTER);

      editFrame.setVisible(true);
    } else {
      JOptionPane.showMessageDialog(
          null, "Please select a todo to edit.", "Error", JOptionPane.ERROR_MESSAGE);
    }
  }

  // Method to show the Delete Todo window
  private static void TodoDeleteWindow() {
    int selectedIndex = todoList.getSelectedIndex();
    if (selectedIndex != -1) {
      // get ID
      String itemText = todoList.getModel().getElementAt(selectedIndex);
      String itemID = itemText.split("\\|", 2)[0].trim(); // regex
      System.out.println("[INF] editing " + itemID);

      // get Task
      Task toDelete = ReadTask(itemID);

      int confirmation =
          JOptionPane.showConfirmDialog(
              null,
              "Are you sure you want to delete Todo with ID " + toDelete.ID + "?",
              "Delete Todo",
              JOptionPane.YES_NO_OPTION);

      if (confirmation == JOptionPane.YES_OPTION) {
        DeleteTask(itemID);
        refreshTodoList();
      }
    } else {
      JOptionPane.showMessageDialog(
          null, "Please select a todo to delete.", "Error", JOptionPane.ERROR_MESSAGE);
    }
  }
}

// clazz
class Store extends FileOpts {
  static String file = "./store.txt"; // hidden file
  private static String separator = "~~~";

  public static void UpdateTask(String TaskID, String content) {
    TouchFile(file);
    List<Task> tasks = ReadTasks();

    for (int i = 0; i < tasks.size(); i++) {
      if (tasks.get(i).ID.equals(TaskID)) {
        Task t = new Task(TaskID, content);
        tasks.set(i, t);
      }
    }

    String content2 = "";
    for (Task t : tasks) {
      content2 += t.ID + separator + t.description + "\n";
    }

    WriteFile(file, content2);
  }

  public static void DeleteTask(String TaskID) {
    List<Task> tasks = ReadTasks();
    // remove all
    // tasks.removeIf(task -> task.ID.equals(TaskID));

    // NOTE: we are iterating backwards because elements of an array can't be
    // deleted reliably when iterating forward at the same time
    // A better solution would be to use predicate
    for (int i = tasks.size() - 1; i >= 0; i--) {
      if (tasks.get(i).ID.equals(TaskID)) {
        tasks.remove(i);
      }
    }

    String content = "";
    for (Task t : tasks) {
      content += t.ID + separator + t.description + "\n";
    }

    WriteFile(file, content);
  }

  // Create a task and return it
  public static Task CreateTask(String description) {
    TouchFile(file);

    // regenerate the ID if it's already assigned
    String id = GenerateID();
    while (IdExists(id)) {
      id = GenerateID();
    }

    Task task = new Task(id, description);
    AppendFile(file, task.ID + separator + task.description + "\n");
    return task;
  }

  public static List<Task> ReadTasks() {
    List<Task> tasks = new ArrayList<>();

    // return empty list incase file doesn't exist
    if (!FileExists(file)) {
      return tasks;
    }

    List<String> lines = ReadFile(file);

    for (String s : lines) {
      if (s.trim().equals("")) {
        continue; // avoid empty lines
      }
      String[] parts = s.split(separator);
      Task task = new Task(parts[0], parts[1]);
      tasks.add(task);
    }

    return tasks;
  }

  public static Task ReadTask(String ID) {
    for (Task t : ReadTasks()) {
      if (t.ID.equals(ID)) {
        return t;
      }
    }
    return null;
  }

  public static boolean IdExists(String ID) {
    List<Task> tasks = ReadTasks();
    for (Task t : tasks) {
      if (t.ID.equals(ID)) {
        return true;
      }
    }
    return false;
  }

  private static String GenerateID() {
    Random rand = new Random();
    int randomNum = rand.nextInt(999);
    return String.format("T%03d", randomNum);
  }
}

class FileOpts {
  static boolean FileExists(String filepath) {
    File f = new File(filepath);
    if (f.exists() && !f.isDirectory()) {
      return true;
    }
    return false;
  }

  static void AppendFile(String filepath, String line) {
    try {
      FileWriter myWriter = new FileWriter(filepath, true); // true for append mode
      myWriter.write(line);
      myWriter.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  static void WriteFile(String filepath, String content) {
    try {
      FileWriter myWriter = new FileWriter(filepath);
      myWriter.write(content);
      myWriter.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  // Create file if not exists
  static void TouchFile(String filepath) {
    try {
      File fileobj = new File(filepath);
      fileobj.createNewFile();
      // the above method returns a boolean, which is false if the file already exists
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }

  // Read a file into a list
  static List<String> ReadFile(String filepath) {
    List<String> list = new ArrayList<>();
    File file = new File(filepath);

    try {
      Scanner sc = new Scanner(file);
      // keep reading as long as there is a line
      while (sc.hasNextLine()) {
        String line = sc.nextLine();
        list.add(line);
      }
      sc.close();

    } catch (FileNotFoundException e) {
      System.out.println("[Error] could not read file " + file.getAbsolutePath());
      e.printStackTrace();
    }

    return list;
  }
}

class Task {
  public String description;
  public String ID;

  Task(String ID, String description) {
    this.ID = ID;
    this.description = description;
  }
}
