#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<ctime>

using namespace std;
//functiom prototype
void customer(string [], string [], double [], int );
void manager(string [], string [], double [], int );
void createMenu(string [], string [], double [], int);
double deliveryTime();
void order(string [], string [], double [], int);
double totalSale();


int main()
{
	cout <<"----------------------------------------------------"<<endl;
	cout <<endl;
	cout <<"            WELCOME TO WESTERN DELIGHT              "<<endl;
	cout <<endl;
	cout <<"----------------------------------------------------"<<endl;
	cout <<"We are opening from monday until saturday"<<endl;
	cout <<endl;
	
	ifstream myfile;
	myfile.open("menu.txt");//open menu file
	
	const int SIZE = 15;//const size array(size menu)
	
	//declare array
	string food[SIZE];
	double price[SIZE];
	string code[SIZE];
	//declare
	int j;
	while(myfile)
	{
		
		for(int j=0;j<SIZE ;j++)
		{
			//getting file from menu data
			getline(myfile,code[j],'\t');
			getline(myfile,food[j],'\t');
			myfile >> price[j];
			
		}
	}
	myfile.ignore();
	myfile.close();
	//display menu
	cout <<"code \t "<<setw(6)<<"menu "<<setw(6)<<"\t\t\t price"<<endl;
	for(int j=0;j<SIZE ;j++)
		{
			cout <<showpoint<<setprecision(2)<<fixed;
			cout << code[j]<<"\t "<<setw(6)<<food[j]<<setw(6)<<"\t\t RM"<<price[j]<<endl;
		}
	cout <<"----------------------------------------------------"<<endl;
	
	cout <<endl;
	char ch;
	//ask user whether manager or customer
	cout <<"Are you- "<<endl;
	cout << "A. Restaurant Manager"<<endl
		 << "B. customer "<<endl
		 << "Enter: ";
	cin >> ch;
	
	cout <<endl;
	
	if(ch=='A' || ch=='a')
		manager(code,food,price,SIZE);//going to manager functiom
	else if(ch=='B' || ch=='b')
		customer(code,food,price,SIZE);//going to customer function
		
	return 0;
}

void manager(string code[], string food[], double price[], int SIZE)
{
	cout << "Hi, manager"<<endl;
	char ch;
	cout <<"\nDo you want to update menu?"<<endl //ask user want to update menu or not
		 <<"Enter Y for yes: ";
	
	cin >> ch;
	cout <<endl;
	if(ch=='y'||ch=='Y') //determine whether user want to update or not
	{
		createMenu(code,food,price,SIZE);//going to createMenu functiom
	}
	cout <<"-------------------------------------"<<endl;
	cout <<endl;
	cout << "This is estimated delivery time"<<endl;//see the estimate delivery time
	cout <<"Enter y to see and any key to continue: ";
	cin >> ch;
	if(ch=='y'||ch=='Y') //determine whether user want to see delivery time or not
	{
		cout<< "This is delivery time: "<<deliveryTime()<<" min"; //going to deliveryTime functiom
	}
	
	cout <<"\n-------------------------------------"<<endl;
	cout <<endl;
	cout << "This customer order payment "<<endl;
	cout <<"Enter y to see and any key to continue: "; //ask user that want to see order payment or not
	cin >> ch;
	if(ch=='y'||ch=='Y') //determine whether user want to see order payment or not
	{
		order(code,food,price,SIZE); //going to order functiom
	}
	
	cout <<endl;
	cout <<"-------------------------------------"<<endl;
	cout << "This is total sale for today"<<endl;
	cout <<"Enter y to see and any key to continue: "; //ask user to see total sale per day
	cin >> ch;
	if(ch=='y'||ch=='Y') //determine whether user want to see total sale per day or not
	{
		cout <<"total sale for today: RM" <<totalSale(); //display total sale per day from totalSale function
	}
	cout <<"\n-------------------------------------"<<endl;
	cout <<"Spread love everywhere you go. Let no one"<<endl
		 <<"ever come to you without leaving happier"<<endl
		 <<"-Mother Teresa"<<endl;
	cout <<"Thanks for using this application";
}

