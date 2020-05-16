#ifndef Animation_h
#define Animation_h
#include "Picture.h"
#include "Plate.h"
#include "Sun.h"
#include <vector>

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

    void make(std::vector<std::ofstream*>& wek,  Picture& rysunek, Sun& slonce, Plate& talerz)
    {   
        for(size_t i=0; i<6; i++)
        {
            draw(*wek[i], rysunek, slonce, talerz);
        }        
    }

    void doAll()
    {
        std::vector <std::ofstream*> wektor;

        rysunek.resolutionChoice();

        std::ofstream klatka1 ("klatka1.svg");
        std::ofstream klatka2 ("klatka2.svg");
        std::ofstream klatka3 ("klatka3.svg");
        std::ofstream klatka4 ("klatka4.svg");
        std::ofstream klatka5 ("klatka5.svg");
        std::ofstream klatka6 ("klatka6.svg");

        wektor.reserve(6);
        wektor.push_back(&klatka1);
        wektor.push_back(&klatka2);
        wektor.push_back(&klatka3);
        wektor.push_back(&klatka4);
        wektor.push_back(&klatka5);
        wektor.push_back(&klatka6);

        slonce.makeSun(rysunek);
        talerz.makePlate(rysunek);
        make(wektor, rysunek, slonce, talerz);

        wektor.clear();
    }

    ~Animation() = default;

};

#endif