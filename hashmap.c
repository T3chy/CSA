#include<stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
int capacity = 50;
struct node {
    char*key;
    char* value;
    struct node*next;
};
typedef struct node node_t;
node_t * initalize(int size) {
    static node_t map[50];
    for (int i=0; i < 49; i++) {
        map[i].value = "none";
        map[i].next = NULL;
    }
    return map;
}
int hash(char *key) {
    int hashsum = 0;
    int i = 0;
    for(i=0; i < strlen(key); i++) {
        hashsum += (int)key[i];
        hashsum = hashsum % capacity;
    }
    hashsum = hashsum % capacity;
    return hashsum;

}
char* find(char *key, node_t map[]) {
    int hashval = hash(key);
    if (map[hashval].value == "none") {
        printf("there is nothing here lmao\n");
        return "none";
    }
    else {
        if (map[hashval].key == key) {
                printf("Item found! Value is: %s \n", map[hashval].value);
                return map[hashval].value;
        } else {
            node_t * temp = &map[hashval];
            while (temp -> next != NULL) {
                if (temp -> key == key) {
                printf("Item found! Value is: %s \n", temp -> value);
                return temp -> value;                    
                }
                temp = temp -> next;
            }
        if (temp -> key == key) {
            printf("Item found! Value is: %s \n", temp -> value);
            return temp -> value;                    
            }
        }
        printf("something messed up lmao\n");
        return "none";
    }
}
int add(node_t map[], char *key, char *value) {
    int hashval = hash(key);
    if (map[hashval].value == "none") {
        map[hashval].key = key;
       map[hashval].value = value;
       return 0;
    } else {
        struct node * newbruh = (struct node*) malloc(sizeof(struct node)); 
        newbruh -> value = value;
        newbruh -> key = key;
        newbruh -> next = NULL;
        node_t * temporary= &map[hashval];
        while (temporary -> next != NULL) {
            temporary = temporary -> next;
        }
            temporary ->next = newbruh;
        return 1;
    }
}
void printList(struct node *temp) 
{ 
    printf("list items: \n");
  while (temp != NULL) 
  { 
     printf(" %s \n", temp->value); 
     temp = temp->next; 
  } 
} 
void main() {
    node_t * map = initalize(50);
    add(map, "Elam", "fucka");
    add(map, "not elam", "not fucka");
        add(map, "d elam", "not d");
    find("d elam",map);
}