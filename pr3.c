#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

int main(){
	srand(time(NULL));
	int balance = 5000;
	int choice, i;
	int multiplier = 1;
	int bet = 500;
	int game[3];
	
	while(1){
		printf("1)Auto game\n2)Show combinations\n3)Quit\n");
		scanf("%d", &choice);
		if(choice == 1){
			while(balance >= bet){
				multiplier = 1;
				balance -= bet;
				printf("\n\nYour current balance is %d, bet is %d\n", balance, bet);
				for(i = 0; i < 3; i++){
					game[i] = rand()%8;
					printf("%d ", game[i]);
				}
				switch(game[0]){
					case 0:
					case 1:
					case 2:
					case 3:
					case 4: 
						if (game[0] == game[1] && game[1] == game[2]) {
						multiplier = 3;
						}
						break;
					case 5:
					case 7:
						if (game[0] == game[1] && game[1] == game[2] && game[2] == 7){
							printf("JACKPOT!");
							system("pause");
						} else if (game[0] == game[1] && game[1] == game[2] && game[2] == 5){
							multiplier = 10;
							break;
						} else if (game[0] == game[1]) {
							multiplier = 5;
							break;
						} else {
						multiplier = 2;
						break; }
					case 6: 
						if (game[0] == game[1] && game[1] == game[2]) {
							printf("\nOHH NO! YOU LOSE ANOTHER 500...");
							balance -= bet;
							break;
						}	
				} if (multiplier != 1){
				printf("\n!!!You won %d credits!!!", bet*multiplier);
				balance += bet*multiplier; } else printf("\nYOU LOSE!");
			}
		printf("\nGAME OVER!");
		system("pause");
		}else if(choice == 2){
				MessageBox(0,"MULTIPLIER X2: 5XX 7XX\nMULTIPLIER X3: 000 111 222 333 444\nMULTIPLIER X5: 55X 77X\nMULTIPLIER X10: 555\nJACKPOT: 777\n","Winning combinations",MB_OK);
		}else return 0;
	}
	return 0;
}
