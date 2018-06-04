#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;


struct Node //Creating Node
{
	int data;
	string action;
	struct Node *next;
	string username;
};


int main() //main function
{
	Node* accounts[1000]; 
	Node* allaccounts[100];
	int mark;
	
	int input;
	string current;
	hash <string> myhash;
	
	cout << "Create an Account: " << endl;
	cin >> current;
	input = myhash(current) % 100;
	
	//cout << input << endl;
	
	
	Node* head = NULL; 
	Node* current_node = NULL;
	Node* temp = NULL;
	
	
	head = new Node();
	
	
	head->data = 100000;
	head->username = current;
	head->next = NULL;
	accounts[input] = head;
	allaccounts[0] = head;
	mark = 1;

	sleep(1);
	system("CLS");
	bool flag = true;
	
	while(flag){
		cout<<"Actions:\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show All Transactions\n5. Show All Accounts\n6. Create New\n7. Login\n8. Exit\nInput:"<<endl;
		cin>>input;
			
		if (input == 1)/*Depositing a specific ammount of money to an account*/
		{
			temp = new Node();
			cout<<"How much?" << endl;
			
			cin>>input;
			temp->data = input;
			temp->action = "Deposit";
			temp->next = NULL;
			
			current_node = head;
			while(current_node->next != NULL)
			{
				current_node = current_node->next;
			}
			current_node->next = temp;
			head->data += input;
			
			cout << "Your balance = "<< head->data << endl;
			sleep(2);
			system("CLS");
		}
		
		else if (input == 2)/*Withdrawing a specific ammount of money to an account*/
		{
			temp = new Node();
			cout<< "How much?" << endl;
			
			cin>>input;
			temp->data = input;
			temp->action = "Withdraw";
			temp->next = NULL;
			
			current_node = head;
			while(current_node->next != NULL)
			{
				current_node = current_node->next;
			}
			current_node->next = temp;
			head->data -= input;
			cout << "Your balance = "<< head->data << endl;
			sleep(2);
			system("CLS");
		}
		
		else if (input == 3)/*Showing the balance of the selected account*/
		{
			cout << "Your balance = "<< head->data << endl;
			sleep(2);
			system("CLS");
		}
		
		else if (input == 4)/*Showing all transactions*/
		{
			cout << "Showing All Transaction:\n";
			Node* current = head;
			while (current!=NULL)
			{
				if(current->action == "Deposit")
					cout<<"Deposited: "<<current->data<<endl;
				else if(current->action == "Withdraw")
					cout<<"Withdrawn: "<<current->data<<endl;
				current = current->next;
			}
			sleep(2);
			system("CLS");
			delete(current);
			}
		
		
		else if (input == 5){/*Showcase all accounts made*/
			for (int i = 0; i<mark;i++)
			{
				cout<<"Accounts:["<<allaccounts[i]->username<<"]\n";
			}
			sleep(2);
			system("CLS");
			
		}
		
		
		
		else if(input == 6)/*Create an account and assign it to the hashtable*/
		{
			cout << "Create an Account: " << endl;
			cin >> current;
			input = myhash(current) % 100;
			//cout << input << endl;
		
		
			head = new Node(); 
			head->data = 100000;
			head->next = NULL;
			head->username = current;
			allaccounts[mark] = head;
			mark+=1;
		
			if(accounts[input] == NULL)
			{
				accounts[input] = head;	
			}
			else
			{
				while(accounts[input] != NULL)
				{
					input += 1;
				}
				accounts[input] = head;
			}
			sleep(2);
			system("CLS");
		}
		
		else if(input ==7)/*Selecting an already made account in the hashtable*/
		{
			cout << "Username:" << endl;
			cin >> current;
			input = myhash(current) % 100;
			//cout << input <<endl;
			
			if(current == accounts[input]->username)
			{
				head = accounts[input];
			}
			else
			{
				int counter = 0;
				while(current != accounts[input]->username && counter < 11)
				{
					if(input >= 1000)
					{
						input = 0;
					}
					input += 1;
					counter +=1;
				
				if(current == accounts[input]->username)
				{
					cout << "Logged in as = ";
					head = accounts[input];
				}
				else
				{
					cout << "Account not found" << endl;
					continue;
				}
				
				}
			}
			head = accounts[input];
			sleep(2);
			system("CLS");
		}

		
		else if (input == 8)/*Exiting the program*/
		{
			flag = false;
		}
		
	}
	
	return 0;
}
