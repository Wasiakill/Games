#include <iostream>
#include "gra.h"

using namespace std;

int main()
{
	int n;
	
	do
	{
		cout << "Podaj rozmiar (minimum 3): ";
		cin >> n;
	}
	while(n<3);
	
	char **tablica = new char *[n];
	
	for(int i=0;i<n;i++)
	{
		tablica[i] = new char [n];
	}
	wybor(tablica,n);
	return 0;
}
int jeszczeraz()
{
	int odp;
	cout << "\nAby zagrac ponownie wcisnij 1 ";
	cin >> odp;
	if(odp==1)
	{
		main();
	}
	return 0;
}
