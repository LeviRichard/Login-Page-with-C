#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.system.h>
int menu();
void signup();
void login();
void forgot_pass();
void change_pass();
void delete_acc();
void brokenlines();

struct account
{
    char first_name[20];
    char last_name[20];
    char username[30];
    char phone[15];
    char gender[20];
    char DOB[20];
    char pass1[20];
    char num2[20];
};
int main()
{

   while(1)
   {
       system("cls");
       switch(menu())
       {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            forgot_pass();
            break;
        case 4:
            change_pass();
            break;
        case 5:
            delete_acc();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Option\n");
            break;

       }




   }


}

int menu()
{
    system("cls");
    system("Color 0A");
    int choice;
    printf("\n--------------------MAIN MENU--------------------\n");
    printf("1.SIGNUP\n");
    printf("2.LOGIN\n");
    printf("3.FORGOT PASSWORD OR USERNAME\n");
    printf("4.CHANGE PASSWORD\n");
    printf("5.DELETE ACCOUNT\n");
    printf("6.EXIT\n");
    brokenlines();
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    return choice;


}

void takepassword(char pass1[20]) //to mask the password
{
    char ch;
    int i=0;
    while(1)
        {
            ch=getch();

            if(ch==13) //if user presses "enter" it will end the command
            {
                pass1[i] = '\0';// adding a non character to the end of the string
                break;
            }
            else if(ch==8) //if user makes a mistake and wants to erase
            {
                if(i>0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if(ch==9 ||  ch==32)  //if user uses tab or space bar, it will continue and not add a character
            {
                continue;
            }
            else
            {
                pass1[i++] = ch;
                printf("*");
            }


        }
}


void signup()
{
    system("cls");
    system("Color 70");
    struct account u;
    char pass2[20];
    FILE *fp= fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "r");
    fprintf(fp," ");
    fclose(fp);
    printf("\n---------------------CREATING NEW ACCOUNT-----------------------\n");
    printf("ENTER FIRST NAME: ");
    scanf("%s",u.first_name);
    printf("ENTER LAST NAME: ");
    scanf("%s",u.last_name);
    printf("ENTER USERNAME: ");
    scanf("%s",u.username);
    printf("ENTER PHONE NUMBER: ");
    scanf("%s",u.phone);
    printf("ENTER GENDER: ");
    scanf("%s",u.gender);
    printf("ENTER DATE OF BIRTH: ");
    scanf("%s",u.DOB);
    printf("ENTER PASSWORD: ");
    takepassword(u.pass1); // function to take password from the user
    

    conf_pass:
    system("cls");
    system("Color 0A");
    printf("\n----------------------------------------------------------------");

    printf("\nCONFIRM PASSWORD: ");
    takepassword(pass2);
    
    //comparing the passwords:
    if (strcmp(u.pass1,pass2)==0)
    {

        printf("\n---------------------ACCOUNT CREATED SUCCESSFULLY-------------------------\n");
        getch();
        FILE *fp= fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "w");
        fwrite(&u, sizeof(struct account), 1, fp);
        fclose(fp);

    }
    else
    {
        brokenlines();
        printf("\nINCORRECT PASSWORD \n");
        goto conf_pass;


    }

}

void login()
{
    
    system("cls");
    system("Color E0");
    printf("--------------------------LOGIN PAGE-------------------------------\n");
    brokenlines();
    FILE *fp= fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "r");
    char c=fgetc(fp);
    if(c==EOF)
    {
        printf("Account not found, please Sign up");
        signup();
    }
    else
    {
        struct account u;
        char user_name[20];
        char pass3[20];
        FILE *fp= fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "r");
        fread(&u, sizeof(struct account),1,fp);
        input_username:
        printf("\nEnter Username:");
        scanf("%s",&user_name);
        if(strcmp(u.username,user_name)==0)
        {
           input_pass:
            printf("\nEnter Password:");
           takepassword(pass3);
          if(strcmp(u.pass1,pass3)==0)
           {
              system("cls");
              system("Color 40");
              
              printf("\n-----------------YOUR DETAILS ARE-----------------\n");
              printf("\nFirst Name:  %s\n",u.first_name);
              printf("Last Name:  %s\n",u.last_name);
              printf("Username:  %s\n",u.username);
              printf("Phonenumber:  %s\n",u.phone);
              printf("Date of birth:  %s\n",u.DOB);
              printf("Gender:  %s\n",u.gender);
              printf("\n----------------LOGIN SUCCESSFUL-------------------\n");
              getch();
           }
         else
          {
              printf("\nIncorrcet Password\n");
              goto input_pass;
          }

        }
        else
        {
          printf("\nIncorrect Username\n");
          goto input_username;
        }
        fclose(fp);
    }
    
}

