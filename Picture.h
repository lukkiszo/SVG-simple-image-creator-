//
// Created by szopka on 2020-05-16.
//

#ifndef UNTITLED_PICTURE_H
#define UNTITLED_PICTURE_H

#ifndef Picture_h
#define Picture_h
#include <iostream>
#include <fstream>

int getWidth()
{
    int a;
    std::cout << "Podaj wybrana szerokosc obrazka: ";
    std::cin >> a;
    while (a <= 0)
    {
        std::cout << "Podaj dodatnia wartosc" << std::endl;
        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}
int getHeight()
{
    int a;
    std::cout << "Podaj wybrana wysokosc obrazka: ";
    std::cin >> a;
    while (a <= 0)
    {
        std::cout << "Podaj dodatnia wartosc" << std::endl;
        std::cin >> a;
    }
    std::cout << "\n";
    return a;
}

void closer(std::ofstream& klatka)
{
    klatka << "</g>" << std::endl;
    klatka << "</svg>" << std::endl;
}

class Picture
{
private:
    unsigned int szerokosc;
    unsigned int wysokosc;
    unsigned int stan;

public:
    int getStan() { return stan; }
    int getSzer() { return szerokosc; }
    int getWysok() { return wysokosc; }

    void zmienStan() { stan += 1; }

    virtual void draw(std::ofstream& klatka) {}

    Picture()
    {
        stan = 1;
        szerokosc = 1080;
        wysokosc = 720;
    }

    Picture(unsigned int szer, unsigned int wysk)
    {
        szerokosc = szer;
        wysokosc = wysk;
        std::cout << "Utworzono obrazek o wymiarach: " << szerokosc << "x" << wysokosc << std::endl;
    }

    static void make(std::ofstream& obraz, unsigned int width, unsigned int height)
    {
        obraz << "<svg width=\"" << width << "\" height=\"" << height << "\"> " << std::endl;
        obraz << "<g>" << std::endl;
    }

    void resolutionChoice();

    ~Picture() = default;
};

void Picture::resolutionChoice()
{
    Picture rysunek;
    int odpowiedz;
    std::cout << "Domyslna rozdzielczosc: " << rysunek.getSzer() << "x" << rysunek.getWysok() << std::endl;
    std::cout << "Chcesz ja zmienic? 1 - tak \t 0 - nie" << std::endl;
    std::cout << "Twoja odpowiedz: ";
    std::cin >> odpowiedz;
    if (odpowiedz == 0) std::cout << "Utworzono domyslny rysunek" << std::endl;
    if (odpowiedz != 0)
    {
        szerokosc = getWidth();
        wysokosc = getHeight();
    }
}

#endif

#endif //UNTITLED_PICTURE_H
