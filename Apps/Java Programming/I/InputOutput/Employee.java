import java.util.Scanner;

class Employee {
    int EMP_ID;
    String name;
    int EMP_SALARY;

    Employee(int EMP_ID, String name, int EMP_SALARY) {
        this.EMP_ID = EMP_ID;
        this.name = name;
        this.EMP_SALARY = EMP_SALARY;
    }

    
    private int partition(Employee[] arr, int F, int L) {
        int pivot = arr[F].EMP_SALARY;
        int i = F;
        int j = L;

        while (i < j) {
            while (i <= L && arr[i].EMP_SALARY <= pivot) {
                i++;
            }
            while (j >= F && arr[j].EMP_SALARY > pivot) {
                j--;
            }
            if (i < j) {
                
                Employee temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        
        Employee temp = arr[F];
        arr[F] = arr[j];
        arr[j] = temp;

        return j;
    }

   
    public void quicksort(Employee[] arr, int F, int L) {
        if (F < L) {
            int pivotIndex = partition(arr, F, L);
            quicksort(arr, F, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, L);
        }
    }

  
    public void display(Employee[] arr) {
        for (Employee emp : arr) {
            System.out.println("ID: " + emp.EMP_ID + ", Name: " + emp.name + ", Salary: " + emp.EMP_SALARY);
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();
        sc.nextLine();  

        Employee[] e = new Employee[n];

       
        for (int i = 0; i < n; i++) {
            System.out.print("Enter Employee ID, Name, and Salary: ");
            int EMP_ID = sc.nextInt();
            sc.nextLine();  
            String name = sc.nextLine();
            int salary = sc.nextInt();
            e[i] = new Employee(EMP_ID, name, salary);
        }

        
        Employee obj = new Employee(0, "", 0);
        obj.quicksort(e, 0, n - 1);

        /
        System.out.println("Employees sorted by salary:");
        obj.display(e);

        sc.close();
    }
}
