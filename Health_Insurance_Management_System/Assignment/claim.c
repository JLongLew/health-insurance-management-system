#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

void claim() {
	//Create structure for storing the plan details//
	typedef struct {
		int name, monthly_premium, annual_limit, lifetime_limit, room_charges, icu_charges;
	}plan_type;
	//Three structures for three different plan types//
	plan_type plan120 = { 120,120,12000000,60000000,120,250 };
	plan_type plan150 = { 150,150,15000000,75000000,150,400 };
	plan_type plan200 = { 200,200,20000000,100000000,200,700 };
	plan_type* p1 = &plan120, * p2 = &plan150, * p3 = &plan200;

	int choice, main_repeat = 1, repeat, a, count, amount_claim, claim_in_rm, claim_in_sen, amount_year, yearleft_rm, yearleft_sen, amount_life, lifeleft_rm, lifeleft_sen, sum;
	int year = 2020;
	char customer_id[10], cus[200], input_id[50], chosen_claim[21];
	//This structure is used to store the details of users' chosen plan//
	plan_type chosen_plan;
	int day_ward = 0, day_icu = 0, services = 0, surgery = 0, others = 0;

	while (main_repeat == 1) {
		repeat = 1;
		while (repeat == 1) {
			printf("Enter customer ID, 999 to exit:");
			gets(customer_id);
			//999 to exit claim function and back to menu function//
			if (strcmp(customer_id, "999") == 0) {
				return;
			}
			//Declare file pointer//
			FILE* f = NULL;
			//This for loop is used to check whether customer ID is exist in each Claim_plan text file//
			for (a = 0; a < 3; a++) {
				switch (a) {
				case 0:
					f = fopen("Claim_plan120.txt", "r");
					chosen_plan = plan120;
					break;
				case 1:
					f = fopen("Claim_plan150.txt", "r");
					chosen_plan = plan150;
					break;
				case 2:
					f = fopen("Claim_plan200.txt", "r");
					chosen_plan = plan200;
					break;
				default:
					printf("File cannot be opened.");
				}
				//Skip the first line in the file before input_iding the customer information//
				fgets(cus, 200, f);
				//As the first line is skipped, hence add 1 into count//
				count = 1;
				//This for loop is used to fetch the available balance of the customer//
				for (fscanf(f, "%s", input_id); !feof(f); fscanf(f, "%s", input_id)) {
					count++;
					//To check whether the user's input ID is same with the customer ID in each file//
					if (strcmp(input_id, customer_id) == 0) {
						fscanf(f, "%*s %d%*c%d %d%*c%d %d%*c%d", &claim_in_rm, &claim_in_sen, &yearleft_rm, &yearleft_sen, &lifeleft_rm, &lifeleft_sen);
						//To calculate the available balance of customer//
						amount_claim = claim_in_rm * 100 + claim_in_sen;
						amount_year = yearleft_rm * 100 + yearleft_sen;
						amount_life = lifeleft_rm * 100 + lifeleft_sen;
						fclose(f);
						switch (chosen_plan.name) {
						case 120:
							f = fopen("Plan120.txt", "r");
							break;
						case 150:
							f = fopen("Plan150.txt", "r");
							break;
						case 200:
							f = fopen("Plan200.txt", "r");
						}
						//Skip the first line in the file before reading the customer information//
						fgets(cus, 200, f);
						for (fscanf(f, "%s", input_id); !feof(f); fscanf(f, "%s", input_id)) {
							//To check whether the user's input ID is same with the customer ID in each file//
							if (strcmp(input_id, customer_id) == 0) {
								fscanf(f, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s", chosen_claim);
								fclose(f);
								repeat = 0;
								break;
							}
							else {
								//Go to the next line to check whether the user's input ID is same with the customer ID//
								fgets(cus, 200, f);
							}
						}
						break;
					}
					else {
						//Go to the next line to check whether the user's input ID is same with the customer ID//
						fgets(cus, 200, f);
					}
				}
				//After the customer ID has been found, the for loop will be break//
				if (repeat == 0) {
					break;
				}
				//After checking all the file, if the input ID still haven't found, the following message will be printed//
				if (a == 2) {
					printf("Please enter a valid input.\n");
				}
			}
		}
		repeat = 1;
		while (repeat == 1) {
			repeat = 0;
			printf("How many days do you stay in normal wards: ");
			scanf_s("%d", &day_ward);
			// Avoid useless input characters//
			while (getchar() != '\n');
			printf("How many days do you stay in ICU: ");
			scanf_s("%d", &day_icu);
			// Avoid useless input characters//
			while (getchar() != '\n');
			printf("Enter the amount of hospital supplies and services in RM: ");
			scanf_s("%d", &services);
			// Avoid useless input characters//
			while (getchar() != '\n');
			printf("Enter the amount of surgical fees in RM: ");
			scanf_s("%d", &surgery);
			// Avoid useless input characters//
			while (getchar() != '\n');
			printf("Enter the amount of other fees in RM: ");
			scanf_s("%d", &others);
			// Avoid useless input characters//
			while (getchar() != '\n');

			//Calculate the sum of the claimed amount//
			sum = (day_ward * chosen_plan.room_charges + day_icu * chosen_plan.icu_charges + services + surgery + others) * 100;

			//To check the amount of the available balance in customer's chosen claim limit type//
			if (strcmp(chosen_claim, "Lifetime") == 0) {
				if (sum > amount_life) {
					//If the sum of claimed amount excess the available balance, then customers can only claim the left balance//
					printf("Your available balance for current plan is not enough.\n");
					sum = amount_life;
				}
			}
			else {
				if (sum > amount_year) {
					//If the sum of claimed amount excess the available balance, then customers can only claim the left balance//
					printf("Your available balance for current plan is not enough.\n");
					sum = amount_year;
				}
			}
			//Declare file pointer//
			FILE* f = NULL;
			switch (chosen_plan.name) {
			case 120:
				f = fopen("Claim_plan120.txt", "r+");
				break;
			case 150:
				f = fopen("Claim_plan150.txt", "r+");
				break;
			case 200:
				f = fopen("Claim_plan200.txt", "r+");
			}

			//To find of the line of data that needed to be modified//
			for (cus[0] = fgetc(f); cus[0] != EOF; cus[0] = fgetc(f)) {
				if (cus[0] == '\n') {
					count--;
					if (count == 1) {
						break;
					}
				}
			}
			fseek(f, 0, SEEK_CUR);

			//To check the customer's chosen claim type limit//
			if (strcmp(chosen_claim, "Lifetime") == 0) {
				//Update the amount_claimed and the balance of their plan//
				fprintf(f, "%-16s%-24d%11d.%-12.2d\t  0.00\t\t%11d.%-12.2d", customer_id, year, (amount_claim + sum) / 100, (amount_claim + sum) % 100, (amount_life - sum) / 100, (amount_life - sum) % 100);
			}
			else {
				//Update the amount_claimed and the balance of their plan//
				fprintf(f, "%-16s%-24d%11d.%-12.2d%11d.%-12.2d\t  0.00\t\t", customer_id, year, (amount_claim + sum) / 100, (amount_claim + sum) % 100, (amount_year - sum) / 100, (amount_year - sum) % 100);
			}
			fclose(f);
			main_repeat = 1;
		}
	}
}