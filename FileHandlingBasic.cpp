#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class Student
{
    int admno;
    char name[50];
    char addr[50];
public:
    void setData()
    {
        cout << "\nEnter Roll no. ";
        cin >> admno;
        cout << "Enter name of student ";
        //cin.getline(name,50);
        cin>>name;
        cout<<"enter the address of the student";
        cin>>addr;


    }

    void showData()
    {
        cout << "\nAdmission no. : " << admno;
        cout << "\nStudent Name : " << name;
        cout<<"\nAddress:"<<addr;
    }

    int retAdmno()
    {
        return admno;
    }
};

/*
* function to write in a binary file.
*/

void write_record()
{
    ofstream outFile;
    outFile.open("student.odt", ios::binary | ios::app);

    Student obj;
    obj.setData();

    outFile.write((char*)&obj, sizeof(obj));

    outFile.close();
}

/*
* function to display records of file
*/


void display()
{
    ifstream inFile;
    inFile.open("student.odt", ios::binary);

    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
    }

    inFile.close();
}

/*
* function to search and display from binary file
*/

void search(int n)
{
    ifstream inFile;
    inFile.open("student.odt", ios::binary);

    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.showData();
            break;
        }
    }

    inFile.close();
}

/*
* function to delete a record
*/

void delete_record(int n)
{
    Student obj;
    ifstream inFile;
    inFile.open("student.odt", ios::binary);

    ofstream outFile;
    outFile.open("temp.odt", ios::out | ios::binary);

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

/*
* function to modify a record
*/

void modify_record(int n)
{
    fstream file;
    file.open("student.odt",ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
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

    case 1: cout<<"Enter number of records";//Store 4 records in file
    int n;
    cin>>n;
    for(int i = 0; i <n; i++)
       write_record();
    break;

    case 2:
    //Display all records
    cout << "\nList of records";
    display();
    break;


    case 3://Search record
    	cout<<"Enter admission no. to be searched";
    	int s;
    	cin>>s;
    	search(s);
        	break;
    case 4:
    	cout<<"enter no to be deleted";
    	int d;
    	cin>>d;
    //Delete record
    delete_record(d);
    cout << "\nRecord Deleted";
    break;
    case 5:

    //Modify record
    	cout<<"enter rno to be modified";
    	int m;
    	cin>>m;

    
    modify_record(m);
    break;
    case 6:

    return 0;
    }
	}while(ch!=6);
}
