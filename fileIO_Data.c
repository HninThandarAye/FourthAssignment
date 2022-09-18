//Created by Hnin Thandar Aye


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void pressOne();
void pressTwo();
void pressThree();

FILE *userData = NULL;

struct DataBank{
  int userId;
  char username[50];
  int password;
  int amount;
  int userAge;
  char location[100];
}user;

int pressNumber = 0;
int userNumbers = 0;
char userNameGet[50];
char userNameSearch[50];

int main(){

printf("Press 1 to insert data.\nPress 2 to find data.\nPress 3 to update data.\n");
scanf("%d",&pressNumber);

switch (pressNumber){

  case 1:
    pressOne();
    break;

  case 2:
    pressTwo();
    break;

  case 3:
    pressThree();
    break;

return 0;
}
}

void pressOne(){

userData = fopen("data.txt","a+");

if(userData == NULL){
    printf("\nThere is no file.\n");
    exit(1);
}else{
    printf("\nThere is a file.\n");
}

printf("\nHow many Users would you like to insert? ");
scanf("%d",&userNumbers);

for(int i = 0; i < userNumbers; i++){

   printf("\nInsert data for user %d.\n\n",i+1);

   printf("Enter User Id:");
   scanf("%d",&user.userId);

   printf("Enter User Name:");
   scanf("%s",user.username);

   printf("Enter Password:");
   scanf("%d",&user.password);

   printf("Enter Amount:");
   scanf("%d",&user.amount);

   printf("Enter User Age:");
   scanf("%d",&user.userAge);

   printf("Enter Location:");
   scanf(" %s",user.location);

fprintf(userData,"%d   %s   %d   %d   %d   %s\n",user.userId,user.username,user.password,user.amount,user.userAge,user.location);
}

if (userData != NULL){
   fclose(userData);
}
}

void pressTwo(){

   userData = fopen("data.txt","r");

if(userData == NULL){
   printf("\nDatabase is empty.\n");
   exit(1);
}else{
   printf("\nDatabase is found.\n");
}

printf("Press any key to find data: ");
scanf("%s",&userNameSearch);

while(!feof(userData)){

  int readFile = fgets(userNameGet,"%s",userData);
  if (readFile > 0){
    printf("%s\n",userNameGet);
}
}

if (userData != NULL){
    fclose(userData);
}
}

void pressThree(){

userData = fopen("data.txt","r");

if(userData == NULL){
   printf("\nDatabase is empty.\n");
   exit(1);
}else{
   printf("\nDatabase is found.\n");
}

userData = fopen("data.txt","a+");

printf("\n\nUpdate data for a user.\n\n");

printf("Enter User Id:");
scanf("%d",&user.userId);

printf("Enter User Name:");
scanf("%s",user.username);

printf("Enter Password:");
scanf("%d",&user.password);

printf("Enter Amount:");
scanf("%d",&user.amount);

printf("Enter User Age:");
scanf("%d",&user.userAge);

printf("Enter Location:");
scanf(" %s",user.location);

fprintf(userData,"%d   %s   %d   %d   %d   %s\n",user.userId,user.username,user.password,user.amount,user.userAge,user.location);

if (userData != NULL){
    fclose(userData);
}
}