void createMenu(string code[], string food[], double price[], int SIZE)
{
	cout <<endl;
	char ch;
	cout << "\nDo you want to"<<endl; //ask user want to update menu/price or update price
	cout << "a.update menu and price"<<endl
		 << "b.update price"<<endl;
	cout <<"Enter: ";
	cin >>ch;
	
	if(ch=='a'||ch=='A')
	{
		string codeC;
		cout <<"You choose to update menu and price"<<endl; 
		cout <<"Enter menu code: "; //ask user to enter code menu
		cin >> codeC;
		
		for(int i=0;i<SIZE;i++) //check the code menu from array
		{
			if(codeC==code[i])
			{
				cout << "you want to change "<<food[i]<<" RM"<<price[i]<<endl;
				cout << "Enter menu: "; //ask user to enter new menu
				cin >>food[i];
				cout << "Enter price: "; //ask user to enter new price
				cin >> price[i];
			}
		}
		
		cout <<"This is your new menu: "<<endl;
		for(int i=0;i<SIZE;i++)// print new menu
		{
			cout <<showpoint<<setprecision(2)<<fixed;
			cout << code[i]<<setw(6)<<" "<<food[i]<<setw(6)<<" RM"<<price[i]<<endl;
		}
	}
	else if(ch=='b'||ch=='B')
	{
		string codeC;
		cout <<"\nYou choose to update price"<<endl;
		cout <<"Enter menu code: "; //ask user to enter code menu
		cin >> codeC;
		
		for(int i=0;i<SIZE;i++) //check the code menu from array
		{
			if(codeC==code[i])
			{
				cout << "you want to change "<<food[i]<<" RM"<<price[i]<<endl;
				cout << "Enter price: "; //ask user to enter new price
				cin >> price[i];
			}
		}
		
		cout <<"This is your new menu: "<<endl;
		for(int i=0;i<SIZE;i++)// print new menu
		{
			cout <<showpoint<<setprecision(2)<<fixed;
			cout << code[i]<<setw(6)<<" "<<food[i]<<setw(6)<<" RM"<<price[i]<<endl;
		}
	}
	cout << endl;
}

double deliveryTime()//set delivery time
{
	int num;
	srand(time(0));
	num = rand()%40;
	
	
	return num;
}

void order(string code[], string food[], double price[], int SIZE)
{
	//declaration
	string codeOrder;
	double numOrder, total, totalPrice;
	char conti;
	cout <<"----------------------------------------------------"<<endl;
	cout <<"What is your order?"<<endl; 
	do
	{
		cout <<"Enter menu code: ";//ask user menu code
		cin >> codeOrder;
		
		for(int i=0;i<SIZE;i++) //check menu array to detect code same with user enter or not
		{
			if(codeOrder==code[i])//determine whether codeOrder same code[i] or not
			{
				cout << "You choose "<<food[i]<<" RM"<<price[i]<<endl;
				cout << "Number order: "; //ask user number order
				cin >> numOrder;
				total = numOrder * price[i]; //calculate order
				totalPrice= totalPrice + total; //calculate total order
			}
			else
				cout <<"wrong code"<<endl;
				break; //enter wrong code
		}
		cout <<endl;
		cout << "Do you want to add more order? "<<endl; //ask user want to add more or not
		cout << "Enter Y for yes: ";
		cin >>conti;
	}	while(conti =='y'||conti=='Y'); //repeat until user don't wany to add anymore
	
	cout <<showpoint<<setprecision(2)<<fixed;
	cout << "This is your total price: RM"<<totalPrice<<endl; //print total price
	
	ofstream outfile;
	outfile.open("totalprice.txt");
	outfile << totalPrice <<endl; //insert total price into data
	outfile.close();

}

double totalSale()
{
	ifstream inputFile;
	inputFile.open("totalprice.txt");//open total price data file
	
	double num,totalSaleDay; //declaration
	
	while(inputFile) //set data into file
	{
		inputFile >> num;
		totalSaleDay= num +totalSaleDay; //calculate totalSaleDay
	}
	
	inputFile.close();
	return totalSaleDay; //returm totalSaleDay
}


void customer(string code[], string food[], double price[], int SIZE)
{
	char ch;
	string day;
	cout <<"Hi, costumer! "<<endl;
	cout <<"Do you want to order?"<<endl;
	cout <<"Enter Y for yes: "<<endl; //ask user want to order or not
	cin >> ch;
	
	cout <<"When you want to deliver(day)?"<<endl;
	cin >> day;
	while(day=="sunday"||day=="Sunday"||day=="SUNDAY")
	{
		cout <<"Sorry we are close at that time"<<endl;
		cout<<"Try other day?";
		cin >>day;
	}
	
	
	if(ch=='y'||ch=='Y') //determine whether user want to order or not
	{
		order(code,food,price,SIZE); //going to order function
	}
	//display time estimate and the day to sent
	cout << endl;
	cout <<"your destination from this place is: "<< deliveryTime()<<" min"<<endl;
	cout <<"we will be sent your order this "<<day<<endl; 
	
	cout <<"----------------------------------------------------"<<endl;
	cout <<"Thank you for choosing WESTERN DELIGHT"<<endl;
	cout <<"Sayonara..."<<endl;
	cout <<"----------------------------------------------------"<<endl;
}
