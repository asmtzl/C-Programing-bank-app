// j login number
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct user
{
    char username[20];
    char password[20];
    int age, cardnumber, watbill, elecbill, telbill;
    long long int phonenumber;
    float balance;
} account[100];
int i, sum = 0, g, num, j;
void read();
int userlogin();
void userregister();
void displayuser();
void deposit();
void withdrawal();
void transfer();
void editaccount();
int deleteaccount();
void write();
void paybill();
void view();
int main()
{
    read();
    int choice1 = 0;
    while (choice1 != 3)
    {
        int choice2 = 0;
        int choice3 = 0;
        system("cls");
        printf("\n\n\t|******************************************************************************************************|\n\n");
        printf("\t\t\t\t\t     || BANK AUTOMATION APPLICATION ||\n");
        printf("\n\t|******************************************************************************************************|\n\n\n");
        printf("\t\t\t\t\t\t    Enter your choice\n\n\t\t\t\t\t\t     1. Log in\n\t\t\t\t\t\t     2. Register\n\t\t\t\t\t\t     3. Save and quit\n\n\t\tOption = ");
        scanf("%d", &choice1);
        fflush(stdin);    //making it clear
        if (choice1 == 1) //login
        {
            if (userlogin() == 1)
            {
                while (choice3 == 0)
                {
                    system("cls");
                    printf("\n\t|******************************************************************************************************|\n\n\n");
                    printf("\t\t\t\t\t\t    Enter your choice\n\n\t\t\t\t\t\t    1. Display information\n\t\t\t\t\t\t    2. Deposit\n\t\t\t\t\t\t    3. Withdrawal\n\t\t\t\t\t\t    4. Money transfer\n\t\t\t\t\t\t    5. Edit account\n\t\t\t\t\t\t    6. Delete account\n\t\t\t\t\t\t    7. Bill payment\n\t\t\t\t\t\t    8. Log out\n\n\n");
                    printf("\n\t|******************************************************************************************************|\n\n\n");
                    printf("\t\tOption = ");
                    scanf("%d", &choice2);
                    if (choice2 == 1)
                    {
                        displayuser();
                    }
                    else if (choice2 == 2)
                    {
                        deposit();
                    }
                    else if (choice2 == 3)
                    {
                        withdrawal();
                    }
                    else if (choice2 == 4)
                    {
                        transfer();
                    }
                    else if (choice2 == 5)
                    {
                        editaccount();
                    }
                    else if (choice2 == 6)
                    {
                        if (deleteaccount() == 1)
                        {
                            printf("\nYou have been successfully deleted your account.\n");
                            choice3 = 1;
                        }
                    }
                    else if (choice2 == 7)
                    {
                        paybill();
                    }
                    else if (choice2 == 8)
                    {
                        printf("\nYou have been successfully logged out.\n");
                        printf("Press any key to continue...\n\n");
                        getch();
                        choice3 = 1;
                    }
                    else
                    {
                        //system("cls");
                        printf("\n\nInvalid input , try again by using valid inputs");
                    }
                }
            }
        }
        else if (choice1 == 2) //register
        {
            system("cls");
            userregister();
        }
        else if (choice1 == 3) //search
        {
            system("cls");
            write();
            return 0;
        }
        else if (choice1 == 4) //edit
        {
            view();
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs\n");
        }
        printf("\n\n");
    }
}
void read()
{
    FILE *fp = fopen("userdata.txt", "r");
    if (fp == NULL)
    {
        //create empty file
        fp = fopen("userdata.txt", "w");
        fclose(fp);
    }
    num = fread(account, sizeof(struct user), 100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("userdata.txt", "w+");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(account, sizeof(struct user), num, fp);

    fclose(fp);
}
int userlogin()
{
    int f = 1;
    char uName[20], pwd[20];
    printf("\n\t\tUsername: ");
    gets(uName);
    printf("\t\tPassword: ");
    gets(pwd);
    for (g = 0; g < num; g++)
    {
        if (strcmp(uName, account[g].username) == 0)
        {
            printf("\n\t\tUsername matches\n");
            if (strcmp(pwd, account[g].password) == 0)
            {
                printf("\t\tPassword matches\n\n");
                printf("\t\t\t\t\t\t     Welcome %s!\n\n\n", account[g].username);
                f = 0;
                j = g;
                printf("\t\tPress any key to continue...");
                getch();
                return 1;
            }
        }
    }
    if (f == 1)
    {
        printf("\n\t\tUsername or password is wrong\n\n\n");
        printf("\t\tPress any key to continue...\n");
        getch();

        return 0;
    }
}
void userregister()
{
    char nullstr[20] = "\0";
    int b, usernamec1 = 1, usernamec2 = 1, passwordc, agec, phonenumberc;
    printf("\n\n");
    printf("\n\n\t\tAlready %d account exist\n\n", num); //account number
    sum = num + 1;
    printf("\n");
    fflush(stdin);

    for (i = num; i < sum; i++)
    {
        do //username existence
        {
            printf("\n\n\t\tEnter username: ");
            gets(account[i].username);

            if (strcmp(account[i].username, nullstr) == 0)
            {
                printf("\n\n\t\tEnter a valid username\n\n");
                usernamec1 = 0;
            }
            else
            {
                usernamec1 = 1;
            }

            for (b = 0; b < i; b++) //repeat
            {
                if (strcmp(account[i].username, account[b].username) == 0)
                {
                    printf("\n\n\t\tUsername already used\n\n\n");
                    usernamec2 = 0;
                    break;
                }
                else
                {
                    usernamec2 = 1;
                }
            }

        } while (usernamec1 == 0 || usernamec2 == 0);

        do //password null detect
        {
            printf("\n\n\t\tEnter password= ");
            gets(account[i].password);

            if (strcmp(account[i].password, nullstr) == 0)
            {
                printf("\n\n\t\tEnter a valid password\n\n\n");
                passwordc = 0;
            }
            else
            {
                passwordc = 1;
            }

        } while (passwordc == 0);
        fflush(stdin);
        do //age null detect
        {
            printf("\n\n\t\tEnter your age= ");
            scanf("%d", &account[i].age);

            if (account[i].age <= 0)
            {
                printf("\n\n\t\tEnter a valid age\n\n");
                agec = 0;
            }
            else
            {
                agec = 1;
            }

        } while (agec == 0);
        fflush(stdin);
        do //phone number null detect
        {
            printf("\n\n\t\tEnter your phone number= 0");
            scanf("%lld", &account[i].phonenumber);

            if (account[i].phonenumber <= 1000000000)
            {
                printf("\n\n\t\tEnter a valid phone number\n\n");
                phonenumberc = 0;
            }
            else
            {
                phonenumberc = 1;
            }

        } while (phonenumberc == 0);
        fflush(stdin);
        account[i].cardnumber = 100000 + i;
        printf("\n\n\t\tYour card number: %d\n", account[i].cardnumber);
        account[i].balance = 0;
        printf("\n\n\t\tYour balance is: %.2f\n", account[i].balance);
        printf("\n");
        account[i].watbill = (rand() % 51 + 50);
        account[i].elecbill = (rand() % 51 + 50);
        account[i].telbill = (rand() % 51 + 50);
        num++;
    }
}
void displayuser()
{
    printf("\n\n");
    printf("\t\tSerial Number=%d\n", j);
    printf("\t\tUsername = ");
    puts(account[j].username);
    printf("\t\tPassword = ");
    puts(account[i].password);
    printf("\t\tCardnumber = %d\n\t\tBalance = %.2f\n\t\tAge= %d\n\t\tPhone number= 0%lld\n", account[j].cardnumber, account[j].balance, account[j].age, account[j].phonenumber);
    printf("\n\n");
    printf("\t\tPress any key to continue...");
    getch();
}
void deposit()
{
    float addmoney;
    int depositc1 = 0, depositc2;
    printf("\n\t\tYour balance is %.2f\n\n", account[j].balance);

    do
    {
        printf("\n\n\t\tEnter money you want to deposit: ");
        scanf("%f", &addmoney);
        if (addmoney > 0)
        {
            account[j].balance = account[j].balance + addmoney;
            printf("\n\n\t\tYour balance is %.2f\n\n", account[j].balance);
            do
            {
                printf("\t\tDo you want to deposit more money?\n\t\t1. Yes\n\t\t2. No\n\n\t\tOption=");
                scanf("%d", &depositc2);
                if (depositc2 == 1)
                {
                    depositc1 = 0;
                }
                else if (depositc2 == 2)
                {
                    depositc1 = 1;
                }
                else
                {
                    printf("\n\t\tInvalid input , try again by using valid inputs\n\n");
                    depositc1 = 3;
                }
            } while (depositc2 == 3);
        }
        else
        {
            printf("\n\t\tInvalid input , please try again\n\n");
            depositc1 == 0;
        }

    } while (depositc1 == 0);
}
void withdrawal()
{
    float takemoney;
    int withdrawalc1 = 0, withdrawalc2;
    printf("\n\t\tYour balance is %.2f\n", account[j].balance);

    do
    {
        printf("\n\t\tEnter money you want to withdraw from account: ");
        scanf("%f", &takemoney);
        if (takemoney > account[j].balance)
        {
            printf("\n\n\t\tUnsufficient balance please try again\n\n");
        }
        else
        {
            if (takemoney > 0)
            {
                account[j].balance = account[j].balance - takemoney;
                printf("\n\n\t\tYour balance is %.2f\n", account[j].balance);
                do
                {
                    printf("\n\t\tDo you want to withdraw more money?\n\t\t1. Yes\n\t\t2. No\n\n\t\tOption=");
                    scanf("%d", &withdrawalc2);
                    if (withdrawalc2 == 1)
                    {
                        withdrawalc1 = 0;
                    }
                    else if (withdrawalc2 == 2)
                    {
                        withdrawalc1 = 1;
                    }
                    else
                    {
                        printf("\n\n\t\tInvalid input , try again by using valid inputs\n\n");
                        withdrawalc1 = 3;
                    }
                } while (withdrawalc2 == 3);
            }
            else
            {
                printf("\n\n\t\tInvalid input, please try again.\n\n");
                withdrawalc1 == 0;
            }
        }

    } while (withdrawalc1 == 0);
}
void transfer()
{
    char transfername[20];
    int f = 1, transferx = 0, transferc1 = 0, transferc2 = 0, transfercardnumber;
    float transfermoney;
    do
    {
        printf("\n\n\t\tHow do you want to transfer money\n\n\t\t1. Username\n\t\t2. Card number\n\t\t3. Exit\n\n\t\tOption= ");
        scanf("%d", &transferx);
        if (transferx == 1)
        {

            printf("\n\n\t\tEnter the username you want to transfer money: ");
            scanf("%s", &transfername);
            for (g = 0; g < num; g++)
            {
                if (strcmp(transfername, account[g].username) == 0)
                {
                    f = 0;
                    printf("\n\n\t\tTransfering money to %s\n\n", &transfername);
                    do
                    {
                        printf("\t\tYour balance is = %f\n\n", account[j].balance);
                        printf("\t\tEnter the amount of money: ");
                        scanf("%f", &transfermoney);
                        if (transfermoney > 0)
                        {
                            if (transfermoney <= account[j].balance)
                            {
                                account[j].balance = account[j].balance - transfermoney;
                                account[g].balance = account[g].balance + transfermoney;
                                transferc2 = 1, transferc1 = 1;
                                printf("\n\n\t\tYou have been successfully transferred money!\n\n\n");
                                printf("\t\tPress any key to continue...");
                                getch();
                            }
                            else
                            {
                                printf("\n\n\t\tUnsufficient balance please try again.\n\n");
                                transferc2 = 0;
                            }
                        }
                        else
                        {
                            printf("\n\n\t\tInvalid input, please try again.\n\n");
                            transferc2 = 0;
                        }

                    } while (transferc2 == 0);
                }
            }
            if (f == 1)
            {
                printf("\n\n\t\tUsername not found.\n\n");
            }
        }
        else if (transferx == 2)
        {

            printf("\n\n\n\n\t\tEnter the card number you want to transfer money: ");
            scanf("%d", &transfercardnumber);
            for (g = 0; g < num; g++)
            {
                if (transfercardnumber == account[g].cardnumber)
                {
                    f = 0;
                    printf("\n\n\t\tTransfer money to %s\n\n", account[g].username);
                    do
                    {
                        printf("\n\t\tEnter the amount of money: ");
                        scanf("%f", &transfermoney);
                        if (transfermoney > 0)
                        {
                            if (transfermoney <= account[j].balance)
                            {
                                account[j].balance = account[j].balance - transfermoney;
                                account[g].balance = account[g].balance + transfermoney;
                                transferc2 = 1, transferc1 = 1;
                                printf("\n\t\tYou have been successfully transferred money!\n\n");
                            }

                            else
                            {
                                printf("\n\n\t\tUnsufficient balance please try again.\n\n");
                                transferc2 = 0;
                            }
                        }
                        else
                        {
                            printf("\n\n\t\tInvalid input, please try again.\n\n");
                            transferc2 = 0;
                        }

                    } while (transferc2 == 0);
                }
            }
            if (f == 1)
            {
                printf("\n\n\t\tCard number not found.\n\n");
            }
        }
        else if (transferx == 3)
        {
            transferc1 = 1;
        }
        else
        {
            printf("\n\n\t\tPlease input a valid value\n\n");
            transferc1 = 0;
        }

    } while (transferc1 == 0);
}
void editaccount()
{
    char nullstr[20] = "\0", editusername[20] = "\0", editpassword[20] = "\0";
    int b, editx, editc, editage = 0, editusernamec1 = 1, editusernamec2 = 1, editpasswordc = 1, editphonenumberc = 1, editagec = 1;
    long long int editphone = 0;
    printf("\n");
    printf("\n\t\tUsername =");
    puts(account[j].username);
    printf("\t\tPassword =");
    puts(account[j].password);
    printf("\t\tage =%d\n\t\tPhone number =%lld\n\n", account[j].age, account[j].phonenumber);
    do
    {
        printf("\n\n\t\tWhich one do you want to change?\n\n\t\t1. Username\n\t\t2. Password\n\t\t3. Phone number\n\t\t4. Age\n\t\t5. Exit\n\n\t\tOption= ");
        scanf("%d", &editx);
        if (editx == 1)
        {
            do //username control
            {
                printf("\n\n\t\tEnter new username: ");
                scanf("%s", &editusername);
                if (strcmp(editusername, nullstr) == 0)
                {
                    printf("\n\n\t\tEnter a valid username\n\n");
                    editusernamec1 = 0;
                }
                else
                {
                    editusernamec1 = 1;
                }

                for (b = 0; b < num - 1; b++) //repeat
                {
                    if (strcmp(editusername, account[b].username) == 0)
                    {
                        printf("\n\n\t\tUsername already used\n\n");
                        editusernamec2 = 0;
                        break;
                    }
                    else
                    {
                        editusernamec2 = 1;
                    }
                }

            } while (editusernamec1 == 0 || editusernamec2 == 0);
            strcpy(account[j].username, editusername);
        }
        else if (editx == 2)
        {
            do //password null detect
            {
                printf("\n\n\t\tEnter new password= ");
                scanf("%s", &editpassword);

                if (strcmp(editpassword, nullstr) == 0)
                {
                    printf("\n\n\t\tEnter a valid password\n\n");
                    editpasswordc = 0;
                }
                else
                {
                    editpasswordc = 1;
                }

            } while (editpasswordc == 0);
            strcpy(account[j].password, editpassword);
        }
        else if (editx == 3)
        {
            do //phone number null detect
            {
                printf("\n\n\t\tEnter your phone number= 0");
                scanf("%lld", &editphone);

                if (editphone <= 1000000000)
                {
                    printf("\n\n\t\tEnter a valid phone number\n\n");
                    editphonenumberc = 0;
                }
                else
                {
                    editphonenumberc = 1;
                }

            } while (editphonenumberc == 0);
            account[j].phonenumber = editphone;
        }
        else if (editx == 4)
        {
            do //age null detect
            {
                printf("\n\n\t\tEnter your age= ");
                scanf("%d", &editage);

                if (editage <= 0)
                {
                    printf("\n\n\t\tEnter a valid age\n\n");
                    editagec = 0;
                }
                else
                {
                    editagec = 1;
                }

            } while (editagec == 0);
            account[j].age = editage;
        }
        else if (editx == 5)
        {
            editc = 2;
        }
        else
        {
            printf("\n\n\t\tInvalid input, try again.\n\n");
        }
        printf("\n\n\n\n\t\tIs there anything else you want to change?\n\n\t\t1. Yes\n\t\t2. No\n\n\t\tOption= ");
        scanf("%d", &editc);
    } while (editc != 2);
}
int deleteaccount()
{
    int x, y = j;
    if (account[j].balance < 0.01)
    {
        while (y < num)
        {
            strcpy(account[y].username, account[y + 1].username);
            strcpy(account[y].password, account[y + 1].password);
            account[y].age = account[y + 1].age;
            account[y].cardnumber = account[y + 1].cardnumber;
            account[y].phonenumber = account[y + 1].phonenumber;
            account[y].balance = account[y + 1].balance;
            account[y].watbill = account[y+1].watbill;
            account[y].elecbill = account[y+1].elecbill;
            account[y].telbill = account[y+1].telbill;
            y++;
        }
        num--;
        return 1;
    }
    else
    {
        printf("\n\n\t\tYou cannot delete your account without withdrawing all your money!\n\n");
        printf("\n\n\t\tPress any key to continue...");
        getch();
        return 0;
    }
}
void paybill()
{ 
    int sec3, sec4;
    printf("\n\n\t\tSelect the bill you want to pay.\n\t\t1. Water\n\t\t2. Electric\n\t\t3. Phone");
    scanf("%d", &sec3);
    switch (sec3)
    {
    case 1:
        printf("Your current water bill : %d\n", account[j].watbill);
        printf("Your balance : %.2f TL\n Press 1 to pay or press 2 to return to main menu.\n", account[j].balance);
        scanf("%d", &sec4);
        switch (sec4)
        {
        case 1:
            if (account[j].watbill > account[j].balance)
            {
                printf("\n\n\t\tInsufficient balance, please add money to your account.\n\n");
                printf("\n\n\t\tPress any ket to continue...");
                getch();
                return;
            }
            account[j].balance = account[j].balance - account[j].watbill;
            printf("\n\n\t\tYour post-processing balance : %.2f\n", account[j].balance);
            account[j].watbill = 0;
            break;
        case 2:
            return;
            break;
        }
        break;
    case 2:
        printf("\n\n\t\tYour current electric bill : %d\n\n", account[j].elecbill);
        printf("\n\n\t\tYour balance: %.2f TL\n\t\tPress 1 to pay or press 2 to return to main menu.\n\n", account[j].balance);
        scanf("%d", &sec4);
        switch (sec4)
        {
        case 1:
            if (account[j].elecbill > account[j].balance)
            {
                printf("\n\n\t\tInsufficient balance, please add money to your account.\n\n");
                printf("\n\n\t\tPress any key to continue...");
                getch();
                return;
            }
            account[j].balance = account[j].balance - account[j].elecbill;
            printf("\n\n\t\tYour post-processing balance : %.2f\n\n", account[j].balance);
            account[j].elecbill = 0;
            break;
        case 2:
            return;
            break;
        }
        break;
    case 3:
        printf("\n\n\t\tYour current phone bill  : %d\n\n", account[j].telbill);
        printf("\n\n\t\tYour balance: %.2f TL\n\t\t\t Press 1 to pay or press 2 to return to main menu.\n\n", account[j].balance);
        scanf("%d", &sec4);
        switch (sec4)
        {
        case 1:
            if (account[j].telbill > account[j].balance)
            {
                printf("\n\n\t\tInsufficient balance, please add money to your account.\n\n");
                printf("\n\n\t\tPress any key to continue...");
                getch();
                return;
            }
            account[j].balance = account[j].balance - account[j].telbill;
            printf("\n\n\t\tYour post-processing balance : %.2f\n", account[j].balance);
            account[j].telbill =0;
            break;
        case 2:
            return;
            break;
        }
        break;
    }
}
/////////////////////////////////////////////////////////////////////////////////////// secret part
void view()
{
    for (i = 0; i <= num + 3; i++)
    {
        printf("\n");
        printf("Serial Number=%d\n", i);
        printf("Username =");
        puts(account[i].username);
        printf("password =");
        puts(account[i].password);
        printf("age =%d\nPhone number =%lld\ncard number=%d\nbalance=%f\n", account[i].age, account[i].phonenumber, account[i].cardnumber, account[i].balance);
        printf("\n\n");
    }
}
///////////////////////////////////////////////////////////////////////////////////////