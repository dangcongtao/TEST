#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void add_employee(struct s_node_t **head, char * new_name, double new_salary)
{
    struct s_node_t *new_employee = NULL;
    new_employee = (struct s_node_t*)malloc(sizeof(struct s_node_t));

    memset(new_employee->data.name, 0, sizeof(new_employee->data.name));
    strcpy(new_employee->data.name, new_name);
    new_employee->data.salary = new_salary;

    new_employee->next = NULL;

    if (*head == NULL) {
        /**/
        *head = new_employee;
    } else {
        struct s_node_t *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_employee;        
    }
}

void del_employee(char *name)
{
    printf("del employee by name\n");
}
