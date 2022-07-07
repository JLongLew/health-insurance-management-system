#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


//Create structure for storing the plan details//
typedef struct  {
	int name, monthly_premium, annual_limit, lifetime_limit, room_charges, icu_charges;
}plan_type;
//Three structures for three different plan types//
plan_type plan120 = { 120,120,12000000,60000000,120,250 };
plan_type plan150 = { 150,150,15000000,75000000,150,400 };
plan_type plan200 = { 200,200,20000000,100000000,200,700 };
plan_type* p1 = &plan120, * p2 = &plan150, * p3 = &plan200;

void plan_name(plan_type* p);

//This function is used for storing the details of plans//
void plan_name(plan_type *p) {
	printf("\nPlan Name: Plan%d\nMonthly Premium: %d\nAnnual Claim Limit : %d\nLifetime Claim Limit : %d", (*p).name,(*p).monthly_premium, (*p).annual_limit/100, (*p).lifetime_limit/100);
	printf("\nRoom Charges : %d / day\nIntensive Care Unit(ICU) Charge: %d/day", (*p).room_charges, (*p).icu_charges);
	printf("\nHospital Supplies and Services: As charged. Subject to approval by ZeeMediLife\nSurgical Fees: As charged. Subject to approval by ZeeMediLife.\nOther Fees: As charged. Subject to approval by ZeeMediLife.");
}

