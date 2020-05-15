#ifndef Animation_h
#define Animation_h
#include "Picture.h"
#include "Plate.h"
#include "Sun.h"
#include <vector>

template <class Type, class Allocator = std::allocator <Type>>
class vector;

class Animation
{
    public:
    Animation() = default;

    Picture rysunek;
    Sun slonce;
    Plate talerz;

    virtual void draw(std::ofstream& klatka, Picture& rysunek, Sun& slonce, Plate& talerz)
    {
        rysunek.make(klatka, rysunek.getSzer(), rysunek.getWysok());
        slonce.draw(klatka);
        talerz.draw(klatka);
        closer(klatka);
        klatka.close();
    }

    void make(std::ofstream& klatka1, std::ofstream& klatka2, std::ofstream& klatka3, std::ofstream& klatka4, std::ofstream& klatka5, std::ofstream& klatka6,  Picture& rysunek, Sun& slonce, Plate& talerz)
    {        
        draw(klatka1, rysunek, slonce, talerz);  // klatka1
        draw(klatka2,rysunek, slonce, talerz);   // klatka2
        draw(klatka3,rysunek, slonce, talerz);   // klatka3
        draw(klatka4,rysunek, slonce, talerz);   // klatka4
        draw(klatka5,rysunek, slonce, talerz);   // klatka5
        draw(klatka6, rysunek, slonce, talerz);  // klatka6
    }

    void doAll()
    {
        std::vector<std::ofstream&> wek;

        rysunek.resolutionChoice();

        std::ofstream klatka1 ("klatka1.svg");
        std::ofstream klatka2 ("klatka2.svg");
        std::ofstream klatka3 ("klatka3.svg");
        std::ofstream klatka4 ("klatka4.svg");
        std::ofstream klatka5 ("klatka5.svg");
        std::ofstream klatka6 ("klatka6.svg");

        wek.push_back(klatka1);
        wek.push_back(klatka2);
        wek.push_back(klatka3);
        wek.push_back(klatka4);
        wek.push_back(klatka5);
        wek.push_back(klatka6);

        slonce.makeSun(rysunek);
        talerz.makePlate(rysunek);
        make(klatka1, klatka2, klatka3, klatka4, klatka5, klatka6, rysunek, slonce, talerz);
        //make(wek, rysunek, slonce, talerz);
    }

    ~Animation() = default;

};

#endif