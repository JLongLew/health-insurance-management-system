#include "header.h"

//main function//
int main() {
	create_file();
	menu();
	return 0;
}
//Creating file at the beginning of the program//
void create_file() {
	FILE* f;
	//Read the file if the file is already existed//
	//Create a new file if the file is not existed//
	//For storing information of customers who subscribe to Plan120//
	if (f = fopen("Plan120.txt", "r")) {
		fclose(f);
	}
	else {
		f = fopen("Plan120.txt", "w");
		fprintf(f, "ID\t\tNAME\t\tAGE\tCONTACT_NUMBER\tHOUSE_NUMBER\tSTREET\t\tCITY\t\tSTATE\t\tHEALTH_HISTORY\t\tPLAN_TYPE\tCLAIM_LIMIT_TYPE\n");
		fclose(f);
	}
	//For storing information of customers who subscribe to Plan150//
	if (f = fopen("Plan150.txt", "r")) {
		fclose(f);
	}
	else {
		f = fopen("Plan150.txt", "w");
		fprintf(f, "ID\t\tNAME\t\tAGE\tCONTACT_NUMBER\tHOUSE_NUMBER\tSTREET\t\tCITY\t\tSTATE\t\tHEALTH_HISTORY\t\tPLAN_TYPE\tCLAIM_LIMIT_TYPE\n");
		fclose(f);
	}
	//For storing information of customers who subscribe to Plan200//
	if (f = fopen("Plan200.txt", "r")) {
		fclose(f);
	}
	else {
		f = fopen("Plan200.txt", "w");
		fprintf(f, "ID\t\tNAME\t\tAGE\tCONTACT_NUMBER\tHOUSE_NUMBER\tSTREET\t\tCITY\t\tSTATE\t\tHEALTH_HISTORY\t\tPLAN_TYPE\tCLAIM_LIMIT_TYPE\n");
		fclose(f);
	}
	//For storing details of claiming process for Plan120//
	if (f = fopen("Claim_plan120.txt", "r")) {
		fclose(f);
	}
	else {
		f = fopen("Claim_plan120.txt", "w");
		fprintf(f, "ID\t\tCLAIMED_YEAR\t\tAMOUNT_CLAIMED\t\tBALANCE(YEAR)(RM)\tBALANCE(LIFETIME)(RM)\n");
		fclose(f);
	}
	//For storing details of claiming process for Plan150//
	if (f = fopen("Claim_plan150.txt", "r")) {
		fclose(f);
	}
	else {
		f = fopen("Claim_plan150.txt", "w");
		fprintf(f, "ID\t\tCLAIMED_YEAR\t\tAMOUNT_CLAIMED\t\tBALANCE(YEAR)(RM)\tBALANCE(LIFETIME)(RM)\n");
		fclose(f);
	}
	//For storing details of claiming process for Plan200//
	if (f = fopen("Claim_plan200.txt", "r")) {
		fclose(f);
	}
	else {
		f = fopen("Claim_plan200.txt", "w");
		fprintf(f, "ID\t\tCLAIMED_YEAR\t\tAMOUNT_CLAIMED\t\tBALANCE(YEAR)(RM)\tBALANCE(LIFETIME)(RM)\n");
		fclose(f);
	}
}

//Menu-driven//
void menu() {
	int choice, statement;
	statement = 1;
	//For looping the menu again and again//
	while (statement == 1) {
		printf("--------------------------------------------------------------");
		printf("\nHEALTH INSURANCE MANAGEMENT SYSTEM");
		printf("\nPlease select one of the functions:");
		printf("\n1. Insurance Plan Subscription");
		printf("\n2. Claim Processing");
		printf("\n3. Accounts Information");
		printf("\n4. Searching Functionalities");
		printf("\n5. Exit");
		printf("\nYour choice:");
		scanf_s("%d", &choice);
		// Avoid useless input characters//
		while (getchar() != '\n');
		switch (choice) {
		case 1:
			subscription();
			break;
		case  2:
			claim();
			break;
		case 3:
			information();
			break;
		case 4:
			search();
			break;
		case 5:
			//End the program//
			return;
			break;
			//If the input not equal to 1-5, it will run the menu again//
		default:
			printf("Invalid input\n");
			statement = 1;
		}
	}
}

// Delete the spaces between the data while reading the file//
void no_spaces(char store[], char filter[]) {
	int a, b = 0;
	//Check whether there is a space within the fetched data//
	for (a = 0; store[a] != '\0'; a++) {
		//If there is not a space between two data, copy the whole data to an array for the use of program//
		if (store[a] != ' ') {
			filter[b] = store[a];
			b++;
		}
	}
	filter[b] = '\0';
}
