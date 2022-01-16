#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class UberDriver{
	public:
		UberDriver(string a,int b,double c,double d,int e){
			cout<<"Your profile is created"<<"\n";
			set_name(a);
			set_fee_per_km(b);
			set_uber_wallet(c);
			set_uber_points(d);
			set_customer_counter(e);
		}
		void set_name(string a){
			name=a;
		}
		string get_name(){
			return name;
		}
		void set_fee_per_km(int b){
			fee_per_km=b;
		}
		int get_fee_per_km(){
			return fee_per_km;
		}
		void set_uber_wallet(double c){
			uber_wallet=c;
		}
		double get_uber_wallet(){
			return uber_wallet;
		}
		void set_uber_points(double d){
			uber_points=d;
		}
		double get_uber_points(){
			return uber_points;
		}
		void set_customer_counter(int e){
			customer_counter=e;
		}
		int get_customer_counter(){
			return customer_counter;
		}
		void print_uber_profile(){
			cout<<"Name:"<<name<<" - Fee:"<<fee_per_km<<" - Rating:"<<round((uber_points/customer_counter)*100)/100<<endl;
		}
		~UberDriver(){
			if(uber_wallet>=100){
				cout<<"Great job"<<endl;	
			}
			else if(uber_wallet>=50){
				cout<<"Good effort"<<endl;;
			}
			else{
				cout<<"Try harder"<<endl;;
			}
		}
	private:
		string name;
		int fee_per_km;
		double uber_wallet;
		double uber_points;
		int customer_counter;
};
void uber_call(UberDriver a,double km){
    double L;
    int customer_points;
    if((a.get_uber_points()/a.get_customer_counter()>=9)){
    	L=(a.get_fee_per_km()*km)+5;
    	customer_points=10;
	}
	else if((a.get_uber_points()/a.get_customer_counter()>6)){
		L=a.get_fee_per_km()*km;
		customer_points=8;
	}
	else{
	    L=(a.get_fee_per_km()*km)/2;
	    customer_points=4;
	}
	cout<<"Customer number:"<<a.get_customer_counter()+1<<" - Cost of the fare:"<<round(L*100)/100<<" - Customer points:"<<customer_points<<endl;
}
int main ()
{
UberDriver driver("Homer",7, 578.5, 150, 20);
driver.print_uber_profile();
uber_call(driver,6.33456);
}


