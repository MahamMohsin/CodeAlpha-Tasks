//A banking system designned using object-oriented approach
//to manage customer acccounts,transactions,balances,withdrawals,deposits and other banking srvices.

#include <iostream>
#include <string>
using namespace std;

class transaction{
    string transactiontype;//-deposit/withdrawal/transfer
    float amt;
    string date;

    public:
    void setType(string t){
        transactiontype=t;
}

void setAmt(float a){
    amt=a;
}

void setDate(string d){
    date=d;
}

string getType(){
    return transactiontype;
}

float getAmt(){
    return amt;
}

string getDate(){
    return date;
}
};

class account{
    public:
    string accountName,accountNum;
    float balance;
    transaction transactions[100];//assuming a maximum of 100 transactions can be made
    int count=0;//keeps track of transactions

    account(){}//default constructor
    account(string n,string num,float b):accountName(n),accountNum(num),balance(b),count(0){}

    void deposit(float amount){
        balance=balance+amount;//updates balance
        transactions[count].setType("deposit");
        transactions[count].setAmt(amount);
        transactions[count].setDate("17-7-2024");
count++;
        cout<<"Dear "<<accountName<<" your recent deposit of PKR "<<amount<<"has been successfully credited into account ["<<accountNum<<"]"<<endl;
        cout<<"Current balance: PKR "<<balance<<endl;
}
      void withdraw(float amount){
        if(balance>=amount){
            balance=balance-amount;
            transactions[count].setType("withdrawal");
            transactions[count].setAmt(amount);
            transactions[count].setDate("17-7-2024");
            count++;
            
            cout<<"Dear "<<accountName<<" your recent withdrawal of PKR "<<amount<<"has been successfully debited from acount["<<accountNum<<"]"<<endl;
            cout<<"Current balance: PKR "<<balance<<endl;
}
else{
    cout<<"Insufficient balance. Withdrawal failed."<<endl;
}
}

void printdetails(){
    cout<<"Account Name: "<<accountName<<endl;
    cout<<"Account Number: "<<accountNum<<endl;
    cout<<"Balance PKR: "<<balance<<endl<<endl;

    cout<<"Transactions History:"<<endl;
    for(int i=0;i<count;i++){
        cout<<"Transaction Type: "<<transactions[i].getType()<<endl;
        cout<<"Amount: "<<transactions[i].getAmt()<<endl;
        cout<<"Date: "<<transactions[i].getDate()<<endl;
}
}
};

class customer{
    public:
    string name;
    int customerID;//unique identifier for each customer
    account accounts[10];//assuming a maximum of 10 accounts can be created
    int count;//keeps track of accounts
  
   customer(){}
   customer(string name,int id):name(name),customerID(id),count(0){}

   //function to add an account for the customer
   void addAccount(account acc){
    accounts[count++]=acc;
    cout<<"Account["<<acc.accountNum<<"]has been added successfully for customer "<<name<<endl;
}

//function to remove an account for the customer
void removeAccount(string accountNum){
    for(int i=0;i<count;i++){
        if(accounts[i].accountNum==accountNum){
            for(int j=i;j<count-1;j++){
                accounts[j]=accounts[j+1];
                count--;
            }
        }
    }
    cout<<"Account["<<accountNum<<"] has been removed successfully for customer "<<name<<endl;
}

//function to print customer details
void printDetails(){
    cout<<"Customer Name: "<<name<<endl;
    cout<<"Customer ID: "<<customerID<<endl;
    cout<<"Accounts Owned: "<<endl;
    for(int i=0;i<count;i++){
        accounts[i].printdetails();
    }
}
};

