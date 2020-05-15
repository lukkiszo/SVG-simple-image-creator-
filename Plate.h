#ifndef Plate_h
#define Plate_h
#include "Picture.h"

int getPlateRadiusX(Picture& rys)
{
    int a;
    std::cout << "Podaj wybrana dlugosc talerza: ";
    std::cin >> a;
    while(a<0 || (a>rys.getSzer() && a>rys.getWysok()))
    {
        std::cout << "Podaj liczbe z zakresu 0 a " << ((rys.getWysok()<rys.getSzer())?rys.getWysok():rys.getSzer()) << std::endl;
        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}

int getPlateRadiusY(Picture& rys)
{
    int a;
    std::cout << "Podaj wybrana grubosc talerza: ";
    std::cin >> a;
    while(a<0 || (a>rys.getSzer() && a>rys.getWysok()))
    {
        std::cout << "Podaj liczbe z zakresu 0 a " << ((rys.getWysok()<rys.getSzer())?rys.getWysok():rys.getSzer()) << std::endl;
        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}

int getPlateStartHeight(Picture& rys)
{
    int a;
    std::cout << "Podaj wybrana wysokosc talerza wzgledem ziemi: ";
    std::cin >> a;
    while(a<0 || a>rys.getWysok())
    {
        std::cout << "Podaj liczbe z zakresu 0 a " << rys.getWysok() << std::endl;
        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}

int getPlateRotation()
{
    int a;
    std::cout << "Podaj poczatkowe nachylenie talerza (w stopniach): ";
    std::cin >> a;
    std::cout << "\n";
    return a;
}

int getRotationChange()
{
    int odpowiedz;
    std::cout << "Podaj w skali 1-5 jak szybko ma sie zmieniac nachylenie talerza: ";
    std::cin >> odpowiedz;
    while(odpowiedz < 1 || odpowiedz > 5)
    {
        std::cout << "Mozesz tylko podac liczby od 1 do 5. Twoja odpowiedz: ";
        std::cin >> odpowiedz;
    }
    std::cout << "\n";
    return odpowiedz;
}

class Plate: public Picture
{
    private:
    unsigned int szerokosc; // rx
    unsigned int wysokosc; // ry
    unsigned int wspxt;  // cx
    unsigned int wspyt;  // cy
    double nachylenie;
    unsigned int zmiana;

    public:
    Plate()
    { 
        szerokosc = 95;
        wysokosc = 20;
        wspxt = 100;
        wspyt = getWysok()/2;
        nachylenie = 20;
        zmiana = 5;
    }

    Plate(unsigned int szer, unsigned int wys, unsigned int x, unsigned int y, double nach, unsigned int zmi)
    {
        szerokosc = szer;
        wysokosc = wys;
        wspxt = x;
        wspyt = y;
        nachylenie = nach;
        zmiana = zmi;
    }

    int getRX() const {return szerokosc;}
    int getRY() const {return wysokosc;}
    int getCX() const {return wspxt;}
    int getCY() const {return wspyt;}
    int getRot() const {return nachylenie;}
    int getCng() const {return zmiana;}

    virtual void draw(std::ostream& obraz)
    {
        unsigned int tmp = stan - 1;
        double kat = 0;

        if((nachylenie - (tmp * ((double)zmiana / 15) * nachylenie)) > 0) kat = -(nachylenie - (tmp * ((double)zmiana / 15) * nachylenie));
        else kat = fabs(nachylenie - (tmp * ((double)zmiana / 15) * nachylenie));
            
        obraz << "<title>Talerz</title>" << std::endl;
        obraz << "<ellipse transform=\"rotate(" << kat << " " << wspxt << "," << getSzer() - wspyt << ")\" ";
        obraz << "cx=\"" << wspxt + tmp * getSzer() / 6 << "\" cy=\"" << getWysok() - wspyt << "\" rx=\"" << szerokosc << "\" ry=\"" << wysokosc << "\" style=\"fill:brown\" />" << std::endl;

        stan += 1;
    }

    static Plate makePlate(Picture& rys)
    {
        Plate temp;
        int odpowiedz;
        std::cout << "\nWARTOSCI DOMYSLNE TALERZA:" << std::endl;
        std::cout << "wysokosc: " << temp.getCY() << ", szerokosc: " << temp.getCX() << ", grubosc: " << temp.getRY() << ", dlugosc: " << temp.getRX() << std::endl;
        std::cout << "nachylenie: " << temp.getRot() << ", zmiana nachylenia (skala od 1 do 5): " << temp.getCng() << std::endl; 
        std::cout << "\nWpisz 1 aby podac cechy talerza lub wpisz 0 aby ustawic wartosci domyslne" << std::endl;
        std::cin >> odpowiedz;
        if(odpowiedz != 0)
        {
            Plate temp(getPlateRadiusX(rys), getPlateRadiusY(rys), 100 , getPlateStartHeight(rys), getPlateRotation(), getRotationChange());
            return temp;
        } 
        else return temp;
    }

    ~Plate() = default;
};

#endif