#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Person {
public:
    string name;
    string cnic;
     string naam;
    int Number;
    void get_customer_data();
    void Display();
    Person():name("0"),cnic("0"),naam(name),Number(0){
	};
    Person(string n,string c,string nn,int num){
    	name=n;
    	naam=nn;
    	naam +=name;
    	Number +=num;
    	cnic=c;
	}
};

class Guest : public Person {
private:
    string Address;
public:
	Guest():Address("0"),Person("0","0","0",0){	};
     void get_customer_data() {
     	fstream file;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter CNIC: "; cin >> cnic;
        cout << "Enter Phone Number: "; cin >> Number;
        cout << "Enter Address: "; cin >> Address;
       	file.open("Guest_InitialData.txt",	ios::out | ios::app);
		file << " " << name << "\n "<< cnic << "\n " << Number << " \n" << Address << " /n";
		file.close();
    }
   	void Display(){
			system("cls");
			fstream file;
			cout << "\n\n\t\t\t\t\tAll BOOKS";
			// Open the file in input mode
			file.open("BookData.txt", ios::in);
			if (!file)
				cout << "\n\nFile Opening Error!";
			else {
				cout << "\n\n\nTitle \t\t\tAuthor \t\t\tPublisher \t\tPrice \t\tISBN \t\tNo. of Books\n\n";
				file >> name >> cnic >> Number >> Address;
				// Till end of file is reached
				while (!file.eof()) {
					cout << " " << name
						<< "\n" <<  cnic
						<< "\n" << Number
						<< "\n" <<Address
						<< "\n\n";
					file >> name >> cnic >> Number >> Address;
				}
				system("pause");
				// Close the file
				file.close();
			}	
		}
};

class Employee :public Person {
	private:
		int ID_Card_Number;
		public:
		string Resignation;
		
		Employee():ID_Card_Number(0),Resignation("0"),Person("0","0","0",0){};
	
	   void get_customer_data() {
        cout << "Enter CNIC: "; cin >> cnic;
        cout <<"Enter ID Card Number :"; cin>> ID_Card_Number;
        cout <<"Enter Your Resignation :"; cin>> Resignation;
        
        }
        void Display() {
        cout << "++++++++++++Employee Detail++++++++++++++++" << endl;
        cout << " ID Card: " << ID_Card_Number << endl;
        cout << " Resignation :"<<Resignation<<endl;
    }
};

class Booking:public Person{
	private:
		string RoomType;
		string Room_Size;
	public:
		Booking(string RT,string RS):Person("0","0","0",0){
		   RoomType = RT;
		   Room_Size = RS;
		}
		void setRoomType(string r){
			RoomType = r;
		}
		
		
};
class Room :public Booking{
	private:
		int price;
		int total;
		string Date;
	public:
		Room(): price(0), total(0), Date("0"), Booking("none","none")
		{	}
		Room(int p,int t,string d):Booking("none","none"){
			price = p;
			total = t;
			Date=d;
		}
//		virtual void Normal_Room();
//		virtual void Luxury_Room();
//		virtual void Royal_Room();
		
		
};
class Payment : public Room, public Person,public Booking{
	public:
		int normal_Room_price_single;
		int normal_Room_price_double;
		int luxury_Room_price_single;
		int luxury_Room_price_double;
		int royal_Room_price_single;
		int royal_Room_price_double;
		
