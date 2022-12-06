
#include <iostream>
using namespace std;

class complex
{
private:
    float real, img;

public:
    complex()
    {
        real=0;
        img=0;
    }
   
    friend ostream &operator<<( ostream &output,complex &D ) {
         output << D.real << "+" << D.img<< "i \n";
         return output;            
      }

    friend istream &operator>>( istream  &input, complex &D ) {

      cout<<"Enter the real part of complex no.:";
      input>>D.real;
      cout<<"Enter the imaginary part of complex no.:";
      input>>D.img;
      return input;            
    }
    complex operator +(complex  &num2){
        complex a;
        a.real=real+num2.real;
        a.img=img+num2.img;
        return a;
    }
    complex operator -(complex  &num2){
        complex a;
        a.real=real-num2.real;
        a.img=img-num2.img;
        return a;
    }
    complex operator *(complex &num2){
        complex a;
        a.real=(real*num2.real)-(img*num2.img);
        a.img=(real*num2.img)+(img*num2.real);
        return a;
    }

};
 int main()
{
    complex a,b,addition,difference,multiplication;
    cin>>a;
    cin>>b;
    char flag;
    do{
        cout<<"<------Menu------>"<<endl;
        cout<<"1.Addition"<<endl;
        cout<<"2.Substraction"<<endl;
        cout<<"3.Multiplication"<<endl;
        int n;
        cin>>n;
        switch (n)
        {
        case 1:
            addition=a+b;
            cout<<"The addition of two complex no. is : ";
            cout<<addition;
            break;
        case 2:
            difference=a-b;
            cout<<"The Substraction of two complex no. is : ";
            cout<<difference;
            break;
        case 3:
            multiplication=a*b;
            cout<<"The Multiplication of two complex no. is : ";
            cout<<multiplication;
            break;
       
        default:
            cout<<"INVALID CHOICE!";
            break;
        }
        cout<<"\n Do you want to continue? (y/n)";
        cin>>flag;
    }
    while(flag=='y');
    cout<<"Thank You!";
    return 0;
}
