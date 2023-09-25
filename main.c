#include "main.h"
/**
 * main - entry point of the program
 * Return: 0 if success otherwise 0;
 */
int main()
{
	system_m *head = NULL;
	int choice;
	char filename[] = "employee_data.txt";

	do {
		printf("Menu :\n");
		printf("1. Read employee data from file\n");
		printf("2. Add a new employee\n");
		printf("3. Display employee information\n");
		printf("4. Save employee data to file\n");
		printf("5. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				read_from(&head, filename);
				break;
			case 2:
				addEmployee(&head);
				break;
			case 3:
				print_info(head);
				break;
			case 4:
				write_from(head, filename);
				break;
			case 5:
				free_list(head);
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while(choice != 5);
	return (0);
}
