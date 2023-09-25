#include "main.h"
/**
 * create - function that initialise a structure
 * Return: the head
 */
system_m *create(int ID, int age, char *name, char *poste, double salary)
{
	system_m *emp = malloc(sizeof(system_m));
	
	if (emp == NULL)
	{
		printf("allocation failed\n");
		free(emp);
		return (NULL);
	}
	emp->ID = ID;
	emp->name = strdup(name);
	emp->poste = strdup(poste);
	emp->salary = salary;
	emp->age = age;
	emp->next = NULL;

	return (emp);

}
/**
 * insert: function to insert new employee
 */
void insert(system_m **head, int ID, int age,char *name, char *poste, double salary)
{
	system_m *new_emp = create(ID, age, name, poste, salary); 
	system_m *current;
	if (*head == NULL)
	{
		*head = new_emp;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_emp;
	}
}
void print_info(system_m *head)
{
	system_m *current = head;
	while( current != NULL)
	{
		printf("Employee ID: %d\n", current->ID);
		printf("Name: %s\n", current->name);
		printf("Age: %d\n", current->age);
		printf("Position: %s\n", current->poste);
		printf("Salary: %.2lf\n", current->salary);
		printf("\n");
		current = current->next;
	}
}
void addEmployee(system_m **head)
{
	int ID, age;
	char name[100], poste[50];
	double salary;

	/*Prompt the user for employee details*/
	printf("Enter Employee ID: ");
	scanf("%d", &ID);
	printf("Enter Employee Age: ");
	scanf("%d", &age);
	printf("Enter Employee Name: ");
	scanf("%s", name); /*Assumes no spaces in the name*/
	printf("Enter Employee Poste: ");
	scanf("%s", poste); /*Assumes no spaces in the poste*/
	printf("Enter Employee Salary: ");
	scanf("%lf", &salary);
	
	/*Create a new employee structure and add it to the linked list*/
	insert(head, ID, age, name, poste, salary);
	printf("Employee added successfully.\n");
}

/**
 * int main()
*{
*	system_m *head = NULL;
*	insert(&head, 1, 26, "Abdoulaye SADIO", "Directeur General", 2000000.0);
*	insert(&head, 2, 30, "Fode DOUCOURE", "Avocat", 200000.0);
*	insert(&head, 3, 26, "Mamadou DIACK", "Engenieur en BA", 250000.0);
*	print_info(head);
*	free_list(head);
*	
*	return (0);
*
*}
*/
