//
// Created by szopka on 2020-05-16.
//

#ifndef UNTITLED_SUN_H
#define UNTITLED_SUN_H

#ifndef Sun_h
#define Sun_h
#include "Picture.h"

int getSunStartHeight(Picture& rys)
{
    int a;
    std::cout << "Podaj wybrana wysokosc slonca (w pikselach): ";
    std::cin >> a;
    while (a < ((rys.getWysok()) / 3) || a > rys.getWysok() - 100)
    {
        if (a < ((rys.getWysok()) / 3)) std::cout << "Slonce nie moze byc tak nisko, podaj liczbe z zakresu " << rys.getWysok() / 3 << " a " << rys.getWysok() - 100 << " :" << std::endl;
        if ((a + 100) > (rys.getWysok())) std::cout << "Slonce nie moze wyjsc poza obrazek, podaj liczbe z zakresu " << rys.getWysok() / 3 << " a " << rys.getWysok() - 100 << " :" << std::endl;

        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}

int getSunStartWidth(Picture& rys)
{
    int a;
    std::cout << "Podaj wybrana wspolrzedna x slonca(w pikselach): ";
    std::cin >> a;
    while (a<100 || a>rys.getSzer() - 100)
    {
        std::cout << "Podaj liczbe z zakresu 100 a " << rys.getSzer() - 100 << ": " << std::endl;
        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}

int getSunRadius(Picture& rys)
{
    int a;
    std::cout << "Podaj promien slonca (w pikselach): ";
    std::cin >> a;
    while (a < 0 || (a > rys.getSzer() && a > rys.getWysok()))
    {
        std::cout << "Podaj liczbe z zakresu 0 a " << ((rys.getWysok() < rys.getSzer()) ? rys.getWysok() : rys.getSzer()) << std::endl;
        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}

class Sun : public Picture
{
private:
    unsigned int promien;
    unsigned int wspx;
    unsigned int wspy;

public:

    int sprawdzPromien(unsigned int a);

    virtual void draw(std::ostream& obraz)
    {
        obraz << "<title>Slonce</title>" << std::endl;
        obraz << "<circle id=\"slonce\" cx=\"" << wspx << "\" cy=\"" << getWysok() - wspy << "\" r=\"" << promien << "\"" << " fill=\"#FFFA8D\"/>" << std::endl;
        obraz << "<line id=\"l1\" y2=\"" << sprawdzPromien(getWysok() - wspy + ((8 * promien) / 3)) << "\" x2=\"" << wspx << "\" y1=\"" << getWysok() - (wspy + (4 * promien / 3)) << "\" x1=\"" << wspx << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
        obraz << "<line id=\"l2\" y2=\"" << sprawdzPromien(getWysok() - (wspy + (2 * promien))) << "\" x2=\"" << (wspx + 2 * promien) << "\" y1=\"" << getWysok() - (wspy + promien) << "\" x1=\"" << (wspx + promien) << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
        obraz << "<line id=\"l3\" y2=\"" << getWysok() - wspy << "\" x2=\"" << (wspx + (8 * promien / 3)) << "\" y1=\"" << getWysok() - wspy << "\" x1=\"" << (wspx + (4 * promien) / 3) << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
        obraz << "<line id=\"l4\" y2=\"" << getWysok() - (wspy - 2 * promien) << "\" x2=\"" << (wspx + 2 * promien) << "\" y1=\"" << getWysok() - (wspy - promien) << "\" x1=\"" << (wspx + promien) << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
        obraz << "<line id=\"l5\" y2=\"" << getWysok() - (wspy - ((8 * promien) / 3)) << "\" x2=\"" << wspx << "\" y1=\"" << getWysok() - (wspy - (4 * promien / 3)) << "\" x1=\"" << wspx << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
        obraz << "<line id=\"l6\" y2=\"" << getWysok() - (wspy - (2 * promien)) << "\" x2=\"" << (wspx - 2 * promien) << "\" y1=\"" << getWysok() - (wspy - promien) << "\" x1=\"" << (wspx - promien) << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
        obraz << "<line id=\"l7\" y2=\"" << getWysok() - wspy << "\" x2=\"" << (wspx - (8 * promien / 3)) << "\" y1=\"" << getWysok() - wspy << "\" x1=\"" << (wspx - (4 * promien) / 3) << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
        obraz << "<line id=\"l8\" y2=\"" << sprawdzPromien(getWysok() - (wspy + 2 * promien)) << "\" x2=\"" << (wspx - 2 * promien) << "\" y1=\"" << getWysok() - (wspy + promien) << "\" x1=\"" << (wspx - promien) << "\" stroke-width=\"6\" stroke=\"#FFFF91\"/>" << std::endl;
    }

    int getRadius() { return promien; }
    int getWSPX() { return wspx; }
    int getWSPY() { return wspy; }

    Sun()
    {
        promien = 120;
        wspx = getSzer() / 2;
        wspy = getWysok() - 200;
    }

    Sun(unsigned int r, unsigned int x, unsigned int y)
    {
        promien = r;
        wspx = x;
        wspy = y;
        std::cout << "Utworzono slonce o promieniu r = " << promien << " i wspolrzednych (x,y) : (" << wspx << "," << wspy << ")" << std::endl;
    }

    void makeSun(Picture& rys)
    {
        Sun temp;
        int odpowiedz;
        std::cout << "\nWARTOSCI DOMYSLNE SLONCA:" << std::endl;
        std::cout << "wysokosc: " << temp.getWSPY() << ", szerokosc: " << temp.getWSPX() << ", promien: " << temp.getRadius() << std::endl;
        std::cout << "\nWpisz 1 aby podac cechy slonca lub wpisz 0 aby ustawic wartosci domyslne" << std::endl;
        std::cin >> odpowiedz;
        if (odpowiedz != 0)
        {
            promien = getSunRadius(rys);
            wspx = getSunStartWidth(rys);
            wspy = getSunStartHeight(rys);
        }
    }

    ~Sun() = default;
};

int Sun::sprawdzPromien(unsigned int a)
{
    if (a > getWysok()) return 0;
    else return a;
}

#endif

#endif //UNTITLED_SUN_H
