#include <stdio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>

// Structure for storing room information
typedef struct {
    int room_number;
    char guest_name[30];
    int status; // 0 for available, 1 for occupied
	char mobile[15];
	char nat[15];
	char period[10];
} Room;

// Function to display available rooms
void display_available_rooms(Room rooms[], int num_rooms) {
    system("cls");
    printf("\n\n\nAvailable rooms:\n\n");
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].status == 0) {
            printf("%d\t", rooms[i].room_number);
        }
    }
}

// Function to book a room
void book_room(Room rooms[], int num_rooms) {
    int room_number;
    char guest_name[30];
    char mobile[15];
	char nat[15];
	char period[10];

    printf("\n\nEnter room number: ");
    scanf("%d", &room_number);

    // Check if room is available
    int found = 0;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].status == 0) {
                found = 1;
                system("cls");
                printf("\nPlease Provide The Following Details To Complete Booking :-\n\n");
                printf("Enter guest name: ");
                scanf("%s", guest_name);
                strcpy(rooms[i].guest_name, guest_name);
                rooms[i].status = 1;
                printf("Mobile No. :");
                scanf("%s", mobile);
                strcpy(rooms[i].mobile, mobile);
                printf("Nationality :");
                scanf("%s", nat);
                strcpy(rooms[i].nat,nat);
                printf("Period Of Stay :");
                scanf("%s", period);
                strcpy(rooms[i].period,period);
                printf("\n\n\nRoom booked successfully.\n");
                printf(" \n Press any key to continue:");

	getch();
    system("cls");
            } else {
                printf("Room is already occupied.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Room not found.\n");
    }
}

// Function to check in a guest
void check_in(Room rooms[], int num_rooms) {
    int found=0;
    int room_number;
	system("cls");
    printf("\n\nEnter room number: ");
    scanf("%d", &room_number);

    // Check if room is occupied
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].status == 1) {
                found = 1;
                printf("\n\nGUEST DETAILS :\n");
                printf("\n------------------------\n\n");
                printf("Guest name      : %s\n", rooms[i].guest_name);
                printf("Mobile No.      : %s\n",rooms[i].mobile);
                printf("Nationality     : %s\n",rooms[i].nat);
                printf("Period Of Stay  : %s\n",rooms[i].period);
                printf(" \n Press any key to continue:");

	getch();
    system("cls");
            } else {

                printf("\n\nGuest Not Found.\n");
        printf(" \n Press any key to continue:");

	getch();
    system("cls");
            break;
        }
    }

    }
}



// Function to check out a guest
void check_out(Room rooms[], int num_rooms) {
    int room_number;
    system("cls");
    printf("Enter room number: ");
    scanf("%d", &room_number);

    // Check if room is occupied
    int found = 0;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].status == 1) {
                found = 1;
                printf("Guest %s has checked out.\n", rooms[i].guest_name);
                strcpy(rooms[i].guest_name, "");
                rooms[i].status = 0;
            } else {

                printf("\n\nRoom is not occupied.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("\nGuest not found.\n");
    }
    printf(" \n Press any key to continue:");

	getch();
    system("cls");
}
//mergefunction
void display_guests(Room rooms[], int num_rooms)
{
    system("cls");
    int found=0;
     printf("\n\nGUEST DETAILS :\n\n");

for (int i = 0; i < num_rooms; i++) {
            if (rooms[i].status == 1) {
                    found=1;
                printf("\n------------------------\n\n");
                printf("\n||ROOM No.: %d\t",rooms[i].room_number);
                printf("||Guest name : %s\t", rooms[i].guest_name);
                printf("||Mobile No. : %s\t",rooms[i].mobile);
                printf("||Nationality: %s\t",rooms[i].nat);
                printf("||Period Of Stay  : %s\t",rooms[i].period);
            }
    }
    if(found==0)
        printf("NO RECORDs FOUND\n\n");
    printf(" \n Press any key to continue:");

	getch();
    system("cls");

        }

//mergefunction

int main() {
//merge
int i=0;
	time_t t;
	time(&t);
	int choice;

	system("cls");

	printf("\t\t|                                             |\n");
	printf("\t\t|       ------------------------------        |\n");
	printf("\t\t|         WELCOME  TO  HOTEL  EIFA            |\n");
	printf("\t\t|       ------------------------------        |\n");

		for(i=0;i<80;i++)
		printf("-");
	    printf("\nDate and Time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");

	getch();
    system("cls");
    system("cls");

		system("cls");
    Room rooms[10];
    for (int i = 0; i < 10; i++) {
        rooms[i].room_number = i + 1;
        strcpy(rooms[i].guest_name, "");
        rooms[i].status = 0;
    }
    do{
        printf("\n");
        for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t\t|MAIN MENU|  \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\n\n\t\t Select an option:");
		printf("\n");
//merge


    // Initialize rooms
        printf("\n\n\n");
        printf("1. Display available rooms\n");
        printf("2. Book a room\n");
        printf("3. Check a guest\n");
        printf("4. Check out a guest\n");
        printf("5. Display all Guests\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_available_rooms(rooms, 10);
                break;
            case 2:
                book_room(rooms, 10);
                break;
            case 3:
                check_in(rooms, 10);
                break;
            case 4:
                check_out(rooms, 10);
                break;
            case 5 :
                display_guests(rooms,10);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                system("cls");
                break;
        }
    } while (choice != 0);

    return 0;
}
