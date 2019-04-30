
#include<iostream>
#include<stdlib.h>
#include<string.h>

#define MAX 10
using namespace std;

struct hash
{
	int id;
	char name[20];
}rec[MAX],tmp;

class hashtable
{
	public:
	void initialize();
	int hashing( int );
	void woreplace( struct hash );
	void wreplace( struct hash );
	void place_at_next_slot(int, struct hash);
	void display();
	void search(int);
};

void hashtable::initialize() {
	int i;
	for(i = 0; i < MAX; i++ ){
		rec[i].id = -1;      strcpy( rec[i].name, "-" );
	}
}

int hashtable::hashing( int no ) {
	int key;
	key = no % MAX;
	return( key );
}

void hashtable::woreplace( struct hash h ) {
	int i,k,z;
	k = hashing( h.id );

	if( rec[k].id == -1 ) {
		rec[k].id = h.id;
		strcpy( rec[k].name, h.name );
	}
	else
		place_at_next_slot(k,h);
}

void hashtable::place_at_next_slot( int k, struct hash h )
{
	int i, z;
	for(i = 1; i < MAX; i++ ){
		z = (k+i)%MAX;
		if( rec[z].id == -1 ){
			rec[z].id = h.id;
			strcpy( rec[z].name, h.name );
			break;
		}
	}

}

void hashtable::display() {
	cout<<"\n Collision Handling :\n\t----------------------------------";
	cout<<"\n\t Index     ID      Name   \n\t----------------------------------\n";
	for(int i = 0; i < MAX; i++ ) {
		cout<<"\t"<<i <<"\t "<<rec[i].id;
		cout<<"\t "<<rec[i].name;
		cout<<"\n";
	}
	cout<<"\n\t----------------------------------\n";
}

void hashtable::wreplace( struct hash h )
{
	int k,p,change_pos;

	k = hashing( h.id );

	if( rec[k].id == -1 )
	{
		rec[k].id = h.id;
		strcpy( rec[k].name, h.name );
	}
	else if( hashing(rec[k].id) == hashing(h.id) )
		place_at_next_slot(k,h);
	else
	{
		tmp.id = rec[k].id;
		strcpy( tmp.name, rec[k].name );

		rec[k].id = h.id;
		strcpy(rec[k].name, h.name);

		place_at_next_slot(k,tmp);

	}
}

void hashtable::search( int key )
{
	int i,k,z;
	int flag = 0;
	k = hashing( key );

	if( rec[k].id == key )
		cout << "\n Key " << key << " found at home address !!";
	else
	{
		for(z = 1; z < MAX; z++ ){
			i = (k+z)%MAX;
			if( rec[i].id == key ) {
				cout << "\n Key " << key << " found at "<< i << " address!!";
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout << "\n Key " << key << " not present in the table";
	}
}



int main(){
	hashtable h;
	int ch,ch1,key;
	char ans;
	struct hash temph;
		do	{
		cout<<"\n Collision Handling ";
		cout<<"\n 1. Without Replacement \n 2. With Replacement ";
		cout<<"\n 3. Display Record \n 4. Search Record \n 5. Exit \n Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				h.initialize();
				do {
					cout<<"\n Enter ID : ";
					cin>>temph.id;
					cout<<"\n Enter Name : ";
					cin>>temph.name;
					h.woreplace(temph);
					cout<<"\n Do you want to add more elements(0/1)? ";
					cin>>ch1;
				}while( ch1 != 0 );
				break;

			case 2:
				h.initialize();
				do{
					cout<<"\n Enter ID : ";
					cin>>temph.id;
					cout<<"\n Enter Name : ";
					cin>>temph.name;
					h.wreplace(temph);
					cout<<"\n Do you want to add more elements(0/1)? ";
					cin>>ch1;
				}while( ch1 != 0 );
				break;
			case 3:
                               h.display();  break;
			case 4:
				cout << "\n Enter the id for searching: ";
				cin >> key;
                               	h.search(key);
				break;
			case 5:  exit(0);
		}
	}while( ch != 5 );
return 0;
}



