#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
using namespace std;
const char* fileName="test.txt";

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
    char empName[50],address[50],email[50],phoneNo[20];
    int empId;
    float salary;
public:
    void getEmployeeDetails(){
        cout<<"Enter Employee Id";
        cin>>empId;
         fflush(stdin);
        cout<<"Enter Full Name:";
        cin.getline(empName,sizeof(empName));
         fflush(stdin);
        cout<<"Enter Address:";
        cin.getline(address,sizeof(address));
         fflush(stdin);
        cout<<"Enter Email";
        cin>>email;
        fflush(stdin);
        cout<<"Enter Phone Number";
        cin>>phoneNo;
    }

    void displayHeader(){
        cout<<"Employee Id"<<setw(20)<<" Employee Name"<<setw(20)<<"Address"<<setw(20)<<"Email"<<setw(20)<<"Phone Number"<<endl;
    }

    void displayEmployeeDetails(){
        cout<<empId<<setw(20)<<empName<<setw(30)<<address<<setw(20)<<email<<setw(20)<<phoneNo<<endl;
    }

    int getId(){
        return empId;
    }
};

int main(){
    User user;
    int choice;
    fstream file;
    Employee e,emp;
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
                        file.open(fileName,ios::app|ios::binary);
                        int isfound=0;
                        emp.getEmployeeDetails();
                        file.clear();
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
                        file.write((char*)&emp,sizeof(emp));
                        cout<<"Data Saved ";
                        getch();
                        file.close();
                        break;
                    }
                    case 2:{
                        file.open(fileName,ios::in);
                        file.clear();
                        file.seekg(0,ios::beg);
                        e.displayHeader();
                        while(file.read((char*)&e,sizeof(e))){
                            e.displayEmployeeDetails();
                        }
                        file.close();
                        getch();
                        break;
                    }
                    case 3:{
                        int recordNo=0,Id,isFound=0;
                        cout<<endl<<"Enter the ID to update";
                        cin>>Id;
                        file.open(fileName,ios::ate|ios::in|ios::out|ios::binary);
                        file.clear();
                        file.seekg(0,ios::beg);
                        while(file.read((char*)&e,sizeof(e))){
                            recordNo++;
                            if(e.getId()==Id){
                                e.displayHeader();
                                e.displayEmployeeDetails();
                                isFound=1;
                                break;
                            }
                        }
                        if(isFound==0){
                            cout<<endl<<"No record Found";
                            getch();
                            break;
                        }
                        file.clear();
                        int location=(recordNo-1)*sizeof(e);
                        file.seekp(location,ios::beg);
                        cout<<endl<<"Enter New record for employee"<<endl;
                        e.getEmployeeDetails();
                        file.write((char*)&e,sizeof(e));
                        file.close();
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
