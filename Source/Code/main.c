#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int addpass();

int main(void) {
  bool loop=true;
  // Main loop
  while(loop) {
    int selection;
    // Main menu
    printf("What you wanna do\n"
           "1 - Add Password\n"
           "2 - Search an exsisting password\n"
           "3 - Delete Password\n"
           "0 - Exit\n");
    scanf("%d", &selection);
    system("clear");
    // Switch selection
    switch(selection) {
        case 1:
            addpass(); // Call add password 
            break;
        case 0:
            loop = false; // Exit the main loop
            break;
        default:
            break;
    }
  }
  
}
// Access to a file with the password and add a raw with the name and the password itself
int addpass(void) {
  FILE *fptr;
  fptr = fopen("passwords.txt", "w");
  if (fptr == NULL) {
    printf("Error");
    exit(1);
  }
  char passname[100];
  printf("Enter the name of the password: ");
  scanf("%s", passname);
  fprintf(fptr, "%s", passname);
  fclose(fptr);
}

