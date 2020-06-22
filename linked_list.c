#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;

struct Tree{
    struct Node* root;
};

struct List{
    struct Node* head;
};

struct Node{
    char name[32];
    struct Node* next;
    struct Node* left;
    struct Node* right;
    struct List list;
};

void init_list(struct List* list);
struct Node* creat_node(char name[]);
void insert_list(struct List* list, char name[]);
void remove_list(struct List* list, char name[]);
struct Node* search_list(struct List* list, char name[]);

void init_list(struct List* list){
    list->head = NULL;
}

struct Node* search_list(struct List* list, char name[]){
    struct Node* ptr = list->head;


    while (ptr != NULL){
        if(strcmp(ptr->name, name) == 0){
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
}

struct Node* creat_node(char name[]){

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (node == NULL){
        return NULL;
    }
    strcpy(node->name, name);
    node->next = NULL;
    node->left = NULL;
    node->right = NULL;
    node->list.head = NULL;
    return node;
}

void insert_list(struct List* list, char name[]){

    struct Node* node = creat_node(name);
    //printf("---\n");
    if(list->head == NULL){
        list->head = node;
        return;
    }
    struct Node* ptr = list->head;
    struct Node* pre_ptr = list->head;

    if(strcmp(name, ptr->name) < 0){
        list->head = node;
        node->next = ptr;
        return;
    }
    while (ptr != NULL){

        if(strcmp(name, ptr->name) < 0){
            break;
        }

        pre_ptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL){
        pre_ptr->next = node;
    } else{
        pre_ptr->next = node;
        node->next = ptr;
    }
}
void remove_list(struct List* list, char name[]){

    if(list->head == NULL){
        return;
    }
    struct Node* ptr = list->head;
    struct Node* pre_ptr = list->head;

    if(ptr == NULL){
        return;
    }
    if(strcmp(ptr->name, name) == 0){
        list->head = ptr->next;
        free(ptr);
        pre_ptr = NULL;
        return;
    }
    while (ptr != NULL){
        if(strcmp(name, ptr->name) == 0){
            break;
        }
        pre_ptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL){
        return;
    }
    pre_ptr->next = ptr->next;
    free(ptr);
}

void print_list(struct List* list){
    struct Node* ptr = list->head;
    if(ptr == NULL){
        printf("No user in the database\n");
        return;
    }
    while (ptr != NULL){
        printf("name: %s\n", ptr->name);
        struct Node* rl = ptr->list.head;
        if(rl == NULL){
            printf("No relationship\n");
        }else{
            printf("\thas relationship with: ");
            while (rl != NULL){
                printf("%s, ", rl->name);
                rl = rl->next;
            }
            printf("\n");
        }
        ptr = ptr->next;
    }
}

void save_list(struct List* list, FILE* file){
    struct Node* ptr = list->head;
    if(ptr == NULL){
        //printf("No user in the database\n");
        return;
    }
    while (ptr != NULL){
        fputs(ptr->name, file);
        struct Node* rl = ptr->list.head;
        if(rl == NULL){
            fputs("\n", file);
        }else{
            while (rl != NULL){
                fputs(",", file);
                fputs(rl->name, file);
                rl = rl->next;
            }
            fputs("\n", file);
        }
        ptr = ptr->next;
    }
    printf("save successfully\n");
}

void delete_list(struct List* list){

    struct Node* ptr = list->head;
    while (ptr != NULL){
        struct Node* rl = ptr->list.head;
        while (rl != NULL){
            struct Node* temp = rl;
            rl = rl->next;
            free(temp);
        }
        struct Node* temp = ptr;
        ptr = ptr->next;

        printf("delete: %s\n", temp->name);
        free(temp);
    }
}

void load_list(struct List* list, FILE* file){
    char *line,*record;
    char buffer[1024];
    int flg = 0;
    struct Node* temp = NULL;
    while ((line = fgets(buffer, sizeof(buffer), file))!=NULL)
    {
        if(line[strlen(line)-1] == '\n'){
            line[strlen(line)-1] = '\0';
        }

        flg = 0;
        record = strtok(line, ",");
        while (record != NULL)
        {
            if(flg == 0){
                insert_list(list, record);
                temp = search_list(list, record);
                flg = 1;
            } else{
                insert_list(&temp->list, record);
            }
            record = strtok(NULL, ",");
        }
    }
}


void init_tree(struct Tree* tree){
    tree->root = NULL;
}

struct Node* insert_tree(struct Node* root, char name[]){

    if(root == NULL){
        struct Node* node = creat_node(name);
        root = node;
    } else if(strcmp(name, root->name) > 0){
        root->right = insert_tree(root->right, name);
    } else{
        root->left = insert_tree(root->left, name);
    }

    return root;
}

struct Node* remove_tree(struct Node* root, char name[]){
    if(root){
        if(strcmp(name, root->name) > 0){
            root->right = remove_tree(root->right, name);
        } else if(strcmp(name, root->name) < 0){
            root->left = remove_tree(root->left, name);
        } else{
            if(root->right != NULL && root->left != NULL){
                struct Node* min = root->right;

                while (min->left != NULL){
                    min = min->left;
                }
                if(min != NULL){
                    strcpy(root->name, min->name);
                    root->right = remove_tree(root->right, min->name);
                }
            } else{
                struct Node* temp = root;

                if(root->right != NULL){
                    root = root->right;
                } else if(root->left != NULL){
                    root = root->left;
                }
                if(root == temp){
                    root = NULL;
                }
                free(temp);
                temp = NULL;
            }
        }
        return root;
    }
}


struct Node* search_tree(struct Node* root, char name[]){
    if(root != NULL){
        if(strcmp(root->name, name) == 0){
            return root;
        } else if(strcmp(root->name, name) > 0){
            return search_tree(root->left, name);
        } else{
            return search_tree(root->right, name);
        }
    }

    return NULL;
}

void inorder(struct Node* node){
    if(node == NULL){
        return;
    } else{
        inorder(node->left);
        printf("name: %s\n", node->name);
        struct Node* rl = node->list.head;
        if(rl == NULL){
            printf("No relationship\n");
        }else{
            printf("\thas relationship with: ");
            while (rl != NULL){
                printf("%s, ", rl->name);
                rl = rl->next;
            }
            printf("\n");
        }

        inorder(node->right);

    }
}

void print_tree(struct Tree* tree){

    struct Node* ptr = tree->root;

    inorder(ptr);
}

struct Node* inorder_delete_tree(struct Node* node){
    if(node == NULL){
        return NULL;
    }
    node->left = inorder_delete_tree(node->left);
    node->right = inorder_delete_tree(node->right);

    if(node->left==NULL && node->right == NULL){

        struct Node* rl = node->list.head;
        while (rl != NULL){
            struct Node* temp = rl;
            rl = rl->next;
            free(temp);
        }
        printf("delete: %s\n", node->name);
        free(node);
        return NULL;
    }
    return node;
}

void delete_tree(struct Tree* tree){
    struct Node* root = tree->root;
    root = inorder_delete_tree(root);
    free(root);
}

void load_tree(struct Tree* tree, FILE* file){
    char *line,*record;
    char buffer[1024];
    int flg = 0;
    struct Node* temp = NULL;
    while ((line = fgets(buffer, sizeof(buffer), file))!=NULL)
    {
        if(line[strlen(line)-1] == '\n'){
            line[strlen(line)-1] = '\0';
        }

        flg = 0;
        record = strtok(line, ",");
        while (record != NULL)
        {
            if(flg == 0){
                tree->root = insert_tree(tree->root, record);
                temp = search_tree(tree->root, record);
                flg = 1;
            } else{
                insert_list(&temp->list, record);
            }
            record = strtok(NULL, ",");
        }
    }
}

void inorder_save_tree(struct Node* node, FILE* file){
    if(node == NULL){
        return;
    } else{
        inorder_save_tree(node->left, file);
        fputs(node->name, file);
        struct Node* rl = node->list.head;
        if(rl == NULL){
            fputs("\n", file);
        }else{
            while (rl != NULL){
                fputs(",", file);
                fputs(rl->name, file);
                rl = rl->next;
            }
            fputs("\n", file);
        }

        inorder_save_tree(node->right, file);
    }
}

void save_tree(struct Tree* tree, FILE* file){
    inorder_save_tree(tree->root, file);
}


int main(int argc, char** argv) {
    if(argc != 4){
        printf("error input args, should be 'tree/list save_filename load_filename'\n");
        return -1;
    }
    char type[16];
    char filename[512];
    char load_filename[512];

    strcpy(type, argv[1]);
    strcpy(filename, argv[2]);
    strcpy(load_filename, argv[3]);

    struct List list;
    struct Tree tree;
    init_list(&list);
    init_tree(&tree);

    while (1){
        printf("\n1) Introduce user\n");
        printf("2) Introduce relationship/friendship\n");
        printf("3) Remove user\n");
        printf("4) Print user information\n");
        printf("5) Print report for all users (all information)\n");
        printf("6) Save to file\n");
        printf("7) Retrieve data from file\n");
        printf("8) Exit\n\n");

        int choice;
        printf("input your choice: ");
        scanf("%d", &choice);

        // insert
        if(choice == 1){

            printf("\nPlease input the user name: ");
            char name[32];
            scanf("%s", name);
            if(strcmp("list", type) == 0){
                if(search_list(&list, name)){
                    printf("error: the user is existed\n");
                } else{
                    insert_list(&list, name);
                }
            } else if(strcmp("tree", type) == 0){
                if(search_tree(tree.root, name)){
                    printf("error: the user is existed\n");
                } else{
                    tree.root = insert_tree(tree.root, name);
                }
            }

        } else if(choice == 2){

            char name1[32];
            char name2[32];
            printf("\nPlease input the first user name: ");
            scanf("%s", name1);

            printf("\nPlease input the second user name: ");
            scanf("%s", name2);
            struct Node* node1 = NULL;
            struct Node* node2 = NULL;
            if(strcmp("list", type) == 0){
                node1 = search_list(&list, name1);
                node2 = search_list(&list, name2);
            } else if(strcmp("tree", type) == 0){
                node1 = search_tree(tree.root, name1);
                node2 = search_tree(tree.root, name2);
            }

            if(node1 == NULL && node2 == NULL) {
                printf("\n");
                printf("error: %s and %s are not in the database\n", name1, name2);
            } else if(node1 == NULL) {
                printf("\n");
                printf("error: %s is not in the database\n", name1);
                if(search_list(&node2->list, name1)){
                    printf("error: there is a relationship in %s relationship\n", name2);
                } else{
                    //insert_list(&node1->list, node2->name);
                    insert_list(&node2->list, name1);
                    printf("insert %s into %s relationships\n", name1, name2);
                }

            }else if(node2 == NULL){
                if(search_list(&node1->list, name2)){
                    printf("error: there is a relationship in %s relationship\n", name1);
                } else{
                    //insert_list(&node1->list, node2->name);
                    insert_list(&node1->list, name2);
                    printf("insert %s into %s relationships\n", name2, name1);
                }
                printf("error: %s is not in the database\n", name2);

            } else{
                if(search_list(&node1->list, node2->name)){
                    printf("error: there is a relationship with them\n");
                } else{
                    insert_list(&node1->list, node2->name);
                    printf("insert %s into %s relationships\n", name2, name1);
                    insert_list(&node2->list, node1->name);
                    printf("insert %s into %s relationships\n", name1, name2);
                }
            }

        } else if(choice == 3){
            printf("\nPlease input the removing user name: ");
            char name[32];
            scanf("%s", name);

            if(strcmp("list", type) == 0){
                remove_list(&list, name);
            } else if(strcmp("tree", type) == 0){
                tree.root = remove_tree(tree.root, name);
            }
        } else if(choice == 4){
            printf("\nPlease input the searching user name: ");
            char name[32];
            scanf("%s", name);
            struct Node* node = NULL;
            if(strcmp("list", type) == 0){
                node = search_list(&list, name);
            } else if(strcmp("tree", type) == 0){
                node = search_tree(tree.root, name);
            }

            if(node == NULL){
                printf("No such student\n");
            } else{
                printf("name: %s\n", node->name);
                struct Node* rl = node->list.head;
                if(rl == NULL){
                    printf("No relationship\n");
                }else{
                    printf("\thas relationship with: ");
                    while (rl != NULL){
                        printf("%s, ", rl->name);
                        rl = rl->next;
                    }
                    printf("\n");
                }
            }

        } else if(choice == 5){
            if(strcmp("list", type) == 0){
                print_list(&list);
            } else if(strcmp("tree", type) == 0){
                print_tree(&tree);
            }

        } else if(choice == 6){
            FILE* file = fopen(filename, "w");

            if(strcmp("list", type) == 0){
                save_list(&list, file);
                fflush(file);
            } else if(strcmp("tree", type) == 0){
                save_tree(&tree, file);
                fflush(file);
            }

            fclose(file);


        } else if(choice == 7){
            FILE* load_file = fopen(load_filename, "r");
            if(strcmp("list", type) == 0){

                delete_list(&list);

                list.head = NULL;

                load_list(&list, load_file);
                fflush(load_file);
            } else if(strcmp("tree", type) == 0){
                delete_tree(&tree);

                tree.root = NULL;

                load_tree(&tree, load_file);

                fflush(load_file);

            }

            fclose(load_file);

        } else if(choice == 8){
            if(strcmp("list", type) == 0){
                delete_list(&list);
                list.head = NULL;
            } else if(strcmp("tree", type) == 0){
                delete_tree(&tree);
                tree.root = NULL;
            }

            break;
        }
    }

    return 0;
}