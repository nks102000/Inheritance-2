/*Extend the program 1 to derive a class from result from class ‘test’ which includes member 
function to calculate total marks and percentage of a student. 
Input the data for a student and display its total marks and percentage*/
#include<iostream>
#include<string.h>
using namespace std;

class student{
    char *name;
    int roll;
    int age;
    public:
        void set(char *n,int r,int a){
            name=new char[strlen(n)];
            strcpy(name,n);
            roll=r;
            age=a;
        }
        void get(){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<roll<<endl;
            cout<<"Age: "<<age<<endl;
        }
        ~student(){
            delete(name);
        }
};

class test:public student{
    protected:
        int marks[5];
    public:
        void set(char *n,int r,int a,int *m){
            student::set(n,r,a);
            for(int i=0;i<5;i++){
                marks[i]=m[i];
            }
        }
        void get(){
            student::get();
            cout<<"Marks of student are: "<<endl;
            for(int i=0;i<5;i++){
                cout<<"Marks of subject "<<i+1<<": "<<marks[i]<<endl;
            }
        }
        ~test(){
            delete(marks);
        }
};

class result:public test{
    int total;
    float percentage;
    public:
        void set(char *n,int r,int a,int *m){
            total=0;
            percentage=0.0;
            test::set(n,r,a,m);
        }
        void cal(){
            for(int i=0;i<5;i++){
                total=total+marks[i];
            }
            percentage=total/5.0;
        }
        void get(){
            test::get();
            cout<<"Total: "<<total<<endl;
            cout<<"Percentage: "<<percentage<<endl;
        }
};

int main(){
    cout<<"Enter the Number of student data you want to enter:";
    int n;
    cin>>n;
    result t[n];
    char *name = new char[50];
    int roll;
    int age;
    int marks[5];
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Enter Details of students:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Enter Details of "<<i+1<<"st students:"<<endl;
       cout<<"Enter name: ";
       cin.ignore();
       cin.getline(name,50); 
       cout<<"Enter Roll Number: ";
       cin>>roll;
       cout<<"Enter Age: ";
       cin>>age;
       cout<<"Enter Marks of student : "<<endl;
        for(int j=0;j<5;j++){
            cout<<"Enter Marks of subject "<<j+1<<": ";
            cin>>marks[j];
        }
        t[i].set(name,roll,age,marks);
    }
    for(int i=0;i<n;i++){
        t[i].cal();
        t[i].get();
    }
    return 0;
}