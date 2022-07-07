#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void information() {
	int a = 0, b = 0, c, d;
	char num_lifesubscriber[1000][10], num_yearsubscriber[1000][10];
	int total_amount_claimed = 0, num_exsubscriber = 0;
	//Declare file pointer//
	FILE* f = NULL;
	char cus[200], customer_id[10], chosen_claim[21];
	for (c = 0; c < 3; c++) {
		switch (c) {
		case 0:
			f = fopen("Plan120.txt", "r");
			break;
		case 1:
			f = fopen("Plan150.txt", "r");
			break;
		case 2:
			f = fopen("Plan200.txt", "r");
		}
		//Skip the first line in the file before reading the customer information//
		fgets(cus, 200, f);

		//Only read the needed information//
		for (fscanf(f, "%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s", customer_id, chosen_claim); !feof(f); fscanf(f, "%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s", customer_id, chosen_claim)) {
			if (strcmp(chosen_claim, "Lifetime") == 0) {
				strcpy(num_lifesubscriber[a], customer_id);
				a++;
			}
			else {
				strcpy(num_yearsubscriber[b], customer_id);
				b++;
			}
		}
		fclose(f);
	}
	int amount_claim, claim_in_rm, claim_in_sen, amount_year, yearleft_rm, yearleft_sen;
	for (d = 0; d < 2; d++) {
		switch (d) {
		case 0:
			for (c = 0; c < 3; c++) {
				switch (c) {
				case 0:
					f = fopen("Claim_plan120.txt", "r");
					break;
				case 1:
					f = fopen("Claim_plan150.txt", "r");
					break;
				case 2:
					f = fopen("Claim_plan200.txt", "r");
				}
				//Skip the first line in the file before reading the customer information//
				fgets(cus, 200, f);
				for (fscanf(f, "%s %*s %d%*c%d", customer_id, &claim_in_rm, &claim_in_sen); !feof(f); fscanf(f, "%s %*s %d%*c%d", customer_id, &claim_in_rm, &claim_in_sen)) {
					for (a = 0; a < 1000; a++) {
						if (strcmp(num_lifesubscriber[a], customer_id) == 0) {
							amount_claim = claim_in_rm * 100 + claim_in_sen;
							total_amount_claimed = total_amount_claimed + amount_claim;
						}
					}
					//Next new line//
					fgets(cus, 200, f);
				}
			}
			break;
		case 1:
			for (c = 0; c < 3; c++) {
				switch (c) {
				case 0:
					f = fopen("Claim_plan120.txt", "r");
					break;
				case 1:
					f = fopen("Claim_plan150.txt", "r");
					break;
				case 2:
					f = fopen("Claim_plan200.txt", "r");
				}
				//Skip the first line in the file before reading the customer information//
				fgets(cus, 200, f);
				for (fscanf(f, "%s %*s %*d%*c%*d %d%*c%d %*s", customer_id, &yearleft_rm, &yearleft_sen); !feof(f); fscanf(f, "%s %*s %*d%*c%*d %d%*c%d %*s", customer_id, &yearleft_rm, &yearleft_sen)) {
					for (a = 0; a < 1000; a++) {
						if (strcmp(num_yearsubscriber[a], customer_id) == 0) {
							amount_year = yearleft_rm * 100 + yearleft_sen;
							if (amount_year == 0) {
								num_exsubscriber = num_exsubscriber + 1;
							}
						}
					}
				}
			}
		}
	}
	fclose(f);
	printf("\nTotal amount claimed by Lifetime Claim Limit subscribers(RM): %d.%.2d\nTotal number of Annual Claim Limit subscribers who have exhausted all their eligible amount: %d\n\n", total_amount_claimed / 100, total_amount_claimed % 100, num_exsubscriber);
}