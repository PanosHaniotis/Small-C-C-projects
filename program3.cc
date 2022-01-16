#include<stdio.h>//for IO
#include<stdlib.h>//for exit() function
#include<ctype.h>//for toupper(char c) function


typedef struct{
	char name;
	int price;
}fruit;

int n = 5; //default fruit items 

//------------------*functions*---------------------------
void displayMenu(fruit fruits[],int n){
	printf("***** Shop Menu *****\n");
	printf("Item:  Price\n");
	for (int i = 0; i < n; i++)
	{
		printf("%c: %d $\n", fruits[i].name, fruits[i].price);
	}
}

int getItemPrice(char choice,fruit fruits[]){
	
	
	for (int i = 0; i < n; i++){
		if(choice == fruits[i].name || choice == toupper(fruits[i].name) ){
			return fruits[i].price;
		}
	}
	
	return -1;

}

int withinBudget(int budget, char purchase, fruit fruits[]){
	int price = 0;

	price = getItemPrice(purchase, fruits);

	if (budget < price || price == -1 )
	{
	
		return 0;
	}

	else
	{
		
		
		return 1;
	}
}

int purchaseItem(int budget, char purchase, fruit fruits[]){
	int	price = getItemPrice(purchase,fruits);

	if(withinBudget(budget,purchase,fruits))
	{
	
		printf("Purchase Successful!\n");
		
		printf("Purchase details\n");
		printf("-----------------\n");
		printf("Item: %c\n", purchase);
		printf("Price: $%i\n", price);
		printf("Remaining budget: $%i\n", budget - price);
		return budget - price;
	}
	else
	{
		printf("PURCHASE FAILED!\n");
		printf("Low budget or missing item.");
		return budget;
	}

	
}

int IsItemExists(fruit fruits[], char name){
	
	for (int i = 0; i < n; i++){
		if(name == fruits[i].name || name == toupper(fruits[i].name) ){
			return i;
		}
	}
	return -1;
}



//----------------------*main*----------------------------
int main(){


	
//-----------------Item Prefix----------------------------
	const char NAMES[5][10] = {"Apple","Orange","Mango","Pear","Grapes"};
	printf("*** Item Prefixes ***\n");
	for (int i = 0; i < 5; i++){
		printf("%c: %s\n",NAMES[i][0], NAMES[i]);
	}
	printf("******************\n\n");
	
//----------------Shopkeeper Panel------------------------
	printf("*** SHOPEKEEPER PANEL ***\n");
	
	printf("\nHow many fruits do you want in your shop?");
	scanf("%d",&n);
	if(n>25) {n=25;printf("\nNot enough characters, 25 fruits!");}//-----------------
	
	//fruit fruits[n]; //fruits initialization for C11 and after
	fruit* fruits = (fruit*)calloc(n, sizeof(fruit)); 
	
	for (int i = 0; i < n; i++){
		int error = 1; //duplicate item
		char shopkeeperName; //shopkeeper choice
		while(error){
			printf("\nPlease enter fruit prefix: ");
			//scanf(" %c", &shopkeeperName,1);					  //-----------------
			shopkeeperName = (char)(97+ rand()%25);				 //------------------

			
			if(IsItemExists(fruits, shopkeeperName) == -1){
				error = 0;
				fruits[i].name = shopkeeperName;
			}else{
				printf("\nNo duplicate items!");
			}
		}
		
		printf("Please enter '%c' price:$", fruits[i].name);
		//scanf("%i", &fruits[i].price);						  //-----------------
		fruits[i].price = (int)(rand() % 9)+1;				     //------------------
	}
	printf("\n******************\n\n");
	
//----------------Customer Panel---------------------------
	printf("*** CUSTOMER PANEL ***\n");
	printf("Please enter your budget: $");
	int budget = 0;
	scanf("%i", &budget);
	
	char cstmrc = 0; //customer choice
	char cont = 'y'; //continue
	
	while (cont =='y'){
		displayMenu(fruits, n);
		
		printf("Please enter Item Prefix from the Menu to purchase:");
		scanf(" %c", &cstmrc, 1);
		
		budget = purchaseItem(budget, cstmrc, fruits);
		
		printf("\nWhould you like to continue shopping? y/n:");
		scanf(" %c", &cont, 1);
		
	}
	
	printf("\n\nThanks for shopping with us!\n");
	return 0;
}