void subscription() {
	//Main_repeat is a while loop for the entire subscription program, if user want to enter another customer's data, it will repeat again//
	//Repeat is a while loop for the seperate part of the subscription program, if user enters a wrong input, it will require user to enter again//
	int main_repeat = 1, repeat, age, days, plan, claim, age_group, count;
	char cus[200];
	char id[5], customer_id[9];
	char cus_name[100], cus_contact_number[20], cus_house_number[20], cus_street[100], cus_city[50], cus_state[20], cus_health_history[100];
	char name[100], contact_number[20], house_number[20], street[100], city[50], state[20], health_history[100];
	//This structure is used to store the details of users' chosen plan and display them out after they entered their information//
	plan_type chosen_plan;
	char chosen_claim[30];

	//For main_repeat and repeat, '1' for entering the loop, '0' for ending the loop//
	while (main_repeat == 1) {
		repeat = 1;
		//1. Ask age//
		while (repeat == 1) {
			repeat = 0;
			//If users didn't want to enter another subscription, '999' for them to exit this function and enter to the menu//
			printf("\nEnter your age, (999) to exit:");
			scanf_s("%d", &age);
			// Avoid useless input characters//
			while (getchar() != '\n');
			if (age == 0) {
				//Ask day of the baby//
				printf("How many days old the baby is:");
				scanf_s("%d", &days);
				// Avoid useless input characters//
				while (getchar() != '\n');
				//Baby under 15 days is not eligible for applying insurance//
				if (days >= 15) {
					age_group = 1;
				}
				else {
					printf("Your baby is not eligible for applying any plans.\n");
					repeat = 1;
				}
			}
			else if (age >= 1 && age <= 20) {
				age_group = 1;
			}
			else if (age >= 21 && age <= 40) {
				age_group = 2;
			}
			else if (age >= 41 && age <= 54) {
				age_group = 3;
			}
			else if (age == 999) {
				printf("\n");
				return;
			}
			else {
				printf("Your age is not eligible for applying any plans.");
				repeat = 1;
			}
		}
		//Repeat change to 1 again to enter the next loop//
		repeat = 1;
		//2. Choose plan//
		if (age_group == 1) {
			printf("\nYou are eligible for applying the following plans:");
			//Plan120 descibrition//
			printf("\n1. Plan120");
			plan_name(p1);
			//Plan150 descibrition//
			printf("\n\n2. Plan150");
			plan_name(p2);
			//Plan200 descibrition//
			printf("\n\n3. Plan200");
			plan_name(p3);
			while (repeat == 1) {
				repeat = 0;
				printf("\n\nEnter your choice:");
				scanf_s("%d", &plan);
				// Avoid useless input characters//
				while (getchar() != '\n');
				if (plan == 1) {
					chosen_plan = plan120;
				}
				else if (plan == 2) {
					chosen_plan = plan150;
				}
				else if (plan == 3) {
					chosen_plan = plan200;
				}
				else {
					printf("\nPlease choose a listed plan.");
					repeat = 1;
				}
			}
		}
		else if (age_group == 2) {
			printf("\nYou are eligible for applying the following plans:");
			//Plan150 descibrition//
			printf("\n1. Plan150");
			plan_name(p2);
			//Plan200 descibrition//
			printf("\n\n2. Plan200");
			plan_name(p3);
			while (repeat == 1) {
				repeat = 0;
				printf("\n\nEnter your choice:");
				scanf_s("%d", &plan);
				// Avoid useless input characters//
				while (getchar() != '\n');
				if (plan == 1) {
					chosen_plan = plan150;
				}
				else if (plan == 2) {
					chosen_plan = plan200;
				}
				else {
					printf("\nPlease choose a listed plan.");
					repeat = 1;
				}
			}
		}
		else if (age_group == 3) {
			printf("\nYou are eligible for applying the following plans:");
			//Plan20\n0 descibrition//
			printf("\n1. Plan200");
			plan_name(p3);
			while (repeat == 1) {
				repeat = 0;
				printf("\n\nEnter your choice:");
				scanf_s("%d", &plan);
				// Avoid useless input characters//
				while (getchar() != '\n');
				if (plan == 1) {
					chosen_plan = plan200;
				}
				else {
					printf("\nPlease choose a listed plan.");
					repeat = 1;
				}
			}
		}
		//Repeat change to 1 again to enter the next loop//
		repeat = 1;
		//3. Choose claim limit type//
		printf("\n\nPlease choose a claim limit type:");
		printf("\n1. Annual Claim Limit");
		printf("\n2. Lifetime Claim Limit");
		while (repeat == 1) {
			repeat = 0;
			printf("\nEnter your choice:");
			scanf_s("%d", &claim);
			// Avoid useless input characters//
			while (getchar() != '\n');
			if (claim == 1) {
				strcpy_s(chosen_claim, 30, "Annual Claim Limit");
				chosen_plan.lifetime_limit = NULL;
			}
			else if (claim == 2) {
				strcpy_s(chosen_claim, 30, "Lifetime Claim Limit");
				chosen_plan.annual_limit = NULL;
			}
			else {
				printf("\nPlease choose a listed claim limit.");
				repeat = 1;
			}
		}
		//4. Customer information//
		// Delete the spaces between the data//
		printf("\n\nName: ");
		gets(cus_name);
		no_spaces(cus_name,name);
		printf("Contact Number: ");
		gets(cus_contact_number);
		no_spaces(cus_contact_number, contact_number);
		printf("House Number: ");
		gets(cus_house_number);
		no_spaces(cus_house_number, house_number);
		printf("Street: ");
		gets(cus_street);
		no_spaces(cus_street, street);
		printf("City: ");
		gets(cus_city);
		no_spaces(cus_city, city);
		printf("State: ");
		gets(cus_state);
		no_spaces(cus_state, state);
		printf("Health History: ");
		gets(cus_health_history);
		no_spaces(cus_health_history, health_history);
		count = 0;
		//Open customer subscription files// 
		FILE* f_subscribe = NULL; 
		//Open customer claim files//
		FILE* f_claim = NULL;    
		switch (chosen_plan.name) {
		case 120:
			f_subscribe = fopen("Plan120.txt", "a+");
			f_claim = fopen("Claim_plan120.txt", "a");
			break;
		case 150:
			f_subscribe = fopen("Plan150.txt", "a+");
			f_claim = fopen("Claim_plan150.txt", "a");
			break;
		case 200:
			f_subscribe = fopen("Plan200.txt", "a+");
			f_claim = fopen("Claim_plan200.txt", "a");
			break;
		default:
			printf("File cannot be opened.");
		}
		//Skip the first line in the file before writing the customer information//
		fgets(cus, 200, f_subscribe);
		// Counting the number of customers//
		while (!feof(f_subscribe)) {
			if (fgetc(f_subscribe) - '0' == age_group) {		
				count++;
			}
			fgets(cus, 200, f_subscribe);
		}
		// Generate a unique sequence number for the customers as there will be different level of number when excess 10,100,1000//
		if (count < 10) {
			sprintf(id, "00%d", count);
		}
		else if (count - 2 < 100) {
			sprintf(id, "0%d", count);
		}
		else {
			sprintf(id, "%d", count);
		}
		//Generate a customer id//
		//Customer ID format: ABBBXXX A:AGE_GROUP(1,2,3) BBB:CHOSEN_PLAN(120,150,200) XXX:SEQUENCE NUMBER(001,002,...)//
		sprintf(customer_id, "%d%d%s", age_group, chosen_plan.name, id);
		//Store customer information to subscribe file//
		fprintf(f_subscribe, "%-16s%-17s%-7d%-16s%-16s%-16s%-16s%-16s%-24s%-16d%s\n", customer_id, name, age, contact_number, house_number, street, city, state, health_history, chosen_plan.name, chosen_claim);
		//Store plan information to claim file//
		fprintf(f_claim, "%-16sN/A\t\t\t\t0.00\t\t%11d.%-12.2d%11d.%-12.2d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n", customer_id, chosen_plan.annual_limit / 100, chosen_plan.annual_limit % 100, chosen_plan.lifetime_limit / 100, chosen_plan.lifetime_limit % 100);
		fclose(f_subscribe);
		fclose(f_claim);
		//5. Show customer details and plan information to customer//
		printf("\nCustomer ID: %s\nName: %s\nAge: %d\nPhone Number: %s\nAddress:%s, %s, %s, %s\nHealth History: %s\nChosen Plan: Plan%d\nClaim Limit Type: %s\n", customer_id, cus_name, age, cus_contact_number, cus_house_number, cus_street, cus_city, cus_state, cus_health_history, chosen_plan.name, chosen_claim);
		//Repeat the subscription function again//
		main_repeat = 1;
	}
}
