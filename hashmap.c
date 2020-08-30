#include<stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#define capacity 50
struct node {
    char*key;
    char* value;
    struct node*next;
};
typedef struct node node_t;
node_t * initalize() {
    static node_t map[capacity];
    for (int i=0; i < capacity - 1; i++) {
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
   //     printf("there is nothing here lmao\n");
        return "none";
    }
    else {
        if (map[hashval].key == key) {
             //   printf("Item found! Value is: %s \n", map[hashval].value);
                return map[hashval].value;
        } else {
            node_t * temp = &map[hashval];
            while (temp -> next != NULL) {
                if (temp -> key == key) {
           //     printf("Item found! Value is: %s \n", temp -> value);
                return temp -> value;                    
                }
                temp = temp -> next;
            }
        if (temp -> key == key) {
          //  printf("Item found! Value is: %s \n", temp -> value);
            return temp -> value;                    
            }
        }
      //  printf("something messed up lmao\n");
        return "fail";
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
int delete(node_t map[], char * key) {
  printf("actually write this lmao"); //write this
  return 1;
}
void printMap(node_t map[]) {
  for (int i=0; i < sizeof(*map); i++) {
    printf("%s \n", map[i].value);
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
void writetheory(struct node booktowrite[]) {
    printf("called");
    FILE * fp; 
    fp = fopen ("bookz", "wb");
    if (fp != NULL) {
        fwrite(booktowrite, sizeof(struct node), capacity , fp);
        fclose(fp);
        printf("file opened \n");
    } else {
        printf("something went wrong opening the file\n");
}
}
node_t * readtheory(){
    FILE * fp; 
    static node_t mybooks[capacity];
     fp = fopen ("bookz", "rb");
   // printf("file opened \n");
    if (fp != NULL) {
        fread(&mybooks, sizeof(struct node), capacity, fp);
        fclose(fp);
   //     printf("file opened\n");
       // printf("book title is %s",mybooks[hash("Elam")].value);
    } else {
        printf("something went wrong opening the file\n");
}  return mybooks;
}
int main() {
    // node_t * map = initalize(50);
    // add(map, "Elam", "ganer");
    // add(map, "not elam", "not gamrt");
    // add(map, "d elam", "not d");
    // find("d elam",map);
    // writetheory(map);
   node_t * library = readtheory();
   printf("  _      _ _                          \n | |    (_) |                         \n | |     _| |__  _ __ __ _ _ __ _   _ \n | |    | | '_ \\| '__/ _` | '__| | | |\n | |____| | |_) | | | (_| | |  | |_| |\n |______|_|_.__/|_|  \\__,_|_|   \\__, |\n                                 __/ |\n                                |___/ \n");
   printf("What would you like to do?\n");
   printf("[G]ive a book    --    [R]ead a Book! \n");
   char selection; 
   scanf("%c",&selection);
   if (selection == 'G' || selection == 'g') {
       printf("Great! What is it's title?\n");
       char* title;
       char* content;
       scanf(" %s", &title);
       printf("title: %s", title);
       printf("paste the book here\n");
       scanf(" %s", &content);
       add(library,title,content);
       printf("Thank you for your donation :) \n");
       writetheory(library);
    //   main();
   } else {
       char*ftitle;
       printf("Please enter the title of the book you'd like to read: \n");
       scanf("%s",ftitle);
     //  printf("gamer %s", ftitle);
       find(ftitle,library);
       char* book;
       if (book != (NULL) ) {
           printf("here is your book! \n");
       } else {
           printf("sorry :( we don't have your book");
       }
   }
  return 0;
}