// class to manage customers and provide banking services
class bank{
customer customers[100];//assuming a max of 100 customers
int count;//keeps track of customers

public:
bank():count(0){}

//function to add a new customer
void addcustomer(customer c){
    customers[count++]=c;
    cout<<"Customer "<<c.name<<" has been added successfully to the bank."<<endl;
    }

//function to remove a customer
void removecustomer(int id){
    for(int i=0;i<count;i++){
        if(customers[i].customerID==id){
            for(int j=i;j<count-1;j++){
                customers[j]=customers[j+1];
                count--;
}
        }
    }
    cout<<"Customer with ID "<<id<<" has been removed"<<endl;
}    

//function to perform deposit
void deposit(int id, string accNum, float amount) {
    bool customerFound = false;
    for (int i = 0; i < count; i++) {
        if (customers[i].customerID == id) {
            customerFound = true;
            bool accountFound = false;
            for (int j = 0; j < customers[i].count; j++) {
                if (customers[i].accounts[j].accountName == accNum) {
                    customers[i].accounts[j].deposit(amount);
                    cout<<"Deposit of PKR " << amount << " has been successfully credited into account [" << accNum << "]" << endl;
                    accountFound = true;
                    break;
                }
            }
            if (!accountFound) {
                cout<<"Account with number [" << accNum << "] not found."<<endl;
            }
            break;
        }
    }
    if (!customerFound) {
        cout<<"Customer with ID [" << id << "] not found."<<endl;
    }
}

//function to perform withdrawal
void withdraw(int id,string accNum,float amount){
    bool customerFound=false;
    for(int i=0;i<count;i++){
        if(customers[i].customerID==id){
            customerFound=true;
            bool accoundFound=false;

            for(int j=0;j<customers[i].count;j++){
                if(customers[i].accounts[j].accountNum==accNum){
                    customers[i].accounts[j].withdraw(amount);
                    cout<<"Withdrawal of PKR "<<amount<<" has been successfully debited from account ["<<accNum<<"]"<<endl;
                    accoundFound=true;
                    break;
    
                }
            }
            if(!accoundFound){
                cout<<"Account with number ["<<accNum<<"]"<<endl;
            }
            break;
        }
         }
         if(!customerFound){
            cout<<"Customer with ID ["<<id<<"]"<<endl;
         }
}

//function to transfer money between two accounts
void transfer(int id,string accNum1,string accNum2,float amount){
bool customerFound=false;
for(int i=0;i<count;i++){
    if(customers[i].customerID==id){
        customerFound=true;
        bool accountfound1=false;
        bool accfound2=false;
        for(int j=0;j<customers[i].count;j++){
            if(customers[i].accounts[j].accountNum==accNum1){
                customers[i].accounts[j].withdraw(amount);
                accountfound1=true;

                for(int k=0;k<customers[i].count;k++){
                    if(customers[i].accounts[k].accountNum==accNum2){
                        customers[i].accounts[k].deposit(amount);
                        accfound2=true;
                        break;

                    }

                }
                if(!accfound2){
                    cout<<"Account with number ["<<accNum2<<"]"<<endl;
                }

            }
            if(!accountfound1){
                cout<<"Account with number ["<<accNum1<<"]"<<endl;
            }
            break;
        }
    }

}
}

//function to print all customers and their details
void printAll(){
    for(int i=0;i<count;i++){
        customers[i].printDetails();
}
}
};

int main(){
    bank b;

    customer customer1("Alice", 1001);
    customer customer2("Bob", 1002);

    //adding accounts to these customers
    account account1("Alice's Savings", "ACC001", 1000.0f);
    account account2("Alice's Checking", "ACC002", 500.0f);
    account account3("Bob's Savings", "ACC003", 2000.0f);

    customer1.addAccount(account1);
    customer1.addAccount(account2);
    customer2.addAccount(account3);

    //adding customers to the bank
    b.addcustomer(customer1);
    b.addcustomer(customer2);

    //performing some transactions
    b.deposit(1001, "ACC001", 500.0f);  //deposit to Alice's Savings
    b.withdraw(1002, "ACC003", 300.0f);  //withdraw from Bob's Savings
    b.transfer(1001, "ACC001", "ACC002", 200.0f); //transfer from Alice's Savings to Checking

    //print details of all customers and their accounts
    b.printAll();
cout << "Press any key to continue...";
cin.get();
    return 0;
}
