#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void addpass();
void copypass();

int main(void) {
  bool loop=true;
  // Main loop.
  while(loop) {
    int selection;
    // Main menu.
    printf("What you wanna do\n"
           "1 - Add Password\n"
           "2 - Copy an exsisting password\n"
           "3 - Edit exsisting password\n"
           "4 - Delete Password\n"
           "0 - Exit\n");
    scanf("%d", &selection);
    system("clear");
    // Switch selection
    switch(selection) {
        case 1:
            addpass(); // Call add password.
            break;
        case 2:
            copypass();
            break;
        case 0:
            loop = false; // Exit the main loop.
            break;
        default:
            break;
    }
  }
  
}
// Access to a file with the password and add a raw with the name and the password itself.
void addpass() {
  char pos[] = "Passwords//";
  char filename[100];
  printf("What's the name of the password: ");
  scanf("%s", filename);
  char filepos[100];
  strcpy(filepos,pos);
  strcat(filepos,filename);
  FILE *fptr;
  fptr = fopen(filepos, "w");
  char pass[100];
  char t[100];
  printf("\nWrite the password for %s: ", filename);
  scanf(" %s", pass);
  printf("\nConfirm your password: ");
  scanf(" %s", t);
  fprintf(fptr, "%s",pass);
  fclose(fptr);
  system("clear");
}
// Print all the names of saved password and let the user select the password
// they wanna copy.
void copypass() {
  char pos[] = "Passwords//";
  FILE *fptr;
  printf("\nPassword to copy: ");
  char name[100];
  scanf(" %s", name);
  strcat(pos, name);
  fptr = fopen(pos, "r");
  char copy[100];
  fgets(copy,100,fptr);
  printf("\nHere is your password:\n%s\nPress enter to continue", copy);
  char temp;
  scanf(" %c", &temp);
  system("clear");
}

