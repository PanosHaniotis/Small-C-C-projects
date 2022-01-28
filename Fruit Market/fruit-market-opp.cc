#include<ctype.h>//for toupper(char c) function
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;







class shop{

	struct fruit{
		string name;
		int price;
	};
	
	fruit* fruits;
	int budget;
	int numberOfFruits;
	
	
	
	
	
	
	void displayMenu(){
		cout<<"***** Shop Menu *****\n";
		cout<<"Item:  Price\n";
		for (int i = 0; i < numberOfFruits; i++)
		{
			cout<<fruits[i].name<<" : "<<fruits[i].price<<std::endl;
		}
	}	

	int getItemPrice(char choice){
		
		
		for (int i = 0; i < numberOfFruits; i++){
			if(choice == fruits[i].name[0] || choice == toupper(fruits[i].name[0]) ){
				return fruits[i].price;
			}
		}
		
		return -1;
	
	}
	
	int withinBudget(char purchase){
		int price = 0;
	
		price = getItemPrice(purchase);
	
		if (budget < price || price == -1 )
		{
		
			return 0;
		}
	
		else
		{
			
			
			return 1;
		}
	}
	
	int purchaseItem(char purchase){
		int	price = getItemPrice(purchase);
	
		if(withinBudget(purchase))
		{
		
			cout<<"Purchase Successful!\n"
			<<"Purchase details\n"
			<<"-----------------\n"
			<<"Item: "<<purchase<<"\n"
			<<"Price: $"<<price<<"\n"
			<<"Remaining budget: $"<<budget - price<<"\n";
			return budget - price;
		}
		else
		{
			cout<<"PURCHASE FAILED!\n"
			<<"Low budget or missing item.";
			return budget;
		}
	
		
	}
	
	int IsItemExists(char name){
		
		for (int i = 0; i < numberOfFruits; i++){
			if(name == fruits[i].name[0] || name == toupper(fruits[i].name[0]) ){
				return i;
			}
		}
		return -1;
	}


	
	
	
	void itemPrefixes(){
		
		const char NAMES[5][10] = {"Apple","Orange","Mango","Pear","Grapes"};
		cout<<"*** Item Prefixes ***\n";
		for (int i = 0; i < 5; i++){
			cout<<NAMES[i][0]<<" : "<<NAMES[i]<<std::endl;
		}
		cout<<"******************\n\n";
	
	}

	void initializeFruits(){
		
		cout<<"\nHow many fruits do you want in your shop?";
		cin>>numberOfFruits;
		
		//fruits = (fruit*)calloc(numberOfFruits, sizeof(fruit)); 
		fruits = new fruit[numberOfFruits];
		
		for (int i = 0; i < numberOfFruits; i++){
			int error = 1; //duplicate item
			string shopkeeperName; //shopkeeper choice
			while(error){
				cout<<"\nPlease enter fruit name: ";
				cin>>shopkeeperName;					  //-----------------
			
				
			
				if(IsItemExists(shopkeeperName[0]) == -1){
					error = 0;
					fruits[i].name = shopkeeperName;
				}else{
					cout<<"\nNo duplicate items!";
				}
			}
			
			cout<<"Please enter '"<<fruits[i].name<<"' price:$";
			cin>>fruits[i].price;						  //-----------------
		
		}
		cout<<"\n******************\n\n";
	}


	






public:
	shop(){
		shopkeeper();

	}
	
	
	void shopkeeper(){
		
		cout<<"*** SHOPEKEEPER PANEL ***\n";
		initializeFruits();
	
	}
	
	void customer(){
		cout<<"*** CUSTOMER PANEL ***\n";
		cout<<"Please enter your budget: $";
		cin>>budget;

		
		char cstmrc = 0; //customer choice
		char cont = 'y'; //continue
		
		while (cont =='y'){
			displayMenu();
			
			printf("Please enter Item Prefix from the Menu to purchase:");
			cin>>cstmrc;
			
			budget = purchaseItem(cstmrc);
			
			cout<<"\nWhould you like to continue shopping? y/n:";
			cin>>cont;
			
		}
	
		cout<<"\n\nThanks for shopping with us!\n";
	}



	
};




int main(){

	shop manaviko;
	manaviko.customer();
	

	
	return 0;
}
