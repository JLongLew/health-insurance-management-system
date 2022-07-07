#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fetch_data(char string1[], char string2[], FILE* f_claim, char* amount_year, char* amount_claim, char chosen_claim[], char* balance);

//This function is used for fetching the data from claim_plan file//
void fetch_data(char string1[], char string2[], FILE* f_claim, char* amount_year, char* amount_claim, char chosen_claim[], char* balance) {
	if (strcmp(string1, string2) == 0) {
		fscanf(f_claim, "%s %s", amount_year, amount_claim);
		if (strcmp(chosen_claim, "Annual") == 0) {
			fscanf(f_claim, "%s", balance);
			fgets(string1, 200, f_claim);
		}
		else {
			fscanf(f_claim, "%*s %s", balance);
		}
	}
	else {
		fgets(string1, 200, f_claim);
	}
}

void search() {
	//Main_repeat is a while loop for the entire search program, if user want to search another data, it will repeat again//
	//Repeat is a while loop for the seperate part of the search program, if user enters a wrong input, it will require user to enter again//
	int choice, a, repeat, main_repeat = 1, plan, age;
	char name_or_id[100], cus_name[100], customer_id[10];
	int cus_plan, cus_age;
	char cus_chosen_plan[21];
	char name[100], contact_number[100], house_number[100], street[100], city[100], state[100], health_history[100], chosen_claim[21];
	char amount_year[5], amount_claim[100], balance[100];
	char cus[200];
	FILE* f_subscribe = NULL;
	FILE* f_claim = NULL;

	//For main_repeat and repeat, '1' for entering the loop, '0' for ending the loop//
	while (main_repeat == 1) {
		main_repeat = 0;
		printf("\nDo you want use searching functionalities by entering: ");
		printf("\n1. Customer ID or Name");
		printf("\n2. Plan, Claim Limit Type and Age");
		printf("\n999. Exit");
		printf("\nEnter your choice: ");
		//Choice variable only accepts the number(1,2), others will be assume as invalid input//
		scanf_s("%d", &choice);
		// Avoid useless input characters//
		while (getchar() != '\n');
		repeat = 1;
		switch (choice) {
		//For searching by ID or customer name//
		case 1:
			while (repeat == 1) {
				repeat = 0;
				printf("\nDo you want use searching functionalities by entering: ");
				printf("\n1. Customer ID");
				printf("\n2. Customer Name");
				printf("\nEnter your choice: ");
				scanf_s("%d", &choice);
				// Avoid useless input characters//
				while (getchar() != '\n');
				switch (choice) {
				//For searching by customer ID//
				case 1:
					repeat = 1;
					while (repeat == 1) {
						printf("Enter Customer ID: ");
						gets(name_or_id);
						//This for loop is used to open all the text files//
						for (a = 0; a < 3; a++) {
							switch (a) {
							case 0:
								f_subscribe = fopen("Plan120.txt", "r");
								f_claim = fopen("Claim_plan120.txt", "r");
								break;
							case 1:
								f_subscribe = fopen("Plan150.txt", "r");
								f_claim = fopen("Claim_plan150.txt", "r");
								break;
							case 2:
								f_subscribe = fopen("Plan200.txt", "r");
								f_claim = fopen("Claim_plan200.txt", "r");
							}
							//Skip the first line in the file before reading the customer information//
							fgets(cus, 200, f_subscribe);
							//Skip the first line in the file before reading the customer information//
							fgets(cus, 200, f_claim);
							//This for loop is used to check customer ID in all the text files//
							for (fscanf(f_subscribe, "%s", customer_id); !feof(f_subscribe); fscanf(f_subscribe, "%s", customer_id)) {
								//This is for matching the input and the data in each file//
								if (strcmp(customer_id, name_or_id) == 0) {
									//If matched, the program will fetch the data from the specific file and store them in different variables//
									fscanf(f_subscribe, "%s %d %s %s %s %s %s %s %d %s", name, &age, contact_number, house_number, street, city, state, health_history, &plan, chosen_claim);
									for (fscanf(f_claim, "%s", cus); !feof(f_claim); fscanf(f_claim, "%s", cus)) {
										fetch_data(cus, name_or_id, f_claim, amount_year, amount_claim, chosen_claim, balance);
									}
									fclose(f_subscribe);
									//What about the f_claim file????
									//Display the customer's information//
									printf("\nCustomer ID: %s\nName: %s\nAge: %d\nContact Number: %s\nAddress:\t%s, %s,\n\t\t %s,\n\t\t%s\nHealth History: %s\nPlan: %d\nClaim Limit Type: %s\nClaimed Year: %s\nTotal of Claimed Insurance: %s\nAvailable Balance: %s\n", customer_id, name, age, contact_number, house_number, street, city, state, health_history, plan, chosen_claim, amount_year, amount_claim, balance);
									repeat = 0;
									break;
								}
								fgets(cus, 200, f_subscribe);
							}
							if (repeat == 0) {
								break;
							}
						}
						if (repeat == 1) {
							printf("Please enter a valid customer ID.\n");
						}
					}
					break;
				case 2:
					repeat = 1;
					while (repeat == 1) {
						printf("Customer Name: ");
						gets(cus_name);
						no_spaces(cus_name, name_or_id);
						//This for loop is used to open all the text files//
						for (a = 0; a < 3; a++) {
							switch (a) {
							case 0:
								f_subscribe = fopen("Plan120.txt", "r");
								f_claim = fopen("Claim_plan120.txt", "r");
								break;
							case 1:
								f_subscribe = fopen("Plan150.txt", "r");
								f_claim = fopen("Claim_plan150.txt", "r");
								break;
							case 2:
								f_subscribe = fopen("Plan200.txt", "r");
								f_claim = fopen("Claim_plan200.txt", "r");
							}
							//Skip the first line in the file before reading the customer information//
							fgets(cus, 200, f_subscribe);
							//Skip the first line in the file before reading the customer information//
							fgets(cus, 200, f_claim);
							//This for loop is used to check customer Name in all the text files//
							for (fscanf(f_subscribe, "%s %s", customer_id, name); !feof(f_subscribe); fscanf(f_subscribe, "%s %s", customer_id, name)) {
								//This is for matching the input and the data in each file//
								if (strcmp(name, name_or_id) == 0) {
									//If matched, the program will fetch the data from the specific file and store them in different variables//
									fscanf(f_subscribe, "%s %d %s %s %s %s %s %s %d %s", name, &age, contact_number, house_number, street, city, state, health_history, &plan, chosen_claim);
									for (fscanf(f_claim, "%s", cus); !feof(f_claim); fscanf(f_claim, "%s", cus)) {
										fetch_data(cus, customer_id, f_claim, amount_year, amount_claim, chosen_claim, balance);
									}
									repeat = 0;
									//Display the customer's information//
									printf("\nCustomer ID: %s\nName: %s\nAge: %d\nContact Number: %s\nAddress:\t%s, %s,\n\t\t %s,\n\t\t%s\nHealth History: %s\nPlan: %d\nClaim Limit Type: %s\nClaimed Year: %s\nTotal of Claimed Insurance: %s\nAvailable Balance: %s\n", customer_id, name, age, contact_number, house_number, street, city, state, health_history, plan, chosen_claim, amount_year, amount_claim, balance);
								}
								fgets(cus, 200, f_subscribe);
								if (repeat == 1) {
									printf("File cannot be opened.");
								}
							}
						}
					}
					break;
				default:
					printf("Please enter a valid input.\n");
					repeat = 1;
				}
			}
			//Break for ending a case in the switch//
			break;
		//For searching by plan, claim limit type and age//
		case 2:
			//Repeat change to 1 again to enter the next loop//
			repeat = 1;
			//1. Select a plan//
			printf("\nPlease select a plan:");
			printf("\n1. Plan120");
			printf("\n2. Plan150");
			printf("\n3. Plan200");
			while (repeat == 1) {
				repeat = 0;
				printf("\nEnter Choice:");
				scanf_s("%d", &choice);
				// Avoid useless input characters//
				while (getchar() != '\n');
				switch (choice) {
				case 1:
					cus_plan = 120;
					break;
				case 2:
					cus_plan = 150;
					break;
				case 3:
					cus_plan = 200;
					break;
				default:
					printf("Please select a valid plan.");
					repeat = 1;
				}
			}
			//Repeat change to 1 again to enter the next loop//
			repeat = 1;
			//2. Select a claim limit type//
			printf("\nPlease choose a claim limit type:");
			printf("\n1.Annual Claim Limit");
			printf("\n2.Lifetime Claim Limit");
			while (repeat == 1) {
				repeat = 0;
				printf("\nEnter your choice: ");
				scanf_s("%d", &choice);
				// Avoid useless input characters//
				while (getchar() != '\n');
				switch (choice) {
				case 1:
					strcpy(cus_chosen_plan, "Annual");
					break;
				case 2:
					strcpy(cus_chosen_plan, "Lifetime");
					break;
				default:
					printf("Please choose a listed claim limit type. ");
					repeat = 1;
				}
			}
			//3. Select age//
			printf("Enter age: ");
			scanf_s("%d", &cus_age);
			// Avoid useless input characters//
			while (getchar() != '\n');
			repeat = 1;
			//This for loop is used to open all the text files//
			for (a = 0; a < 3; a++) {
				switch (a) {
				case 0:
					f_subscribe = fopen("Plan120.txt", "r");
					f_claim = fopen("Claim_plan120.txt", "r");
					break;
				case 1:
					f_subscribe = fopen("Plan150.txt", "r");
					f_claim = fopen("Claim_plan150.txt", "r");
					break;
				case 2:
					f_subscribe = fopen("Plan200.txt", "r");
					f_claim = fopen("Claim_plan200.txt", "r");
				}
				//Skip the first line in the file before reading the customer information//
				fgets(cus, 200, f_subscribe);
				//Skip the first line in the file before reading the customer information//
				fgets(cus, 200, f_claim);
				//This for loop is used to check plan type, claim type limit and age in all the text files//
				for (fscanf(f_subscribe, "%s %s %d %s %s %s %s %s %s %d %s", customer_id, name, &age, contact_number, house_number, street, city, state, health_history, &plan, chosen_claim); !feof(f_subscribe); fscanf(f_subscribe, "%s %s %d %s %s %s %s %s %s %d %s", customer_id, name, &age, contact_number, house_number, street, city, state, health_history, &plan, chosen_claim)) {
					if (cus_plan == plan && strcmp(cus_chosen_plan, chosen_claim) == 0 && cus_age == age) {
						for (fscanf(f_claim, "%s", cus); !feof(f_claim); fscanf(f_claim, "%s", cus)) {
							//If matched, the program will fetch the data from the specific file and store them in different variables//
							fetch_data(cus, customer_id, f_claim, amount_year, amount_claim, chosen_claim, balance);
							//Display the customer's information//
							printf("\nCustomer ID: %s\nName: %s\nAge: %d\nContact Number: %s\nAddress:%s, %s, %s, %s\nHealth History: %s\nPlan: %d\nClaim Limit Type: %s\nClaimed Year: %s\nTotal of Claimed Insurance: %s\nAvailable Balance: %s\n", customer_id, name, age, contact_number, house_number, street, city, state, health_history, plan, chosen_claim, amount_year, amount_claim, balance);
							repeat = 0;
						}
					}
					//Skip the last two words in the file and read the next line//
					fgets(cus, 200, f_subscribe);
				}
			}
			if (repeat == 1) {
				printf("Can't find the specific age.\n");
			}
			break;
		//999 for exit search function and back to menu
		case 999:
			printf("\n");
			return;
			break;
		default:
			printf("Please select the available choice.\n");
			main_repeat = 1;
		}
	}
}