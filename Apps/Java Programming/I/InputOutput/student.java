import java.util.Scanner;

class Student {
    String name;
    int roll;
    int cgpa;

    // Constructor
    Student(String n, int r, int c) {
        name = n;
        roll = r;
        cgpa = c;
    }

    // Method to get data from the user
    void getdata(Student s[], int n) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the name: ");
            String name = sc.next();
            System.out.print("Enter the roll no: ");
            int roll = sc.nextInt();
            System.out.print("Enter CGPA: ");
            int cgpa = sc.nextInt();
            s[i] = new Student(name, roll, cgpa); // Create and store the student object
        }
    }

    // Method to perform shell sort based on the student names
    void shell(Student s[], int n) {
        int gap = n / 2;
        while (gap >= 1) {
            for (int j = gap; j < n; j++) {
                for (int i = j - gap; i >= 0; i -= gap) {
                    if (s[i].name.compareTo(s[i + gap].name) > 0) { // Use compareTo for string comparison
                        Student temp = s[i + gap];
                        s[i + gap] = s[i];
                        s[i] = temp;
                    } else {
                        break;
                    }
                }
            }
            gap = gap / 2;
        }
    }

    // Method to perform insertion sort based on the student names
    void insertion(Student s[], int n) {
        for (int i = 1; i < n; i++) {
            Student key = s[i];
            int j = i - 1;

            // Move elements of s[0..i-1], that are greater than key.name, to one position ahead of their current position
            while (j >= 0 && s[j].name.compareTo(key.name) > 0) {
                s[j + 1] = s[j];
                j = j - 1;
            }
            s[j + 1] = key;
        }
    }

    // Main method
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = sc.nextInt(); // Initialize `n`

        Student[] s = new Student[n]; // Initialize the student array

        Student x = new Student("", 0, 0); // Create an instance of `Student` to use the methods

        x.getdata(s, n); // Get data from the user

        System.out.println("Choose sorting method:");
        System.out.println("1. Shell Sort");
        System.out.println("2. Insertion Sort");
        int choice = sc.nextInt(); // User selects sorting method

        switch (choice) {
            case 1:
                x.shell(s, n); // Sort the data using Shell sort
                break;
            case 2:
                x.insertion(s, n); // Sort the data using Insertion sort
                break;
            default:
                System.out.println("Invalid choice. Defaulting to Shell Sort.");
                x.shell(s, n); // Default to Shell sort
                break;
        }

        System.out.println("Sorted student list based on names:");
        for (int i = 0; i < n; i++) {
            System.out.println("Name: " + s[i].name + ", Roll: " + s[i].roll + ", CGPA: " + s[i].cgpa);
        }
    }
}
