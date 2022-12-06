#include <iostream>
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
        name=" ";
        roll_no=0;
        cls="";
        division=new char;
        dob="dd/m/yyyy";
        bloodgroup=new char[4];
    }
    ~students(){
        delete division;
        delete[] bloodgroup;
    }

    static int getcount()
    {
        return count;
    }
    void getData(studData*);
    void dispData(studData*);

};
class studData{
    string address;
    long int* tellno;
    long int* dlno;
    friend class students;
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
        cout<<"enter contact address";
        cin.get();
        getline(cin,address);
        cout<<"Enter telephonr no";
        cin>>*tellno;
        cout<<"Enter driving license";
        cin>>*dlno;
    }
    void dispstudData()
    {
        cout<<"Contact Address"<<address<<endl;
        cout<<"Telephne number"<<*tellno<<endl;
        cout<<"Driving licence"<<*dlno<<endl;
    }

};

inline void students::getData(studData* st){
    cout<<"Enter student Name";;
    getline(cin,name);
    cout<<"Enter roll no";
    cin>>roll_no;
    

}
