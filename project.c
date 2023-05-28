/* ***********  AIRLINE RESERVATION SYSTEM *********    */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
struct airlines // struct keyword is used to create a structure

{
        char passport[20];
        char name[20];
        char origin[20]; // starting place of journey
        char destination[20]; // place where we want to reach
        char email[20];
        int seat_num;
        struct airlines *following;
}
    *begin,
    *stream;
struct airlines *dummy;
void main()
{
        void reserve(int r), cancel(), display(), savefile(); // declaration of functions
        int choice;
        begin = stream = NULL; // initialize the struct pointers to NULL
        int num = 1;
        do // starting of do while loop
        {

                printf("\n\t\t\t **********************************************************");

                printf("\n\t\t\t\t WELCOME TO  AIRLINES RESERVATION SYSTEM     ");

                printf("\n\t\t\t **********************************************************");

                printf("\n\n\n\t\t  Please enter your choice from below (1-4):");

                printf("\n\n\t\t 1. RESERVATION");

                printf("\n\n\t\t 2. CANCEL");

                printf("\n\n\t\t 3. DISPLAY");

                printf("\n\n\t\t 4. SAVE FILE");

                printf("\n\n\t\t 5. THANK YOU FOR CHOOSING AIRLINES RESERVATION SYSTEM");

                printf("\n\n\t\t 6. ENTER YOUR CHOICE :\t");

                scanf("%d", &choice);

                fflush(stdin);

                system("cls"); // if you are writing code in linux or mac use clear in place of cls

                switch (choice)

                {

                case 1:

                        reserve(num);

                        num++;

                        break;

                case 2:

                        cancel();

                        break;

                case 3:

                        display();

                        break;

                case 4:

                        savefile();

                        break;

                default:
                        printf("\t INVALID CHOICE");
                        printf("\t KINDLY ENTER CHOICE FROM NO.1-4");
                }

                getch();

        }

        while (choice = 4);
}

void details() // following are the details that you have to enter

{


        printf("\tEnter your passport number:\t");

        gets(stream->passport);
        fflush(stdin); // reads a line from stdin and stores it into the string pointed

        printf("\n\tEnter your name          :\t");

        gets(stream->name);
        fflush(stdin);

        printf("\n\tEnter your email address :\t");

        gets(stream->email);
        fflush(stdin);

        printf("\n\tEnter the Origin         :\t");

        gets(stream->origin);
        fflush(stdin);

        printf("\n\tEnter the Destination    :\t");

        gets(stream->destination);
        fflush(stdin);
}

void details();

void reserve(int r)

{


        stream = begin;

        if (begin == NULL)

        {

                // first traveller

                begin = stream = (struct airlines *)malloc(sizeof(struct airlines));

                details();

                stream->following = NULL;

                printf("\n\t SEAT BOOKING SUCCESSFULL!");

                printf("\n\n\t your seat number is: Seat A-%d", r);

                stream->seat_num = r;

                return;
        }

        else if (r > 20) // FULL SEATS

        {

                printf("\n\t\t Seats Full.");

                return;
        }

        else

        {

                // next traveller

                while (stream->following)

                        stream = stream->following;

                stream->following =(struct airline *)malloc(sizeof(struct airlines));

                stream = stream->following;

                details();

                stream->following = NULL;

                printf("\n\t Seat booking succesful!");

                printf("\n\t your seat number is: Seat A-%d", r);

                stream->seat_num = r;

                return;
        }
}

void savefile()

{

        FILE *fpointer = fopen(" records", "w");

        if (!fpointer)

        {

                printf("\n Error in opening file!");

                return;

                Sleep(800);
        }

        stream = begin;

        while (stream)

        {

                fprintf(fpointer, "%-6s", stream->passport);

                fprintf(fpointer, "%-15s", stream->name);

                fprintf(fpointer, "%-15s", stream->email);

                fprintf(fpointer, "%-15s", stream->origin);

                fprintf(fpointer, "%-15s", stream->destination);

                fprintf(fpointer, "\n");

                stream = stream->following;
        }

        printf("\n\n\t Details have been saved to a file ( records)");

        fclose(fpointer);
}

void display()

{

        stream = begin;

        while (stream)

        {

                printf("\n\t\tPassport Number    : %-15s", stream->passport);

                printf("\n\t\tName               : %-15s", stream->name);

                printf("\n\t\tE-mail address     : %-15s", stream->email);

                printf("\n\t\tSeat number        : A-%d", stream->seat_num);

                printf("\n\t\tOrigin             : %-15s",stream->origin);

                printf("\n\t\tDestination        : %-15s", stream->destination);

                printf("\n\n****=====================================================****");

                stream = stream->following;
        }
}

void cancel()

{

        stream = begin;

        system("cls");

        char passport[6];

        printf("\n\n Enter passort number to delete record? : \t");

        gets(passport);
        fflush(stdin);

        if (strcmp(begin->passport, passport) == 0)

        {

                dummy = begin;

                begin = begin->following;

                free(dummy);

                printf(" booking has been deleted");

                Sleep(800);

                return;
        }

        while (stream->following)

        {

                if (strcmp(stream->following->passport, passport) == 0)

                {

                        dummy = stream->following;

                        stream->following = stream->following->following;

                        free(dummy);

                        printf("has been deleted ");

                        getch();

                        Sleep(800);

                        return;
                }

                stream = stream->following;
        }

        printf("passport number is wrong please check your passport");
}