		Payment(int a,int b,int c,int d,int e,int f,int g):Booking("0","0"){	
			 int normal_Room_price_single= a;
			 int normal_Room_price_double= b;
			 int luxury_Room_price_single= c;
			 int luxury_Room_price_double= d;
			 int royal_Room_price_single= e;
			 int royal_Room_price_double= f;
			}
	void Normal_Room(){
			string rt,rs,d;
			int p,t,amount;
				int days;
			cout<<"++++++++++++++NORMAL ROOM BOOKING+++++++++++++++++++++\n \n";
			cout<<"Room Type | Classic | Modern :";cin>>rt;
			cout<<"Room Size |Single |Double :";cin>>rs;
			cout<<"Booking Date : ";cin>>d;
			cout<<"How many Days You Stay : ";cin>>days;
			if(rs == "single"  || rs == "Single"&& days>0){
				amount = normal_Room_price_single*days;
				
			}
			else if(rs =="double" || rs == "Double"&& days>0){
				amount = normal_Room_price_single*days;
			
			}
			else{
				cout<<"Invalid Option Please Enter a Valid Value Single or Double ";
			}
			cout<<"Enter Your Payment Amount :";cin>>p;
			t = p - amount;
	   cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++NORMAL ROOM BOOKING++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			system("cls");
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++NORMAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
        	Person person;
        	cout<<"                                               Room --- "<<rt<<" ---"<<endl;
        	cout<<"                                               Size --- "<<rs<<" ---"<<endl;
        	cout<<"                                               Name --- "<<person.name<<endl;
        	cout<<"                                               Phone --- "<<person.Number<<" ---"<<endl;
        	cout<<"                                               Price of Room --- "<< amount;cout<<" ---"<<endl;
        	cout<<"                                               Date --- "<<d<<" ---"<<endl;	
        	cout<<"                                               Your Current Balanced Amount "<<p<<" - "<< amount;cout<<endl;
        	cout<<t;
	    cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++NORMAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";

system("pause");		
	};
	void Luxury_Room(){
			string rt,rs,d;
			int p,t,amount,days;
			cout<<"++++++++++++++LUXURY ROOM BOOKING+++++++++++++++++++++\n \n";
			cout<<"Room Type | Classic | Modern :";cin>>rt;
			cout<<"Room Size |Single |Double :";cin>>rs;
			cout<<"Booking Date : ";cin>>d;
			cout<<"How many Days You Stay : ";cin>>days;

			if(rs == "single"  || rs == "Single"|| days>0){
				amount = luxury_Room_price_single*days;
				
			}
			else if(rs =="double" || rs == "Double"|| days>0){
				amount = luxury_Room_price_single*days;
			
			}
			else{
				cout<<"Invalid Option Please Enter a Valid Value Single or Double ";
			}
			cout<<"Enter Your Payment Amount :";cin>>p;
			t = p - amount;
		  cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++LUXURY ROOM BOOKING++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			system("cls");
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++LUXURY BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
        	Person person;
        	cout<<"                                               Room --- "<<rt<<" ---"<<endl;
        	cout<<"                                               Size --- "<<rs<<" ---"<<endl;
        	cout<<"                                               Name --- "<<person.name<<endl;
        	cout<<"                                               Phone --- "<<person.Number<<" ---"<<endl;
        	cout<<"                                               Price of Room --- "<<amount;cout<<" ---"<<endl;
        	cout<<"                                               Date --- "<<d<<" ---"<<endl;	
        	cout<<"                                               Your Current Balanced Amount "<<p<<" - "<<amount;cout<<endl;
        	cout<<t;
	    cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++LUXURY BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
system("pause");		}
	
	void Royal_Room(){
			string rt,rs,d;
			int p,t,amount,days;
			cout<<"++++++++++++++ROYAL ROOM BOOKING+++++++++++++++++++++\n \n";
			cout<<"Room Type | Classic | Modern :";cin>>rt;
			cout<<"Room Size |Single |Double :";cin>>rs;
			cout<<"How many Days You Stay : ";cin>>days;
			cout<<"Booking Date : ";cin>>d;

			if(rs == "single"  || rs == "Single" || days>0){
				amount = royal_Room_price_single*days;
				
			}
			else if(rs =="double" || rs == "Double"|| days>0){
				amount = royal_Room_price_single*days;
			} else{
				cout<<"Invalid Option Please Enter a Valid Value Single or Double ";
			}
			cout<<"Enter Your Payment Amount :";cin>>p;
			t = p - amount;
	
        	cout<<"\n \n+++++++++++++++++++++++++++++++++++++++++++++++++++ROYAL ROOM BOOKING +++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			system("cls");
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++ROYAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
        	Person person;
        	cout<<"                                               Room --- "<<rt<<" ---"<<endl;
        	cout<<"                                               Size --- "<<rs<<" ---"<<endl;
        	cout<<"                                               Name --- "<<person.name<<endl;
        	cout<<"                                               Phone --- "<<person.Number<<" ---"<<endl;
        	cout<<"                                               Price of Room --- "<<amount;cout<<" ---"<<endl;
        	cout<<"                                               Date --- "<<d<<" ---"<<endl;	
        	cout<<"                                               Your Current Balanced Amount "<<p<<" - "<< amount;cout<<endl;
        	cout<<t;
	       cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++ROYAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
system("pause");
	}   

};