void forgot_pass()
{
   
   system("cls");
   system("Color 0A");
   char phoneno[20];
   char pass4[20];
   int des; 
   struct account u;
   FILE *fp=fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "r");
   fread(&u,sizeof(struct  account),1,fp);
   printf("\n---------------------CHOOSE RECOVERY--------------------------\n");
   forgot:
   printf("1. Username \n");
   printf("2. Password \n");
   scanf("%d",&des);
   switch(des)
   {
    case 1:
       enter_pass4:
       printf("\nEnter password: ");
       scanf("%s",&pass4);
       if(strcmp(u.pass1,pass4)==0)
       {
        printf("\nUsername: %s\n",u.username);
        getch();
       }
       else
       {
        printf("\nINCORRECT PASSWORD!!\n");
        goto enter_pass4;
       }
       break;
    case 2:
       enter_username:
       printf("\nEnter Phonenumber:");
       scanf("%s",&phoneno);
       if(strcmp(u.phone,phoneno)==0)
       {
        printf("\n Password: %s\n",u.pass1);
        getch();
       }
       else
       {
        printf(" NOT FOUND!!\n");
        goto enter_username;
       }
       break;
    default:
       printf("\nInvalid option\n");
       goto forgot;
       break;
   }
   fclose(fp);


}

void change_pass()
{
    system("cls");
    system("Color 0A");
    char confirm_pass[20];
    int num1,num2;
    srand(time(0));//initiate the random number function
    num1=rand()%10000;// generate random numbers and make it = num1
    printf(" PASSWORD CODE: %d\n",num1);
    brokenlines();
    code:
    printf("\nEnter code: ");
    scanf("%d",&num2);
    brokenlines();
    if(num1==num2)
    {
        struct account u;
        FILE *fp=fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "r");
        fread(&u,sizeof(struct  account),1,fp);

        printf("\nEnter new password:");
        takepassword(u.pass1);
        confirm:
        printf("\nConfirm new password: ");
        takepassword(confirm_pass);
        if(strcmp(u.pass1,confirm_pass)==0)
        {
            printf("\n---------------------PASSWORD CHANGED SUCCESSFULLY------------------------\n");
            fp= fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "w");//to edit just one value and not the whole file
            fwrite(&u, sizeof(struct account), 1, fp);
            getch();

        }
        else
        {
            printf("\nINCORRECT PASSWORD");
            goto confirm;
        }
        fclose(fp);
    }
    else
    {
        printf("\nINCORRECT CODE");
        goto code;
    }


    

    

}

void brokenlines()
{
    for(int i=0; i<60; i++)
    {
        printf("-");
    }
}

void delete_acc()
{
    struct account u;
    FILE *fp = fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "r");
    if (fp == NULL)
    {
        printf("\nERROR OPENING THE FILE\n");
        getch();
        return;
    }

    char ch = fgetc(fp);//check if file is empty
    if (ch == EOF)//if file is empty it will return -1(EOF)
    {
        printf("\nNO ACCOUNT TO DELETE\n");
        getch();
    }
    else
    {
        char n;
        /*int authorized = check_authorization(); // Function to check if the user is authorized to delete the account
        if (!authorized)
        {
            printf("\nYOU ARE NOT AUTHORIZED TO DELETE AN ACCOUNT\n");
            getch();
            return;
        }*/

        printf("\nDO YOU WANT TO DELETE [Y|N]");
        scanf(" %c", &n); // Notice the added space before %c to consume newline character
        if (n == 'Y' || n == 'y')
        {
            fclose(fp); // Close the file pointer before opening it in write mode
            fp = fopen("C:\\Users\\HP\\Documents\\Education\\Programming\\C PROGRMING\\C projects\\login screen\\Log in folder\\account.txt", "w");
            if (fp == NULL)
            {
                printf("\nERROR OPENING THE FILE\n");
                getch();
                return;
            }

            fprintf(fp, " ");//print empty spaces in the file
            fclose(fp); // Close the file pointer after overwriting the file
            printf("\nACCOUNT SUCCESSFULLY DELETED");
            getch();
        }
        else if (n == 'N' || n == 'n')
        {
            printf("\nACCOUNT DELETION STOPPED");
            getch();
        }
        else
        {
            printf("\nINVALID INPUT. PLEASE TRY AGAIN.");
            getch();
        }
    }
    fclose(fp); // Close the file pointer after the operations are done
    getch();
}
