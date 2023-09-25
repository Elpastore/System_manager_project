#include "main.h"
/**
 * read_from - function open and read the contain of file
 * @head: head of structure
 * @filename: name of file
 */
void read_from(system_m **head, const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Failed to open file for reading\n");
		return;
	}
	int ID, age;
	char name[100], poste[50];
	double salary;

	while (fscanf(file, "%d %d %99s %49s %lf", &ID, &age, name, poste, &salary) == 5)
	{
		insert(head, ID, age, name, poste, salary);
	}
	fclose(file);
}
/**
 * write_from - function to display the contain of file
 * @head: the head of the structure
 * @filename: name of the file
 */
void write_from(system_m *head, const char *filename)
{
	FILE *file = fopen(filename, "a");
	system_m *current;
	if(file == NULL)
	{
		printf("Failed to open file for writing.\n");
		return;
	}
	current = head;
	while(current != NULL)
	{
		fprintf(file, "%d %d %s %s %.2lf\n", current->ID, current->age, current->name, current->poste, current->salary);
		current = current->next;
	}
	fclose(file);

}