class Emp_Payment_Offers:public Payment,public Employee{
	public:
		int year;float Discount,Final_Amount;
		string Offer;
		Emp_Payment_Offers():Payment(0,0,0,0,0,0,0),Employee(){
		};
		void Normal_Room(){
			int nrs=5000;int nrd=8000;
			string rt,rs,d, name;
			int p,t,amount,Number,days;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++NORMAL ROOM BOOKING+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			cout<<"                                         Room Type | Classic | Modern :";cin>>rt;
			cout<<"                                         Room Size |Single |Double :";cin>>rs;
			cout<<"                                         Name : ";cin>>name;
			cout<<"                                         Phone : ";cin>>Number;
			cout<<"                                         Booking Date : ";cin>>d;
			cout<<"                                         How many Days You Stay : ";cin>>days;

			if(rs == "single"  || rs == "Single"&& days>0){
				amount = nrs*days ;
				
			}
			else if(rs =="double" || rs == "Double"&& days>0){
				amount = nrd*days;
			
			}
			else{
				cout<<"Invalid Option Please Enter a Valid Value Single or Double ";
			}
			cout<<"Enter Your Payment Amount :";cin>>p;
			t = p - amount;
			try{
				cout<< "How Many Year Since Work here as  :"<<Resignation<<" ? : ";
			    cin>>year;
			if(year >=1 && year <2){
				Offer="YOU GOT THE 15 % DISCOUNT !! ";
			    Discount = amount/0.15;
			}
			else if(year >=2 && year <3){
			    Offer="YOU GOT THE 30 % DISCOUNT !! ";
				Discount = amount/0.3;
			}
			else if(year >=3 && year <5){
				Offer="YOU GOT THE 50 % DISCOUNT !! ";
				Discount = amount/0.5;
			}
			else{
				throw (year);
		    	}
	    	}
	    	catch(int YearNum){
	    		cout<<"Offer Denied -Atleast 1 year experience Required To Avail this Discount \n";
	    		cout<<"Year is :"<<YearNum<<endl;
			}
			
	        
            cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++NORMAL ROOM BOOKING++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			system("cls");
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++NORMAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
        	Person person;
        	cout<<"                                               Room --- "<<rt<<" ---"<<endl;
        	cout<<"                                               Size --- "<<rs<<" ---"<<endl;
        	cout<<"                                               Name --- "<<person.name<<endl;
        	cout<<"                                               Phone --- "<<person.Number<<" ---"<<endl;
        	cout<<"                                               Price of Room --- "<<(year >= 1) ? Discount : amount;cout<<" ---"<<endl;
        	cout<<"                                               Date --- "<<d<<" ---"<<endl;	
        	cout<<"                                               Your Current Balanced Amount "<<p<<" - "<<(year >= 1) ? Discount : amount;cout<<endl;
        	cout<<t;
	    cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++NORMAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
system("pause");
}
	
