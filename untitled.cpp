#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Hospital {
private:
    string Name, Address,BGroup;

public:
    Hospital(): Name(""), Address(""), BGroup(""){}

    void setName(string name){
    Name = name;
    }

    void setAddress(string address){
    Address = address;
    }

    void setBGroup(string bgroup){
    BGroup = bgroup;
    } 

string getName(){
    return Name;
}

string getAddress(){
    return Address;
}

string getBGroup(){
    return BGroup;
}
};

void admit (Hospital patient){
    system("cls");
    string name, address , bgroup;

    cout<<"\tEnter Name of Patient: ";
    cin>>name;
    patient.setName(name);


    cout<<"\tEnter Address of Patient: ";
    cin>>address;
    patient.setAddress(address);


    cout<<"\tEnter BGroup of Patient: ";
    cin>>bgroup;
    patient.setBGroup(bgroup);
    ofstream outfile("hospital.csv", ios::app);

    if(!outfile){
        cout<<"\tError: File can't Open!"<<endl;
    }
    else{
        outfile<<"\t"<<patient.getName()<<","<<patient.getAddress()<<","<<patient.getBGroup()<<endl<<endl<<endl;
        cout<<"\tPatient Admited"<<endl;

    }
    outfile.close();
    Sleep(5000);
}

void discharge(){
    system("cls");
    string name;
    cout<<"\tEnter the name of petient:"<<endl;
    cin>>name;

      ifstream infile("hospital.csv");
    ofstream outfile("hospital temp.csv");
    if(!infile || !outfile){
        cout<<"\tError:File can't open"<<endl;
    }
    else{
        string line;
        bool found = false;

    while(getline(infile, line)){
        stringstream ss;
        ss<<line;
        string patientName;
        ss>> patientName;
        if(name==patientName){
            found = true;
            cout<<"\tPatient Dischareg"<<endl;
        }
        else{
            outfile<<line<<endl;
        }
    }
    if(!found){
        cout<<"\tIncorrect Patient name!";
    }
    }
    outfile.close();
    infile.close();
    remove("hospital temp.csv");
    rename("hospital.csv","hospital.csv");
    Sleep(5000);
}

int main(){
    Hospital patient;

    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tHospital Management Syatem"<<endl;
        cout<<"\t******************"<<endl;
        cout<<"\t1.Admit Patient"<<endl;
        cout<<"\t2.Discharge Patient"<<endl;
        cout<<"\t3.Exit"<<endl;
        cout<<"\tEnter Choice:";
        cin>>val;

        if(val==1){
            admit(patient);

        }

        else if(val==2){
            discharge();
        }

        else if(val==3){
            system("cls");
            exit = true;
            
            cout<<"\tHave a healthy life"<<endl;
            Sleep(5000);
        }
        Sleep(5000);

    }
}
