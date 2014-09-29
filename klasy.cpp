#include <iostream>
#include <list>
//dodać bibliotekę stringów


class plansza
{
	int dlugosc;
	list<gracz> gracze;
	vector<pole> pola;
	
	plansza();
	~plansza();
	
	void gra();
	bool koniecgry();
	void kolejka(gracz*);
	void ruch();
	int rzut();
};

class dzielnica
{
	list<pole*> miejsca;
	
	bool czywlascicielwspolny();
};

class pole
{
	int numer;
	gracz* wlasciciel; // można tak?
	dzielnica* dzielnia;
	
	pole();
	~pole();
	
	void akcja(gracz*);
};

	class polewlasnosci: protected pole
	{
		dzielnica* dzielnia;
		
		void akcja(gracz*);
	};
	
	class poleszansy: protected pole
	{
		kartaszansy* takarta;

		void akcja(gracz*);
	};
	
	class wiezienie: protected pole
	{
		
		void akcja(gracz*); // wywala gracza z kolejki lub wysyła polecenie, żeby gracz został wywalony z kolejki
	};
	
	class bezplatnyparking: protected pole
	{
		int hajsy;
		void akcja(gracz*);
	};




class karta
{
	gracz* wlasciciel;
	
	
};
	
	class kartawiezienia
	{
	};
	
	class kartaszansy
	{
		string instrukcja;
	};
	
class gracz
{
	int hajsy;
	bool wwiezieniu;
	int numerpola;
	
	void uwiez(); // uwięź się w więzieniu!
	int przesunsie(int);
	void stantutaj(int); // staje na polu
};



bool plansza::koniecgry()
{
	if(sizeof(gracze) < 2) // biblioteka list!!!
		return true
	else
		return false
}

int plansza::rzut()
{
	int a = rand%6+1;
	int b = rand%6+1;
	
	if(a == b)
	{
		cout << "DUBLET!" << endl; // rozwiązać kwestię potrójnego dubletu
		return a+b+rzut();
	}
	else
		return a+b;
}

void plansza::ruch()
{
	int plus = rzut();
	int numer = tytam->przesunsie(plus);
	if(numer > dlugosc)
	{
		//wypłacamyhajsy!!!
		stantutaj(numer%dlugosc);
	}	
}

void plansza::kolejka(gracz* tytam)
{
	ruch();
	gracze[numer]->akcja(tytam);
}

void plansza::gra()
{
	gracz* temp = gracze.begin(); // to nie tak, to nie tak, to nie tak...
	
	while(!koniecgry)
		kolejka(temp++);
}



bool dzielnica::czywlascicielwspolny()
{
	bool kupa = 0;
	for(list<pole*>::iterator temp = miejsca.begin(); temp != miejsca.end(); ++temp) // czemu tak jest?
	{
		if(temp->wlasciciel != ++temp->wlasciciel)
			kupa = 1;
	}
	
	return kupa;
}


int gracz::przesunsie(int plus)
{
	numerpola += plus;  // Hmm, hmm, hmm...
	return numerpola;
}
