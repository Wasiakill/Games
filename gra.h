#include <iostream>

using namespace std;

int sprawdz(char **tab,int n,char kontynuuj,int ruchy,char znak);
int jeszczeraz();
int rysuj(char **tab,int n,char znak);
int ruchy=0;

int kolumny(int n)
{
	int pola=1;
	cout << "  ";
	for(int i=0;i<n;++i)
	{
		if(pola<10)
		{
			cout << " " << pola << " ";
			pola=pola+1;
		}
		else
		{
			cout << pola << " ";
			pola=pola+1;
		}
	}
	return 0;
}
int plansza(char **tab,int n)
{
	kolumny(n);
	int pola=0;
	for(int i=0;i<n;i++)
	{
		if(pola<n)
		{
			if(pola<9)
			{
				pola=i+1;
				cout << "\n" << pola << " ";
			}
			else
			{
				pola=i+1;
				cout << "\n" << pola;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(tab[i][j]<10)
			{
				cout << "| " << tab[i][j] << "|";
			}
			else
			{
				cout << "|" << tab[i][j] << "|";
			}
		}
		cout << pola;
	}
	cout << "\n";
	kolumny(n);
	return 0;
}
int start(char **tab, int n) 
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			tab[i][j] = '_';
		}
	}
	plansza(tab,n);
	return 0;
}
int kolko(char **tab, int n,char znak)
{
	int a,b;
	
	cout << "\n" << "Kolko" << "\n";
	
	do
	{
		cout << "Podaj kolumne: ";
		cin >> a;
		cout << "Podaj wiersz: ";
		cin >> b;
	}
	while(a<=0||a>n||b<=0||b>n);
	
	if(tab[b-1][a-1]=='X'||tab[b-1][a-1]=='O')
	{
		cout << "Nie mozesz tam postawic " << "O \n";
		kolko(tab,n,znak);
		return 0;
	}
	tab[b-1][a-1]='O';
	plansza(tab,n);
	
	ruchy=ruchy+1;
	sprawdz(tab,n,'O',ruchy,znak);
	return 0;
}
int krzyrzyk(char **tab, int n,char znak)
{
	int a,b;
	
	cout << "\n" << "Krzyrzyk" << "\n";
	do
	{
		cout << "Podaj kolumne: ";
		cin >> a;
		cout << "Podaj wiersz: ";
		cin >> b;
	}
	while(a<=0||a>n||b<=0||b>n);
	
	if(tab[b-1][a-1]=='O'||tab[b-1][a-1]=='X')
	{
		cout << "Nie mozesz tam postawic " << "X \n";
		krzyrzyk(tab,n,znak);
		return 0;
	}
	tab[b-1][a-1]='X';
	plansza(tab,n);

	ruchy=ruchy+1;
	sprawdz(tab,n,'X',ruchy,znak);
	return 0;
}
int wybor(char **tab,int n)
{
	int wybierz;
	char znak='A';
	
	cout << "\nGra z komputerem-1 \nDwoch graczy-2 ";
	cin >> wybierz;
	
	start(tab,n);
	if(wybierz==2)
	{
		kolko(tab,n,znak);
	}
	else if(wybierz==1)
	{
		cout << "\nO czy X? ";
		cin >> znak;
		znak=toupper(znak);
		if(znak=='O')
		{
			kolko(tab,n,znak);
		}
		else if(znak=='X')
		{
			rysuj(tab,n,znak);
		}
	}
	return 0;
}
int koniec(int wygrana)
{
	if(wygrana=='O')
	{
		cout << "Kolko wygralo";
	}
	if(wygrana=='X')
	{
		cout << "Krzyrzyk wygral";
	}	
	jeszczeraz();
	return 0;
}
int remis()
{
	cout << "Remis";
	jeszczeraz();
	return 0;
}
int sprawdz(char **tab,int n,char kontynuuj,int ruchy,char znak)
{
	cout << "\n";
	for(int i=0; i<n; ++i)
	{
		for(int j=0;j<n;j++)
		{
			if(i<n-2&&j>1)
			{
				if(tab[i][j]==tab[i+1][j-1]&&tab[i][j]==tab[i+2][j-2])
				{
					if(tab[i][j]=='O'||tab[i][j]=='X')
					{
						delete [] tab;
						koniec(kontynuuj);
						return 0;
					}
				}
			}
			if(i<n-2&&j<n-2)
			{
				if(tab[i][j]==tab[i+1][j+1]&&tab[i][j]==tab[i+2][j+2])
				{
					if(tab[i][j]=='O'||tab[i][j]=='X')
					{
						delete [] tab;
						koniec(kontynuuj);
						return 0;
					}
				}	
			}
			if(j<n-2)
			{
				if(tab[i][j]==tab[i][j+1]&&tab[i][j]==tab[i][j+2])
				{
					if(tab[i][j]=='O'||tab[i][j]=='X')
					{
						delete [] tab;
						koniec(kontynuuj);
						return 0;
					}
				}
			}
			if(i<n-2)
			{
				if(tab[i][j]==tab[i+1][j]&&tab[i][j]==tab[i+2][j])
				{
					if(tab[i][j]=='O'||tab[i][j]=='X')
					{
						delete [] tab;
						koniec(kontynuuj);
						return 0;
					}
				}
			}
		}
	}
	if(ruchy==n*n)
	{
		delete [] tab;
		remis();
		return 0;
	}
	if(znak=='A')
	{
		if(kontynuuj=='O')
		{
			krzyrzyk(tab,n,znak);
		}
		if(kontynuuj=='X')
		{
			kolko(tab,n,znak);
		}
	}
	else if(znak=='O')
	{
		if(kontynuuj=='O')
		{
			rysuj(tab,n,znak);
		}
		if(kontynuuj=='X')
		{
			kolko(tab,n,znak);
		}
	}
	else if(znak=='X')
	{
		if(kontynuuj=='X')
		{
			rysuj(tab,n,znak);
		}
		if(kontynuuj=='O')
		{
			krzyrzyk(tab,n,znak);
		}
	}
	return 0;
}
int rysuj(char **tab,int n,char znak)
{
	int kontynuuj,ri,rj,dostepne=1;
	
	srand (time(NULL));
	
	cout << "\n";
	for(int i=0; i<n; ++i)
	{
		for(int j=0;j<n;++j)
		{
			if(dostepne==1)
			{
				if(i<n-2&&j>1)
				{
					if(tab[i][j]==tab[i+1][j-1])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i+2][j-2]!='X'&&tab[i+2][j-2]!='O')
							{
								if(znak=='X')
								{
									tab[i+2][j-2]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i+2][j-2]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}
				}
				else if(i<n-2&&j<n-2)
				{
					if(tab[i][j]==tab[i+1][j+1])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i+2][j+2]!='X'&&tab[i+2][j+2]!='O')
							{
								if(znak=='X')
								{
									tab[i+2][j+2]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i+2][j+2]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}	
				}
				else if(j<n-2)
				{
					if(tab[i][j]==tab[i][j+1])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i][j+2]!='X'&&tab[i][j+2]!='O')
							{
								if(znak=='X')
								{
									tab[i][j+2]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i][j+2]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}
				}
				else if(i<n-2)
				{
					if(tab[i][j]==tab[i+1][j])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i+2][j]!='X'&&tab[i+2][j]!='O')
							{
								if(znak=='X')
								{
									tab[i+2][j]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i+2][j]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}
				}
				else if(j<n&&j>2)
				{
					if(tab[i][j]==tab[i][j-1])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i][j-2]!='X'&&tab[i][j-2]!='O')
							{
								if(znak=='X')
								{
									tab[i][j-2]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i][j-2]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}
				}
				else if(i<n&&i>2)
				{
					if(tab[i][j]==tab[i-1][j])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i-2][j]!='X'&&tab[i-2][j]!='O')
							{
								if(znak=='X')
								{
									tab[i-2][j]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i-2][j]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}
				}
				else if(i>2&&j>2)
				{
					if(tab[i][j]==tab[i-1][j-1])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i-2][j-2]!='X'&&tab[i-2][j-2]!='O')
							{
								if(znak=='X')
								{
									tab[i-2][j-2]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i-2][j-2]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}
				}
				else if(j<n-2&&i>2)
				{
					if(tab[i][j]==tab[i-2][j+2])
					{
						if(tab[i][j]=='O'||tab[i][j]=='X')
						{
							if(tab[i-2][j+2]!='X'&&tab[i-2][j+2]!='O')
							{
								if(znak=='X')
								{
									tab[i-2][j+2]='O';
									kontynuuj='O';
									dostepne=0;
								}
								else if(znak=='O')
								{
									tab[i-2][j+2]='X';
									kontynuuj='X';
									dostepne=0;
								}
							}
						}
					}
				}
			}
		}
	}
	if(dostepne==1)
	{
		do
		{
			ri=rand()%n;
			rj=rand()%n;
		}
		while(tab[ri][rj]=='X'||tab[ri][rj]=='O');
		
		if(znak=='X')
		{
			tab[ri][rj]='O';
			kontynuuj='O';
			dostepne=0;
		}
		else if(znak=='O')
		{
			tab[rj][ri]='X';
			kontynuuj='X';
			dostepne=0;
		}
	}
	if(dostepne==0)
	{
		plansza(tab,n);
		ruchy=ruchy+1;
		sprawdz(tab,n,kontynuuj,ruchy,znak);
	}
	return 0;
}