	void Luxury_Room(){
	    	int lrs=15000;int lrd=22000;
			string rt,rs,d,Name;
			int p,t,amount,phone,days;
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++LUXURY ROOM BOOKING++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			cout<<"                                           Room Type | Classic | Modern :";cin>>rt;
			cout<<"                                           Room Size |Single |Double :";cin>>rs;
			cout<<"                                           Name : ";cin>>Name;
			cout<<"                                           Phone : ";cin>>phone;
			cout<<"                                           Booking Date : ";cin>>d;
			cout<<"                                           How many Days You Stay : ";cin>>days;
			if(rs == "single"  || rs == "Single"&& days>0){
				amount = lrs*days;
				
			}
			else if(rs =="double" || rs == "Double"&& days>0){
				amount = lrd*days;
			
			}
			else{
				cout<<"Invalid Option Please Enter a Valid Value Single or Double ";
			}
			cout<<"Enter Your Payment Amount :";cin>>p;
			t = p - amount;
        	try{
				cout<< "How Many Year Since Work here as  :"<<Resignation<<" ? : ";
			    cin>>year;
			if(year >=1 && year <2){
				Offer="YOU GOT THE 15 % DISCOUNT !! ";
			    Discount = amount/0.15;
			}
			else if(year >=2 && year <3){
			    Offer="YOU GOT THE 30 % DISCOUNT !! ";
				Discount = amount/0.3;
			}
			else if(year >=3 && year <5){
				Offer="YOU GOT THE 50 % DISCOUNT !! ";
				Discount = amount/0.5;
			}
			else{
				throw (year);
		    	}
	    	}
	    	catch(int YearNum){
	    		cout<<"Offer Denied -Atleast 1 year experience Required To Avail this Discount \n";
	    		cout<<"Year is :"<<YearNum<<endl;
			}
            cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++LUXURY ROOM BOOKING++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			system("cls");
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++LUXURY BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
        	Person person;
        	cout<<"                                               Room --- "<<rt<<" ---"<<endl;
        	cout<<"                                               Size --- "<<rs<<" ---"<<endl;
        	cout<<"                                               Name --- "<<Name<<endl;
        	cout<<"                                               Phone --- "<<phone<<" ---"<<endl;
        	cout<<"                                               Price of Room --- "<<(year >= 1) ? Discount : amount;cout<<" ---"<<endl;
        	cout<<"                                               Date --- "<<d<<" ---"<<endl;	
        	cout<<"                                               Your Current Balanced Amount "<<p<<" - "<<(year >= 1) ? Discount : amount;cout<<endl;
        	cout<<t;
	    cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++LUXURY BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
system("pause");
	}	
	
	
	void Royal_Room(){
			int rrs,rrd;
			rrs=25000;rrd=33000;
			string rt,rs,d,Name;
			int p,t,amount,phone,days;
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ROYAL ROOM BOOKING+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			cout<<"Room Type | Classic | Modern :";cin>>rt;
			cout<<"How many Days You Stay : ";cin>>days;
			cout<<"Name : ";cin>>Name;
			cout<<"Phone : ";cin>>phone;
			cout<<"Booking Date : ";cin>>d;
			cout<<"Room Size |Single |Double :";cin>>rs;
			if(rs == "single"  || rs == "Single"&& days>0){
				amount = rrs*days;
				
			}
			else if(rs =="double" || rs == "Double" && days>0){
				amount = rrd*days;
			} 
			else{
				cout<<"Invalid Option Please Enter a Valid Value Single or Double ";
			}
			cout<<"Enter Your Payment Amount :";cin>>p;
	        try{
				cout<< "How Many Year Since Work here as  :"<<Resignation<<" ? : ";
			    cin>>year;
			if(year >=1 && year <2){
				Offer="YOU GOT THE 15 % DISCOUNT !! ";
			    Discount = amount/0.15;
			    cout<<Offer<<endl;
			}
			else if(year >=2 && year <3){
			    Offer="YOU GOT THE 30 % DISCOUNT !! ";
				Discount = amount/0.3;
				 cout<<Offer<<endl;
			}
			else if(year >=3 && year <5){
				Offer="YOU GOT THE 50 % DISCOUNT !! ";
				Discount = amount/0.5;
				 cout<<Offer<<endl;
			}
			else{
				throw (year);
		    	}
	    	}
	    	catch(int YearNum){
	    		cout<<"Offer Denied -Atleast 1 year experience Required To Avail this Discount \n";
	    		cout<<"Year is :"<<YearNum<<endl;
			}
			cout<<"\n \n+++++++++++++++++++++++++++++++++++++++++++++++++++ROYAL ROOM BOOKING +++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
			system("cls");
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++ROYAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
        	Person person;
        	cout<<"                                               Room --- "<<rt<<" ---"<<endl;
        	cout<<"                                               Size --- "<<rs<<" ---"<<endl;
        	cout<<"                                               Name --- "<<Name<<endl;
        	cout<<"                                               Phone --- "<<phone<<" ---"<<endl;
        	cout<<"                                               Price of Room --- "<<(year >= 1) ? Discount : amount;cout<<" ---"<<endl;
        	cout<<"                                               Date --- "<<d<<" ---"<<endl;	
        	cout<<"                                               Your Current Balanced Amount "<<p<<" - "<<(year >= 1) ? Discount : amount;cout<<endl;
        	cout<<t;
	       cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++ROYAL BOOKING RECEIPT+++++++++++++++++++++++++++++++++++++++++++++++++++\n \n";
system("pause");
}
		
		
};
template<class T>
class Welcome {
public:
	
