#include <iostream>
#include <cmath>

using namespace std;

class Punkt{
	private:	
		int x,y,wx,wy;
		friend class Okrag;
	public:
		przypisz()
		{
			cout<<"Podaj wspolrzedna x = ";
			cin>>x;
			cout<<"Podaj wspolrzedna y = ";
			cin>>y;
		}
		wypisz()
		{
			cout<<"wspolrzedne punktu = ( "<<x<<" ; "<<y<<" )"<<endl;
		}
		odleglosc(Punkt a, Punkt b)
		{
			cout<<"Odleglosc miedzy punktami A = ("<<a.x<<", "<<a.y<<"), B = ("<<b.x<<", "<<b.y<<") wynosi: "
	<<sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
		}
		przesun(Punkt a)
		{
			cout<<"Podaj wektor [x,y] (po spacji x i y): ";
			cin>>wx>>wy;
			x+=wx;
			y+=wy;
		}
};

class Okrag : public Punkt{
	private:
		int x,y,r;
		float pole;
	public:
		utworz(int x, int y, int r)
		{
			this->x = x;
			this->y = y;
			this->r = r;
			cout<<"Utworzono okrag w punkcie = ( "<<x<<" ; "<<y<<" ) i promieniu r = "<<r<<endl;
			pole = 3.14 * r * r;
			cout<<"Pole wynosi = "<<pole<<endl;
		}
		utworz(Punkt a,int r)
		{
			x = a.x;
			y = a.y;
			this->r = r;
			cout<<"Utworzono okrag w punkcie = ( "<<x<<" ; "<<y<<" ) i promieniu r = "<<r<<endl;
			pole = 3.14 * r * r;
			cout<<"Pole wynosi = "<<pole<<endl;
		}
		wspolne(Okrag z)
		{
			if(x==z.x && y == z.y && r == z.r)
			{
				cout<<"Okregi pokrywaja sie"<<endl;
			}
			else if( (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) == (r-z.r) || (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) == (z.r-r) )
			{
				cout<<"Okregi styczne wewnetrznie"<<endl;
			}
			else if( (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) == (r+z.r) )
			{
				cout<<"Okregi styczne zewnetrznie"<<endl;
			}
			else if( (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) < (r-z.r) || (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) < (z.r-r) )
			{
				cout<<"Brak punktow wspolnych"<<endl;
			}
			else if( (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) > (r+z.r) )
			{
				cout<<"Brak punktow wspolnych"<<endl;
			}
			else if( (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) > (r-z.r) && (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) < (r+z.r) )
			{
				cout<<"Dwa punkty wspolne"<<endl;
			}
			else if( (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) > (z.r-r) && (sqrt((z.x-x)*(z.x-x)+(z.y-y)*(z.y-y))) < (r+z.r) )
			{
				cout<<"Dwa punkty wspolne"<<endl;
			}
			
		}
};

int main()
{
	Punkt a;
	cout<<"Punkt srodka okregu"<<endl;
	a.przypisz();
	a.wypisz();
	Okrag okrag, okrag2;
	okrag.utworz(3,4,5);
	okrag2.utworz(a,6);
	okrag.wspolne(okrag2);
}
