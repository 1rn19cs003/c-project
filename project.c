#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char ans=0;
int ok;
int b,valid=0;
// FUNCTION DECLERATION
void welcome_screen(void);
void title(void);
void main_menu(void);
void login_screen(void);
void add_rec(void);
void func_list();
void search_re(void);
void edit_rec(void);
void del_rec(void);
void ex_it(void);
void gotoxy(short x,short y)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
// ====================================================================STRUCTURE==============================================================================
struct  patient
{
    int age;
    char gender;
    char first_name[20];
    char last_name[20];
    char contact_no[15];
    char address[30];
    char email[30];
    char doctor[20];
    char problem[20];
};
struct patient p;
// =======================================================================MAIN FUNCTION========================================================================
void main()
{
    welcome_screen();
    title();
    login_screen();   
}
// ====================================================================WELCOME SCREEN==========================================================================
void welcome_screen(void)
{
    printf("\n\n\n\n\n\n\n\t\t\t\t######################################");
    printf("\n\t\t\t\t#\tWELCOME TO                  #");
    printf("\n\t\t\t\t#    HOSPITAL MANEGEMENT SYSTEM     #");
    printf("\n\t\t\t\t######################################");
    printf("\n\n\n\n\n Press any key to continue............\n");
    getch();
    system("cls");
}
// =====================================================================TITLE=================================================================================
void title(void)
{
    printf("\n\n\t\t-----------------------------------------------------------------------");
    printf("\n\t\t\t\t                   XYZ   HOSPITAL              ");
    printf("\n\t\t-------------------------------------------------------------------------");
}
// =====================================================================MAIN MENU============================================================================
void main_menu(void)
{
    system("cls");
    int choose;
    title();
    printf("\n\n\n\n\n\t\t\t\t1. Add Patient Record\n");
    printf("\n\t\t\t\t2. List Patient Record\n");
    printf("\n\t\t\t\t3. Search Patient Record\n");
    printf("\n\t\t\t\t4. Edit Patient Record\n");
    printf("\n\t\t\t\t5. Delete Patient Record\n");
    printf("\n\t\t\t\t6. Exit\n");
    printf("\n\n\n\n\t\t\t\tChoose from 1 to 6:");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:add_rec();
            break;
        case 2:func_list();
            break;
        case 3: search_re();
            break;
        case 4: edit_rec();
            break;
        case 5: del_rec();
            break;
        case 6: ex_it();
            break;
        default:printf("\t\t\tInvalid Entry. Please Enter the valid option\n");
                getch();
    }
}
// ==================================================================EXIT===================================================================================
void ex_it(void)
{
    system("cls");
    title();
    printf("\n\n\n\n\n\t\t\tTHANK TOU FOR VISITING:");
    getch();
}
// =================================================================LOGIN FUNCTION===========================================================================
void login_screen(void)
{
    int e=0;
    char username[15];
    char password[15];
    char original_username[25]="abhi";
    char original_username2[25]="adya";
    char original_password[15]="1234";
    do
    {
        printf("\n\n\n\n\t\t\t\tEnter your username and password:");
        printf("\n\n\n\t\t\t\t\tUSERNAME:");
        scanf("%s",&username);
        printf("\n\n\t\t\t\t\tPASSWORD:");
        scanf("%s",&password);
        if(((strcmp(username,original_username)==0)||(strcmp(username,original_username2)==0)) && strcmp(password,original_password)==0)
        {
            printf("\n\n\t\t\t\t\t....Login Successfull....");
            getch();
            main_menu();
            break;
        }
        else{
            printf("\n\t\t\tPassword is Incorrect:(try again):");
            e++;
            getch();
        }
    }while(e<=2);
    if(e>2)
    {
        printf("You have cross the limit . You Can't login:");
        getch();
        ex_it();
    }
    system("cls");
}
// =========================================================================RECORD ADDITION================================================================
void add_rec(void)
{
    system("cls");
    title();
    char ans;
    FILE *ek;
    ek=fopen("Record2.dat","a");
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!! Add patient Record !!!!!!!!!!!!!!!!\n");
    // ---------------------------------------------------------FIRST NAME------------------------------------------------------------------
    A:
    printf("\n\t\t\tFIRST NAME: ");
    scanf("%s",p.first_name);
    p.first_name[0]=toupper(p.first_name[0]);
    if(strlen(p.first_name)>20 || strlen(p.first_name)<2)
    {
        printf("\n\t Invalid :(\t The max Range of first name is 20 and min range is 2\n");
        goto A;
    }
    else
    {
        for(b=0;b<strlen(p.first_name);b++)
        {
            if(isalpha(p.first_name[b]))
            {
                valid=1;
            }
            else
            {
                valid =0;
                break;
            }

        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invlaid Character (Enter again)");
            goto A;
        }
    }
    // -------------------------------------------------LAST NAME------------------------------------------------------------------
    B:
    printf("\n\t\t\tLAST NAME: ");
    scanf("%s",p.last_name);
    p.last_name[0]=toupper(p.last_name[0]);
    if(strlen(p.last_name)>20 || strlen(p.last_name)<2)
    {
        printf("\n\t Invalid :(\t The max Range of last name is 20 and min range is 2\n");
        goto B;
    }
    else
    {
        for(b=0;b<strlen(p.last_name);b++)
        {
            if(isalpha(p.last_name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }

        }
        if(!valid)
        {
            printf("\n\t\t last name contain Invlaid Character (Enter again)");
            goto B;
        }
    }
    // -------------------------------------------------------GENDER--------------------------------------------------------------
    do
    {
        printf("\n\t\t\tGender[F/M]: ");
        scanf("%c",&p.gender);
        if(toupper(p.gender)=='M'|| toupper(p.gender)=='F')
        {
            ok=1;
        }
        else
        {
            ok=0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invlaid character (Enter a either F or M:)");

        }
    }while(!ok);
    // --------------------------------------------------------------------AGE----------------------------------------------------------------------
    printf("\n\t\t\tAge: ");
    scanf("%d",&p.age);
    // ------------------------------------------------------------------ADDRESS---------------------------------------------------------------------
    do
    {
        C:
        printf("\n\t\t\tAddress:");
        scanf("%s",p.address);
        p.address[0]=toupper(p.address[0]);
        if(strlen(p.address)>20 || strlen(p.address)<4)
        {
            printf("\n\t Invalid : \t The max range of address is 20 and min is 4\n");
            goto C;

        }
    }while(!valid);
    //----------------------------------------------------------------CONTACT NO.---------------------------------------------------------------------- 
    do
    {
        D:
        printf("\n\t\t\tContact no: ");
        scanf("%s",p.contact_no);
        if(strlen(p.contact_no)>10 || strlen(p.contact_no)!=10)
        {
            printf("\n\t Invalid : \t The Contact must be contain 10 number !! Enter again\n");
            goto D;

        }
        else
        {
            for(b=0;b<strlen(p.contact_no);b++)
            {
                if(!isalpha(p.contact_no[b]))
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }

            }
            if(!valid)
            {
                printf("\n\t\t Contact no. contain Invlaid Character (Enter again)");
                goto D;
            }
        }
    }while(!valid);
    // ----------------------------------------------------------------------------EMAIL--------------------------------------------------------------------
    do
    {
        printf("\n\t\t\tEmail: ");
        scanf("%s",p.email);
        if(strlen(p.email)>30 || strlen(p.email)<8)
        {
            printf("\n\t Invalid : \t The max range of Email is 30 and min is 8\n");

        }
    }while(strlen(p.email)>30 || strlen(p.email)<8);
    // ----------------------------------------------------------------PROBLEM-------------------------------------------------------------------
    E:
    printf("\n\t\t\tProblem: ");
    scanf("%s",&p.problem);
    p.problem[0]=toupper(p.problem[0]);
    if(strlen(p.problem)>15 || strlen(p.problem)<3)
    {
        printf("\n\t Invalid (\t The max range of name is 15 and min range is 3 )");
        goto E;
    }
    else
    {
        for(b=0;b<strlen(p.problem);b++)
        {
            if(isalpha(p.problem[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Problem contain Invlaid Character (Enter again)");
            goto E;
        }
    }
    // ----------------------------------------------------------------DOCTOR-----------------------------------------------------------------------------
    F:
    printf("\n\t\t\tPrescribed Doctor : ");
    scanf("%s",p.doctor);
    p.doctor[0]=toupper(p.doctor[0]);
    if(strlen(p.doctor)>30 || strlen(p.doctor)<3)
    {
        printf("\n\t Invalid (\t The max range of first name is 30 and min range is 3 )");
        goto F;
    }
    else
    {
        for(b=0;b<strlen(p.doctor);b++)
        {
            if(isalpha(p.doctor[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Doctor name contain Invlaid Character (Enter again)");
            goto F;
        }
    }
    //----------------------------------------------------------------------END OF RECORD--------------------------------------------------------------
    fprintf(ek,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor);
    printf("\n\n\t\t\t..........Information Record Successfull........");
    fclose(ek);
    sd:
    getch();
    printf("\n\n\t\t\tDo You want add more data [Y/N]??:");
    scanf("%c",&ans);
    if(toupper(ans)=='Y')
    {
        add_rec();

    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\tThank you:");
        getch();
        main_menu();
    }
    else 
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
// =================================================================================LIST OF RECORDS===============================================================
void func_list()
{
    int row;
    system("cls");
    title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!!!! List of Patient!!!!!!!!!!!!!!\n");
        gotoxy(1,15);
        printf("Full Name");
        gotoxy(20,15);
        printf("Gender");
        gotoxy(32,15);
        printf("Age");
        gotoxy(37,15);
        printf("Address");
        gotoxy(49,15);
        printf("Contact no.");
        gotoxy(64,15);
        printf("Email");
        gotoxy(88,15);
        printf("Problem");
        gotoxy(98,15);
        printf("Prescribed Doctor\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        row=17;
        while(fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem,p.doctor)!=EOF)
        {
            gotoxy(1,row);
            printf("%s %s",p.first_name,p.last_name);
            gotoxy(20,row);
            printf("%c",p.gender);
            gotoxy(32,row);
            printf("%d",p.age);
            gotoxy(37,row);
            printf("%s",p.address);
            gotoxy(49,row);
            printf("%s",p.contact_no);
            gotoxy(64,row);
            printf("%s",p.email);
            gotoxy(88,row);
            printf("%s",p.problem);
            gotoxy(98,row);
            printf("%s",p.doctor);
            row++;
        }
    fclose(ek);
    getch();
    main_menu();
}
// ==========================================================================SEARCH======================================================================
void search_re(void)
{
    char name[20];
    system("cls");
    title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!\n");
    gotoxy(12,8);
    printf("\n Enter Patient Name to be Viewed:");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem,p.doctor))
    {
        if(strcmp(p.first_name,name)==1)
        {
            gotoxy(1,15);
            printf("Full Name");
            gotoxy(25,15);
            printf("Gender");
            gotoxy(32,15);
            printf("Age");
            gotoxy(37,15);
            printf("Address");
            gotoxy(52,15);
            printf("Contact no.");
            gotoxy(64,15);
            printf("Email");
            gotoxy(80,15);
            printf("Problem");
            gotoxy(95,15);
            printf("Prescribed Doctor");
            printf("\n---------------------------------------------------------------------------------------------------\n");
            gotoxy(1,18);
            printf("%s %s",p.first_name,p.last_name);
            gotoxy(25,18);
            printf("%c",p.gender);
            gotoxy(32,18);
            printf("%d",p.age);
            gotoxy(37,18);
            printf("%s",p.address);
            gotoxy(52,18);
            printf("%s",p.contact_no);
            gotoxy(64,18);
            printf("%s",p.email);
            gotoxy(80,18);
            printf("%s",p.problem);
            gotoxy(95,18);
            printf("%s",p.doctor);
            printf("\n");
            
        }
        if(strcmp(p.first_name,name)!=1)
        {
            gotoxy(5,10);
            printf("Record  Not Found!!!");
            getch();

        }
        fclose(ek);
        L:
        getch();
        printf("\n\t\t\tDo  you want to view more [Y/N]:");
        scanf("%c",&ans);
        if(toupper(ans)=='Y')
        {
            search_re();

        }
        else if(toupper(ans)=='N')
        {
            printf("\n\t\tThank you");
            getch();
            main_menu();

        }
        else 
        {
            printf("\n\tInvlaid Input.\n");
            goto L;
        }
    }
}
// ============================================================================EDIT======================================================================
void edit_rec(void)
{
    FILE *ek,*ft;
    int i,b,valid=0;
    char ch;
    char name[20];
    system("cls");
    title();
    ft=fopen("temp2.dat","w+");
    ek=fopen("Record2.dat","r");
    if(ek==NULL)
    {
        printf("\n\t Can't open File!!");
        getch();
        main_menu();
    }  
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!Edit Patient Record!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(12,13);
    printf("Enter the First name of the Patient\n");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);
    if(ft==NULL)
    {
        printf("\n Can not open file\n");
        getch();
        main_menu();
    }
    while (fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem,p.doctor))
    {
        if(strcmp(p.first_name,name)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("********* Existing Record *********\n");
            gotoxy(10,19);
            printf("%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor);
            gotoxy(12,22);
            printf("Enter new First Name\n");
            scanf("%s",p.first_name);
            gotoxy(12,24);
            printf("Enter new Last Name\n");
            scanf("%s",p.last_name);
            gotoxy(12,26);
            printf("Enter Gender\n");
            scanf("%c",&p.gender);
            p.gender=toupper(p.gender);
            gotoxy(12,28);
            printf("Enter Age\n");
            scanf("%d",&p.age);
            gotoxy(12,30);
            printf("Enter Address\n");
            scanf("%s",p.address);
            p.address[0]=toupper(p.address[0]);
            gotoxy(12,32);
            printf("Enter Contact no.\n");
            scanf("%s",p.contact_no);
            gotoxy(12,34);
            printf("Enter New mail\n");
            scanf("%s",p.email);
            gotoxy(12,36);
            printf("Enter Problem\n");
            scanf("%s",p.problem);
            p.problem[0]=toupper(p.problem[0]);
            gotoxy(12,38);
            printf("Enter Doctor\n");
            scanf("%s",p.doctor);
            p.doctor[0]=toupper(p.doctor[0]);
            printf("\nPress U for the Updating Operation\n");
            ch=getche();
            if(ch=='u'|| ch=='U')
            {
                fprintf(ft,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor);
                printf("\n\n\t\t\tPatient record Updated Succesfully.......\n");
            }
            else
            {
                fprintf(ft,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor);
            }
        }
        if(!valid)
        {
            printf("\n\t\tNO RECORD FOUND......\n");
        }
        fclose(ft);
        fclose(ek);
        remove("Record2.dat");
        rename("temp2.dat","Record2.dat");
        getch();
        main_menu();
    }
}
// ============================================================================DELETE====================================================================
void del_rec(void)
{
    char name[20];
    int found=0;
    system("cls");
    title();
    FILE *ek,*ft;
    ft=fopen("temp_file2.dat","w+");
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!!! Delete Patieits Record !!!!!!!!!!!!!!!\n");
    gotoxy(12,8);
    printf("\n Enter Patient Name to Delete\n");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem,p.doctor)!=EOF)
    {
        if(strcmp(p.first_name,name)!=1)
        {
            fprintf(ft,"%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor);
        }
        else
        {
            printf("%s %s %c %d %s %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor);
            found=1;
        }
    }
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found!!!!!!!!....\n");
        getch();
        main_menu();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Record2.dat");
        rename("temp_file2.dat","Record2.dat");
        printf("\n\n\t\t\t Record Deleted Successsfully!!");
        getch();
        main_menu();
    }
}
//===========================================================================END==============================================================================