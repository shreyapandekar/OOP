#include<iostream>
#include<string.h>
using namespace std;

class studData;

class students{
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;
    static int count;

    public:
    students()
    {
        name="";
        roll_no=0;
        cls="";
        division=new char;
        dob="dd/mm/yyyy";
        bloodgroup=new char[4];

    }
    ~students(){
        delete division;
        delete[] bloodgroup;

    }
    static int getcount(){
        return count;
    }
    void getdata(studData*);
    void dispdata(studData*);
};

class studData{
    string address;
    long int* tellno;
    long int* dlno;

    public:
    studData()
    {
        address="";
        tellno=new long;
        dlno=new long;

    }
    ~studData()
    {
        delete tellno;
        delete dlno;

    }
    void getstudData(){
        cout<<"Enter contact no: ";
        cin.get();
        getline(cin,address);
        cout<<"Enter tell no: ";
        cin>>*tellno;
        cout<<"driving License: ";
        cin>>*dlno;
    }
    void dispstudData()
    {
        cout<<"Contact Address: "<<address<<endl;
        cout<<"Telephone number: "<<*tellno<<endl;
        cout<<"Driving License: "<<*dlno<<endl;
    }

};

inline void students::getdata(studData* st){
    cout<<"Enter students Name: ";
    getline(cin,name);
    cout<<"Enter students rollno: ";
    cin>>roll_no;
    cout<<"Enter students class: ";
    cin.get();
    getline(cin,cls);
    cout<<"Enter students division: ";
    cin>>division;
    cout<<"Enter Dob": ;
    cin.get();
    getline(cin,dob);
    cout<<"Enter bloodgroup: ";
    cin>>bloodgroup;
    st->getstudData();
    count++;
}

inline void students::dispdata(studData* st1){
    cout<<"Name: "<<name<<endl;
    cout<<"rollno: "<<roll_no<<endl;
    cout<<"class: "<<cls;
    cout<<"division: "<<division<<endl;
    cout<<"DOB: "<<dob<<endl;
    cout<<"Bloodgroup: "<<bloodgroup<<endl;
    st1->dispstudData();
}
int students::count;
int main(){
    students* stud1[100];
    studData* stud2[100];
    int n=0;
    char ch;

    do
    {
        stud1[n]=new students;
        stud2[n]=new studData;
        stud1[n]->getdata(stud2[n]);
        n++;
        cout<<"Do you want to add another student (y/n) : ";
        cin>>ch;
        cin.get();
    } while (ch=='y' || ch=='Y');

    for(int i=0;i<n;i++)
    {
        cout<<"---------------------------------------------------------------"<<endl;
        stud1[i]->dispdata(stud2[i]);
    }

    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Total Students : "<<students::getcount();
    cout<<endl<<"---------------------------------------------------------------"<<endl;

    for(int i=0;i<n;i++)
    {
        delete stud1[i];
        delete stud2[i];
    }
    return 0;

}