	void welcomeMessage(){
		system("Color 0");
		cout<<"\n\n";
		cout<<"\n\t\t  ##########**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**###############\n";
		cout<<"\t\t           ****=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*****";
		cout<<"\n\t\t              !!!!!!!!!!!!!!!!! HOTEL !!!!!!!!!!!!!!!!!!!";
		cout<<"\n\t\t                      +++++BOOK YOUR HOTEL ++++++++";
		cout<<"\n\t\t           #=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=#";
		cout<<"\n\t\t           #=-=-=-=-=-=-=-=MADE BY RAO ABDUL HAI=-=-=-=-=#";
		cout<<"\n\t\t ############**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**###############\n\n\n";
		system("pause");
		}
};

		
	
		

 void Option(){
 	Employee Emp;
	Guest per;
		system("cls");
	cout<<"#####################################Welcome to Our Hotel#############################################"<<endl<<endl;
	int options;
	cout<<"                                     Please Show Your Identity";
	cout<<"\n";
	cout<<"                                     Press '1' As a Guest \n";
	cout<<"                                     Press '2' As an Employee \n";
	cout<<"                                     Select: ";cin>>options;
	
	cout<<"########################################Rao Abdul Hai#########################################"<<endl<<endl;
		int v;
	Payment person(5000,8000,15000,22000,25000,33000,v);
	Emp_Payment_Offers emp_per;
	switch(options){
		case 1:
			system("cls");
			cout<<"#######################################WELCOME TO GUEST ACCOUNT#############################################\n";
  		    per.get_customer_data();
  		    system("cls");
  		    cout<<"############################################WELCOME TO GUEST ACCOUNT##########################################\n";
            per.Display();
            cout<<"###############################################WELCOME TO GUEST ACCOUNT#######################################\n";
            break;
        case 2:	
            system("cls");
			cout<<"############################################WELCOME TO EMPLOYEE ACCOUNT########################################\n";
        	Emp.get_customer_data();
        	system("cls");
        	cout<<"###################################################DETAIL OF EMPLOYEE ACCOUNT##################################\n";
        	Emp.Display();
        	cout<<"#####################################################DETAIL OF EMPLOYEE ACCOUNT################################\n";
        	break;
        default :
        	system("cls");
        	cout<<"Please Enter A Valid Number";
	}
	    system("pause");
	system("cls");
	string typeRoom;
	cout<<"\n\n                                       WHAT KIND OF ROOM YOU WANT -Normal or Luxury or Royal : ";cin>>typeRoom;
	switch(options){
		case 1:
			system("cls");
			if(typeRoom=="Normal"){
				person.Normal_Room();
			}
			else if(typeRoom == "Luxury"){
				person.Luxury_Room();
			}
			else if(typeRoom=="Royal"){
				person.Royal_Room();
			}
			break;
			system("pause");
		case 2:
			system("cls");
			if(typeRoom=="Normal"){
				emp_per.Normal_Room();
			}
			else if(typeRoom == "Luxury"){
				emp_per.Luxury_Room();
			}
			else if(typeRoom=="Royal"){
				emp_per.Royal_Room();
			}
			break;
		default:
			cout<<"INVALID ERROOR";
		}
		system("pause");	
	
    
}
string user,pass;
 void login_panel();
 	void login_panel(){
			system("cls");
			
			string user_name,user_pass;
			cout << "\n\n\t\t\t\t $$$$$$$$$$-  ADMIN LOGIN   -$$$$$$$$$$$$$$$$$";
			cout<<"\n\n                Enter ID : ";	cin>>user;
			cout<<"                    Enter password : ";	cin>>pass;
			if(user=="RaoAbdulHai29" && pass=="RaoAbdulHai29"){	
				Option();
			}
			else{
				cout<<"Incorrect ID or Password \n";
			}
			system("pause");
		};
int main() {
	Welcome<string> wel;
	wel.welcomeMessage();
	while(pass !="RaoAbdulHai29"){
	    login_panel();
		}
	

    return 0;
}

