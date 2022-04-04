#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;
const char* fileName="employee.txt";

class User{
private:
    string username,password;
public:
    bool Authenticate(){
        getUserDetails();
        if(username.compare("admin")==0 && password.compare("pass")==0)
        {
           return true;
        }
        else
        {
            cout<<"Invalid Login";
            system("CLS");
            this->Authenticate();
        }
    }

    void getUserDetails(){
        cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;
    }
};

class Employee{
private:
    string empName,address,email,phoneNo;
    int empId;
    float salary;
public:
    void getEmployeeDetails(){
        cout<<"Enter Employee Id";
        cin>>empId;
         fflush(stdin);
        cout<<"Enter Full Name:";
        getline(cin,empName);
         fflush(stdin);
        cout<<"Enter Address:";
        getline(cin,address);
         fflush(stdin);
        cout<<"Enter Email";
        cin>>email;
        fflush(stdin);
        cout<<"Enter Phone Number";
        cin>>phoneNo;
    }

    void displayHeader(){
        cout<<"Employee Id \t Employee Name \t Address \t Email \t Phone Number"<<endl;
    }

    void displayEmployeeDetails(){
        cout<<empId<<empName<<address<<email<<phoneNo<<endl;
    }

    int getId(){
        return empId;
    }


};


int main(){
    User user;
    int choice;
    fstream file;
    Employee emp,e;
    file.open(fileName,ios::app|ios::binary|ios::out|ios::in);
    if(user.Authenticate()){
            while(1){
                system("CLS");
                cout<<"Welcome to Project II"<<endl;
                cout<<"1. Add Record"<<endl;
                cout<<"2. View Record"<<endl;
                cout<<"3. Update Record"<<endl;
                cout<<"4. Delete Record"<<endl;
                cout<<"5. Search Record"<<endl;
                cout<<"6. Exit"<<endl;
                cout<<"Enter your Choice[1-5]"<<endl;
                cin>>choice;
                switch(choice){
                    case 1:{
                        int isfound=0;
                        emp.getEmployeeDetails();
                        file.seekg(0,ios::beg);
                        while(file.read((char*)&e,sizeof(e))){
                            if(emp.getId()==e.getId()){
                                    isfound=1;
                                    break;
                            }
                        }
                        if(isfound==1){
                            cout<<"This id already exist.";
                            getch();
                            break;
                        }
                        file.clear();
                        file.seekp(0,ios::end);
                        file.write((char *)&emp,sizeof(emp));
                        cout<<"Data Saved ";
                        getch();
                        file.close();
                        break;

                    }
                    case 2:{
                        break;
                    }
                    case 3:{
                        break;
                    }
                    case 4:{
                        break;
                    }
                    case 5:{
                        break;
                    }
                    case 6:{
                        exit(1);
                    }
                    default:
                        cout<<"Invalid Choice";
                        getch();
                }
            }

    }
}
