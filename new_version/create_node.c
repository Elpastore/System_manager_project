#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct system
{
    char *name;
    char *poste;
    int ID;
    int age;
    int salary;
    struct system *next;
} system_m;

system_m *create(char *name, char *poste, int ID, int age, int salary)
{
    system_m *emp = malloc(sizeof(system_m));
    if (emp == NULL)
    {
        free(emp);
        return (NULL);
    }
    emp->name = strdup(name);
    emp->poste = strdup(poste);
    emp->ID = ID;
    emp->age = age;
    emp->salary = salary;
    emp->next = NULL;

    return (emp);
}
void insert(system_m **head, char *name, char *poste, int ID, int age, int salary)
{
        system_m *new_employee = create(name, poste, ID, age, salary);
        system_m *current;

        if (*head == NULL)/* Check if the list is empty*/
        {
                *head = new_employee;            
        }
        else
        {
            current = *head;
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_employee;
        }
}

void print_list(system_m *head)
{
    system_m *current = head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Poste: %s\n", current->poste);
        printf("ID: %d\n", current->ID);
        printf("Age: %d\n", current->age);
        printf("Salary: %d\n", current->salary);
        printf("\n");

        current = current->next;
    }
}
void add_employee(system_m **head)
{
    char name[100];
    char poste[50];
    int ID;
    int age;
    int salary;
    char password[20] = "elpastore";
    char ask_password[20];

    printf("Please enter the password: ");
    scanf(" %[^\n]", &ask_password);
    if (strcmp(ask_password,password) == 0)
    {
        printf("Enter employee name: ");
        scanf(" %[^\n]", name);
        //scanf("%99s", &name);
        printf("Enter empoyee poste: ");
        scanf(" %[^\n]", poste);
        //scanf("%49s", &poste);
        printf("Enter employee ID: ");
        scanf("%d", &ID);
        printf("Enter employee age: ");
        scanf("%d", &age);
        printf("Enter employee salary: ");
        scanf ("%i",&salary );

        insert(head, name, poste, ID, age, salary);
    }
    else
        printf("Wrong Password!\n");

}
void free_list(system_m *head)
{
    system_m *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next; 
        free(temp->poste);
        free(temp->name);
        free(temp);
    }
}
/**
 * find_info -function that  find info for an employee
 * @head: head of structure
 * @ID_info: the ID of the employee
*/
void find_info(system_m *head, int ID_info)
{
    system_m *current = head;
    int found = 0;

    
    
    
    while (current != NULL)
    {
        if ( ID_info == current->ID)
        {
          found = 1;
            printf("ID found!\n");
            printf("Employee Information:\n");
            printf("Name: %s\n", current->name);
            printf("Poste: %s\n", current->poste);
            printf("ID: %d\n", current->ID);
            printf("Age: %d\n", current->age);
            printf("Salary: %d\n", current->salary);
        }
        current = current->next;
    }
    if (found == 0)
        printf("No corresponnding ID in the base\n");
}

/**

 * delete_nodeint_at_index - deletes the node at index index of list

 * @head: the head of list

 * @index: position

 * Return: 1 if successfull, otherwise -1;

 */

void delete_employee(system_m **head, int ID_info)
{
    system_m *current = *head;
    system_m *prev = NULL;
    system_m *temp;
    int found = 0;
    char password[20] = "elpastore";
    char ask_pass[20];

    printf("Please enter the password: ");
    scanf(" %[^\n]", &ask_pass);
    
    if (strcmp(password, ask_pass) == 0)
    {
        while (current != NULL)
        {
            if (current->ID == ID_info)
            {
                temp = current;
                found = 1;

                if (prev == NULL)
                {
                    // If the node to be deleted is the first node
                    *head = current->next;
                }
                else
                {
                    // Update the next pointer of the previous node
                    prev->next = current->next;
                }

                free(temp->name);
                free(temp->poste);
                free(temp);
                printf("ID found and deleted successfully\n");
                break;  // Exit the loop after deletion
            }

            prev = current;
            current = current->next;
        }

        if (!found)
        {
            printf("ID not found in the list\n");
        }
    }
    else
        printf("\nWrong Password!\n");
}

/**
 * read_file - function that open file for read option
 * @head: head of struct
 * @filename: name of the file
*/
void read_file(system_m **head, char *filename)
{
    FILE *fp = fopen(filename, "r");
    char name[100], poste[50];
    int ID, age, salary;

    if (fp == NULL)
    {
        printf("Opening failed\n");
        return;
    }
    while (fscanf(fp, "%s %s %d %d %d", name, poste, &ID, &age, &salary) == 5)
    {
        insert(head, name, poste,ID, age, salary);
    }
    fclose(fp);
    
}
/**
 * write_file -function that append info in a file
 * @head: head of struc
 * @filename: file name
*/
void write_file(system_m *head, char *filename)
{
    FILE *fp = fopen(filename, "w");
    system_m *current;
    if (fp == NULL)
    {
        printf("Write option failed\n");
        return;
    }
    current = head;
    
    while(current != NULL)
    {
        fprintf(fp,"%s %s %d %d %d\n",current->name, current->poste, current->ID, current->age, current->salary);
        current = current->next;
    }
    fclose(fp);
}
/**
 * main - the enrty point of the program
 * Return: 0 if success
*/
/**
 */
 int main()
{
    
    system_m *head = NULL;
    int choice;
    int ID_info = 0;
    char filename[] = "employee_data.txt";
    do 
    {
        printf("Menu\n");
        printf("Press 1 to add employee\n");
        printf("Press 2 to print the list\n");
        printf("Press 3 to open file\n");
        printf("Press 4 to save file\n");
        printf("Press 5 to search ID employe\n");
        printf("Press 6 to delete a specific ID\n");
        printf("Press 7 to exit\n");
    
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_employee(&head);
            break;
        case 2:
            print_list(head);
            break;
        case 3:
            read_file(&head, filename);
            break;
        case 4:
            write_file(head, filename);
            break;
        case 5:
            printf("Enter the searching ID: \n");
            scanf("%d", &ID_info);
            find_info(head, ID_info);
            break;
        case 6:
            printf("Enter the ID to delete: \n");
            scanf("%d", &ID_info);
            delete_employee(&head, ID_info);
            break;
        case 7:
            printf("Exiting...\n");
            free_list(head);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 7);

    return (0);
}