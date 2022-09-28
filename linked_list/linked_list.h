#ifndef __LINKED_LIST__
#define __LINKED_LIST__

struct employee {
    char name[64];
    double salary;
};

/* struct node in linked list */
struct s_node_t {
    struct employee data;
    struct s_node_t *next;
}s_node_t;


void add_employee(struct s_node_t **head, char * new_name, double new_salary);
void del_employee(char *name);


#endif /* __LINKED_LIST__ */