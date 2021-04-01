/*Simple coffee vendor mechine in c*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*This function show and control the menu*/
int menu()
{
#define MAX 7
#define MIN 1
	system("cls");
	int position = 1;
	int keyPressed = 0;
	while (keyPressed != 13)
	{
		system("cls");
		printf("\n\t *****COFFEE MECHINE******\n");
		printf("\n\t :: CHOSE YOUR COFFEE :: (press ENTER to confirm / to chose use UP and DOWN arrow)\n\n");

		arrowHere(1, position);
		printf("BLACK COFFEE $30.00\n");
		arrowHere(2, position);
		printf("AMERICANO $50.00\n");
		arrowHere(3, position);
		printf("ESPRESSO $50.00\n");
		arrowHere(4, position);
		printf("FLAT WHITE $35.00\n");
		arrowHere(5, position);
		printf("MOCHA $100.00\n");
		arrowHere(6, position);
		printf("DOPPIO $85.00\n");
		arrowHere(7, position);
		printf("EXIT");

		keyPressed = getch();

		if (position != MAX && keyPressed == 80)
		{
			position++;
		}
		else if (position != MIN && keyPressed == 72)
		{
			position--;
		}
		else
		{
			position == position;
		}
	}
	return position;
}

/*show arrow key at selected position : as parameter value function takes the  Real possiton And The nevigated Position*/
void arrowHere(int relPos, int arPos)
{
	if (relPos == arPos)
	{
		printf("      >>  (\4)");
	}
	else
	{
		printf("          ()");
	}
}

/* This Function will give a option for enter quantity of a item*/

int quantity()
{
	int qnt = 0;
	printf("\n\n\t<\4>ENTER QUANTITY IN VALUE : ");
	printf("\n\t >>  ");
	scanf("%d", &qnt);
	return qnt;
}
/*This Function will create a bill for Customer: */
void create_bill(int orderCount, int order_list[10][2], float total)
{
	float priceList[6] = {30.00, 50.00, 50.00, 35.00, 100.00, 85.00};
	char coffeeName[6][20] = {"BLACK COFFEE", "AMERICANO", "ESPRESSO", "FLAT WHITE", "MOCHA", "DOPPIO"};
	int x;
	system("cls");
	printf("\n\t    \4\4\4\4 -- Payble Bill -- \4\4\4\4 ");
	printf("\n\t-------------------------------------");
	for (x = 0; x <= orderCount; x++)
	{
		printf("\n\t (\4) price: %.2f  %s (%d)", priceList[order_list[x][0]] * order_list[x][1], coffeeName[order_list[x][0]], order_list[x][1]);
	}
	printf("\n\t----------------------------------");
	printf("\n\t    TOTAL:  %.2f", total);
}

int main(int argc, char *argv[])
{
	int pos = 0;
	int qnt = 0;
	float total = 0;
	float priceList[6] = {30.00, 50.00, 50.00, 35.00, 100.00, 85.00};
	int order_list[10][2];
	int x = 0, i = 0;
	int key;
	while (1)
	{
		pos = menu();
		if (pos == 7)
		{
			exit(0);
		}
		qnt = quantity();
		total = total + (qnt * priceList[pos - 1]);
		order_list[x][0] = (pos - 1);
		order_list[x][1] = qnt;
		printf("\n\t<\4> PRESS 'ENTER' TO CONFIRM ORDER >> ");
		printf("\n\t<\4> PRESS 'UP KEY' TO ORDER MORE >> ");
		key = getch();
		if (key == 13)
		{
			break;
		}
		x++;
	}

	create_bill(x, order_list, total);

	return 0;
}

/*This code is programed by Abhishek Das */
/*GitHub profile link - https://github.com/avioXD*/

