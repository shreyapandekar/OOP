#include<iostream>
#include<string.h>
using namespace std;

class publication{
    protected:
    string title;
    float price;
    public:
    publication(){
        title="Publication Name : Shreya";
    }
    ~publication(){
    }  
};

class book:public publication
{
    protected:
    int pages;
    public:
    void putdata()
    {
        cout<<"Enter the book details below: "<<endl;
        cout<<"Title : ";
        cin>>title;
        cout<<"Price : ";
        cin>>price;
        try
        {
            cout<<"Pages : ";
            cin>>pages;
            if(pages<0)
            {
                throw pages;
            }
        }
        catch(int pages)
        {
            cout<<"Exception Caught";
            title="";
            price=0;
            this->pages=0;
        }        
    }
    void getdata(){
        cout<<"The Book details are follow: "<<endl;
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Pages : "<<pages<<endl;

    }
    ~book(){
    }
};
class cassate_tape:public publication{
    protected:
    float minutes;
    public:
    cassate_tape():publication(){
        minutes=0;
    }
    void putdata(){
        cout<<"Enter the Tape Details below "<<endl;
        cout<<"Title : ";
        cin>>title;
        cout<<"Price : ";
        cin>>price;
        try{
            cout<<"Minutes : ";
            cin>>minutes;
            if (minutes<0)
            {
                throw minutes;
            }
        }    
        catch (float minutes){
            cout<<"Exception caught : ";
            title="0";
            price=0;
            this->minutes=0;        
        }
    }
    void getdata(){
        cout<<"The Tape details are as follow: "<<endl;
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Minutes : "<<minutes<<endl;
    }
    ~cassate_tape(){
    }
};
int main(){
    book a;
    cassate_tape b;
    a.putdata();
    a.getdata();
    b.putdata();
    b.getdata();
    return 0;
}
