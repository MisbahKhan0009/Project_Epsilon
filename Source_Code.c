#include <stdio.h>
#include <string.h>
#include <unistd.h> // #include <windows.h> in windows//

#define RED "\e[31m"
#define YELLOW "\e[33m"
#define COLOR_RESET "\e[0m"
#define BOLD "\e[1m"
#define BOLD_RESET "\e[m"

void loading() {
  for (int seq = 0; seq < 2; seq++) {
    for (int dot = 0; dot < 4; dot++) {
      printf("\rLoading%.*s   \b\b\b", dot, "...");
      fflush(stdout);
      sleep(1); // Sleep(1000) in windows
    }
  }
  printf("\n");
}
void terminate() {
  printf("\nThis program will now be terminated. Please be patient.\n\n");
}
void terminate2() {
  printf("\nProgram successfully terminated. Thanks for being with us!\n\n");
}

struct user {
  char ID[20];
  char account[100];
  char password[100];
  int balance;
} usr;

struct Admin {
  char Name[20];
  char account[100];
  char password[100];
} admin;

int main() {
  int opt, opts, ad_opt, choice, admin_choice, amount;
  FILE *fp;
  FILE *fpa;
  FILE *fpb;
  char filename[100], ID[50], password[50], ad_name[50], ad_password[50], a[100], number[100];
   

  printf(YELLOW BOLD
         "\n\t\t+-------------------------+" BOLD_RESET COLOR_RESET);
  printf(YELLOW BOLD
         "\n\t\t|Welcome to NSU Print Zone|\n" BOLD_RESET COLOR_RESET);
  printf(YELLOW BOLD "\t\t+-------------------------+" BOLD_RESET COLOR_RESET);
  printf("\nPlease choose a option:");
  printf("\n\n1. I am a student.");
  printf("\n2. I am an admin.");
  printf("\n\nPlease enter your choice: ");
  scanf("%d", &opts);

  if (opts == 1) {
    printf("\nPlease choose a option:");
    printf("\n\n1. Create a new account.");
    printf("\n2. Login to an existing account.");
    printf("\n3. Exit.");

    printf("\n\nPlease enter your choice: ");

    scanf("%d", &opt);

    if (opt == 1) {

      printf("Enter your account number: ");
      scanf("%s", usr.account);

      printf("Enter your ID number: ");
      scanf("%s", usr.ID);

      printf("Enter your password: ");

      scanf("%s", usr.password);

      usr.balance = 200;

      stpcpy(filename, usr.account);
      fp = fopen(strcat(filename, ".dat"), "w");
      fwrite(&usr, sizeof(struct user), 1, fp);

      loading();

      if (&fwrite != NULL) {
        printf("\nAccount successfully created.\n");
      } else {
        printf("\nError creating account.\n");
      }
    }

    else if (opt == 2)

    {

      printf("\nPlease Enter your ID number: ");
      scanf("%s", ID);
      printf("Please enter your password: ");
      scanf("%s", password);
      fp = fopen(strcat(ID, ".dat"), "r");
      if (fp == NULL) {
        printf("\nAccount not found\n");
      }

      else {
        fread(&usr, sizeof(struct user), 1, fp);
        fclose(fp);
        if (!strcmp(password, usr.password)) {
          printf(RED BOLD
                 "\n\t\t+-------------------------+" BOLD_RESET COLOR_RESET);
          printf(RED BOLD
                 "\n\t\t|Welcome to your account  |\n" BOLD_RESET COLOR_RESET);
          printf(RED BOLD
                 "\t\t+-------------------------+" BOLD_RESET COLOR_RESET);
          printf("\n1. See remaining pages");
          printf("\n2. Add pages");
          printf("\n3. print pages");
          printf("\n4. Exit");
          printf("\n\nPlease enter your choice: ");
          scanf("%d", &choice);
          printf("\n");

          switch (choice) {
          case 1: {
            loading();
            printf("You have %d pages remaining.\n", usr.balance);
            break;
          }

          case 2:
            printf("Please Enter the amount to be added(Please note 1 that "
                   "page cost 1tk): ");
            scanf("%d", &amount);
            usr.balance = usr.balance + amount;
            fp = fopen(ID, "w");
            fwrite(&usr, sizeof(struct user), 1, fp);
            if (&fwrite != NULL) {
              loading();
              printf("You have added %d pages in your account, your current "
                     "printable pages are %d pages\n",
                     amount, usr.balance);
            }
            fclose(fp);
            break;

          case 3:
            printf("How many page you want to print: ");
            scanf("%d", &amount);

            if (amount > usr.balance) {
              printf("\nSorry You don't have enough page left\n'");
            } else if (amount > 50) {
              printf("\nSorry You can't print over 50 pages at a time.\n");
            } else {
              usr.balance = usr.balance - amount;
              fp = fopen(ID, "w");
              fwrite(&usr, sizeof(struct user), 1, fp);
              if (&fwrite != 0) {
                loading();
                printf("\nYou printed %d pages, and now your remaininhg pages "
                       "are %d pc\n",
                       amount, usr.balance);
              }

              fclose(fp);
            }
            break;

          case 4: {

            terminate2();
          }
          }
        }
      }
    } else if (opt == 3) {

      terminate();
      loading();
      terminate2();
    }
    printf("\n");
    return 0;
  } else if (opts == 2) {
    printf("\nPlease choose a option:");
    printf("\n\n1. Create new admin account.");
    printf("\n2. Login to admin account.");
    printf("\n3. Exit.");
    printf("\nEnter choice: ");
    scanf("%d", &ad_opt);

    if (opt == 1) {

      printf("Enter your Name: ");
      scanf("%s", admin.Name);

      printf("Enter your account number: ");
      scanf("%s", admin.account);

      printf("Enter your password: ");

      scanf("%s", admin.password);

      usr.balance = 200;

      fpa = fopen("admin.dat", "w");
      fwrite(&admin, sizeof(struct Admin), 1, fpa);

      loading();

      if (&fwrite != NULL) {
        printf("\nAccount successfully created.\n");
      } else {
        printf("\nError creating account.\n");
      }
    }

    else if (ad_opt == 2)

    {

      printf("\nPlease Enter your name: ");
      scanf("%s", ad_name);
      printf("Please enter your password: ");
      scanf("%s", ad_password);
      fpa = fopen("admin.dat", "r");
      if (fpa == NULL) {
        printf("\nAccount not found\n");
      } else {
        fread(&admin, sizeof(struct Admin), 1, fpa);
        fclose(fpa);
        if (!strcmp(ad_password, admin.password)) {
          printf(RED BOLD
                 "\n\t\t+-------------------------+" BOLD_RESET COLOR_RESET);
          printf(RED BOLD
                 "\n\t\t|Welcome to your account  |\n" BOLD_RESET COLOR_RESET);
          printf(RED BOLD
                 "\t\t+-------------------------+" BOLD_RESET COLOR_RESET);
          printf("\n1. See student details");
          printf("\n2. Add student manually");
          printf("\n3. Exit");
          printf("\n\nPlease enter your choice: ");
          scanf("%d", &admin_choice);
          printf("\n");

          if (admin_choice == 1) {
           
            printf("Please Enter student account number: ");
            scanf("%s", number);

           
            strcpy(filename, number);
            fpb = fopen(strcat(filename, ".dat"), "r");
            if (fpb == NULL) {
              printf("File is not available!!!");
            } else {
              fread(a, sizeof(char), 100, fpb);
            }

            for (int i = 0; i < 10; i++) {
              printf("%c", a[i]);
            }
          } else if (admin_choice == 2) {

            printf("Enter Students account number: ");
            scanf("%s", usr.account);

            printf("Enter Students ID number: ");
            scanf("%s", usr.ID);

            printf("Enter Students password: ");

            scanf("%s", usr.password);

            usr.balance = 200;

            stpcpy(filename, usr.account);
            fp = fopen(strcat(filename, ".dat"), "w");
            fwrite(&usr, sizeof(struct user), 1, fp);

            loading();

            if (&fwrite != NULL) {
              printf("\nAccount successfully created.\n");
            } else {
              printf("\nError creating account.\n");
            }
          } else if (admin_choice == 3) {

            terminate();
            loading();
            terminate2();
          }
        }
      }
      printf("\n");
      return 0;
    }
  }
}
