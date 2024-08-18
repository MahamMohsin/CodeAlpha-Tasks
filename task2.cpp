// This program implements a Login and Registration System in C++.
// It allows users to register by providing a username and password
// and saves the credentials in a file for future authentication.

#include <iostream>
#include <fstream>
using namespace std;

class LoginRegistration{
    string username;
    string password,confirmedpassword;
    

    public:
    void registerUser(){
        cout<<"Enter your Username: "<<endl;
        cin>>username;

        cout<<"Enter your Password: "<<endl;
        cin>>password;

        cout<<"Confirm your Password: "<<endl;
        cin>>confirmedpassword;

        if (password != confirmedpassword) {
        cout<<"PASSWORDS DO NOT MATCH. PLEASE TRY AGAIN."<<endl;
    }
    else{
        //saving the credentials in a file
        ofstream userfile;
        userfile.open(username+"_credentials.txt",ios::out);
        userfile<<username<<endl;
        userfile<<password<<endl;
        userfile.close();
        cout<<"REGISTRATION SUCCESSFUL!"<<endl;

    }
}

void loginUser(){
        cout<<"Enter your Username: "<<endl;
        cin>>username;

        cout<<"Enter your Password: "<<endl;
        cin>>password;

        string storedusername,storedpassword;

        ifstream userfile;
        userfile.open(username+"_credentials.txt",ios::in);
        if(userfile.is_open()){
            getline(userfile,storedusername);
            getline(userfile,storedpassword);
            userfile.close();

            if(username==storedusername && password==storedpassword){
                cout<<"LOGIN SUCCESSFUL!"<<endl;
                cout<<"Welcome "<<username<<endl<<endl;
}
else{
    cout<<"USER NOT FOUND. PLEASE REGISTER FIRST."<<endl;
}
        }

}
};

int main(){
    LoginRegistration lr;
    int choice;

    do{
    cout<<"WELCOME TO THE LOGIN AND REGISTRATION SYSTEM"<<endl;
    cout<<"1. REGISTER"<<endl;
    cout<<"2. LOGIN"<<endl;
    cout<<"ANY OTHER NUMBER WOULD EXIT THE SYSTEM"<<endl<<endl;
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;

    if (choice==1){
        lr.registerUser();
    }
    else if(choice==2){
        lr.loginUser();
    }
    else{
        cout<<"EXITING THE SYSTEM...";
    }

}while (choice==1 || choice==2);

return 0;
}