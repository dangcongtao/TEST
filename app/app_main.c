#include <stdio.h>
#include "linked_list.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


static struct s_node_t *gs_head = NULL;

/* number of Employee */
static uint8_t gs_num_em = 0;

enum APP_ENUM {
    START = 0,
    ADD,
    DEL, /* delete employee by name */
    LIST, /* list employee by salary */
    SHOW, /* print all empployee */
    CLEAR, /* go to "homepage" */
    EXIT, /* exit app */
};


int main() {
    struct s_node_t *node_temp = NULL;
    
    int user_opt = 0;
    char name[40];
    char temp;
    double salary = 0;
    uint8_t exit = 0;
    uint8_t just_added = 0;
    uint8_t just_del = 0;


    while (1)
    {
        if (exit) {
            break;
        }

        /* add */
        switch (user_opt)
        {
        case START:{
            system("clear");
            printf(" ************* created by taodc *************\n");
            printf(" ********************************************\n");
            printf(" ********************************************\n");
            printf("\n");
            if (just_added) {
                printf(" ************* add an Employee success *************\n");
                just_added = 0;
            }
            if (just_del) {
                printf(" ************* del an Employee success *************\n");
                just_del = 0;
            }

            printf(" ************* Type: \n");
            printf("                       1: to add employee  \n");
            printf("                       2: to delete employee by name \n");
            printf("                       3: to find salary by name \n");
            printf("                       4: to show all \n");
            printf("                       5: to clear your screen \n");
            printf("                       6: to exit \n");



            printf("select your option: ");
            scanf("%d", &user_opt);
            scanf("%c", &temp); /**/
            break;
        }

        case ADD: {
            system("clear");
            printf(" ************* add an Employee *************\n\n");

            printf("name: ");
            memset(name, 0, sizeof(name));
            scanf("%[^\n]", name);
            
            printf("salary: ");
            scanf("%lf", &salary);
            scanf("%c", &temp); /**/

            /**/
            add_employee(&gs_head, name, salary);
            gs_num_em++;

            just_added = 1;
            user_opt = 0;
            break;
        }

        case DEL: {
            system("clear");
            printf(" ************* del an Employee *************\n\n");

            printf("name: ");
            memset(name, 0, sizeof(name));
            scanf("%[^\n]", name);

            node_temp = gs_head;
            struct s_node_t *node_del = NULL;

            if (strcmp(gs_head->data.name, name) == 0) {
                node_del = gs_head;
                gs_head = gs_head->next;
            } else {
                for (uint8_t i = 1; i < gs_num_em; i++) {
                    if (strcmp(node_temp->next->data.name, name) == 0) {
                        node_del = node_temp->next;
                        node_temp->next = node_del->next;
                        
                        /* free node */
                        free(node_del);
                        
                        just_del = 1;
                        break;
                    }
                    printf("Delete success\n");
                    node_temp = node_temp->next;
                }
            }

            gs_num_em--;
            
            user_opt = 0;
            break;
        }
        case LIST: {
            system("clear");
            printf(" ************* find Employee by salary *************\n\n");

            printf("type salary: ");
            scanf("%lf", &salary);
            scanf("%c", &temp);

            printf("\n");
            node_temp = gs_head;
            for (uint8_t i = 0; i < gs_num_em; i++) {
                if (node_temp->data.salary == salary) {
                    printf("name: %s\n", node_temp->data.name);
                    printf("salary: %.2lf\n", node_temp->data.salary);

                    printf("\n");

                }
                node_temp = node_temp->next;
            }

            printf(" ************* hit anykey *************\n");
            scanf("%c", &temp);
            user_opt = 0;
            break;
        }

        case SHOW: {
            system("clear");
            node_temp = gs_head;
            for (uint8_t i = 0; i < gs_num_em; i++) {
                printf("name: %s\n", node_temp->data.name);
                printf("salary: %.2lf\n", node_temp->data.salary);

                printf("\n");
                node_temp = node_temp->next;
            }

            printf(" ************* hit anykey *************\n");
            scanf("%c", &temp);
            user_opt = 0;
            break;
        }
        
        case CLEAR:{
            system("clear");
            user_opt = 0;
            break;
        }

        case EXIT: {
            system("clear");
            printf(" ************* shut down *************\n");
            exit = 1;
            break;
        }
        default:
            break;
        }


    }
    
    

    return 0;
}