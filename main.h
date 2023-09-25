#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct sytem - structure that store employees info
 * @name: name of employee
 * @ID: the numeric identification
 * @age: age of employee
 * @salary: salary of employee
 * @poste: poste of employee
 * @next: pointer to the next address
 */
typedef struct system
{
	char *name;
	int ID;
	int age;
	char *poste;
	double salary;
	struct system  *next;
} system_m;

void free_list(system_m *head);
void write_from(system_m *head, const char *filename);
void read_from(system_m **head, const char *filename);
system_m *create(int ID, int age, char *name, char *poste, double salary);
void insert(system_m **head, int ID, int age,char *name, char *poste, double salary);
void print_info(system_m *head);
void addEmployee(system_m **head);

#endif
