#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class Employee
{
    int empno;
    char name[50];
    char dsg[50];
    long salary;

public:
    void setData()
    {
        cout << "\nEnter Employee no. ";
        cin >> empno;
        cout << "\nEnter name of employee ";

        cin>>name;
        cout<<"\nEnter the designation of the employee";
        cin>>dsg;
        cout<<"\nEnter the salary of the employee";
        cin>>salary;
    }

    void showData()
    {
        cout << "\n Employee no. : " << empno;
        cout << "\n Student Name : " << name;
        cout<<"\n Designation: "<<dsg;
        cout<<"\n Salary: "<<salary;

    }

    int retempno()
    {
        return empno;
    }
};

void write_record()
{
    ofstream outFile;
    outFile.open("employee.dat", ios::binary | ios::app);

    Employee obj;
    obj.setData();

    outFile.write((char*)&obj, sizeof(obj));

    outFile.close();
}

void display()
{
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);

    Employee obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
    }

    inFile.close();
}


void search(int n)
{
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);

    Employee obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retempno() == n)
        {
            obj.showData();
            break;
        }
    }

    inFile.close();
}


void delete_record(int n)
{
    Employee obj;
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retempno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");
}

void modify_record(int n)
{
    fstream file;
    file.open("employee.dat",ios::in | ios::out);

    Employee obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retempno() == n)
        {
            cout << "\nEnter the new details of student";
            obj.setData();

            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);

            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}

int main()
{
	int ch;
	do{
    cout<<"\nMenu\n\t1.write\n2.display\n3.search\n4.delete\n5.modify";
    cout<<"\nEnter your choice";
    cin>>ch;
    switch(ch){

    case 1: cout<<"Enter number of records";
    int n;
    cin>>n;
    for(int i = 0; i <n; i++)
       write_record();
    break;

    case 2:

    cout << "\nList of records";
    display();
    break;


    case 3:
    	cout<<"Enter employee no. to be searched";
    	int s;
    	cin>>s;
    	search(s);
        	break;
    case 4:
    	cout<<"enter no to be deleted";
    	int d;
    	cin>>d;

    delete_record(d);
    cout << "\nRecord Deleted";
    break;
    case 5:


    	cout<<"enter EmpNo to be modified";
    	int m;
    	cin>>m;


    modify_record(m);
    break;
    case 6:

    return 0;
    }
	}while(ch!=6);
}









