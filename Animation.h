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


    std::vector<Picture*> cosRobi()
    {
        std::vector<Picture*> obraz;

        Picture* p = &rysunek;
        Sun* s = &slonce;
        Plate* t = &talerz;

        obraz.push_back(p);
        obraz.push_back(s);
        obraz.push_back(t);

        return obraz;
        // for(size_t i=0;i<3;i++)
        // {
        //     std::cout << "sprawdzam" << obraz[i] << std::endl;
        // }
    }


    virtual void draw(std::ofstream& klatka, Picture& rysunek, Sun& slonce, Plate& talerz)
    {
        rysunek.make(klatka, rysunek.getSzer(), rysunek.getWysok());
        slonce.draw(klatka);
        talerz.draw(klatka);
        closer(klatka);
        klatka.close();
    }
    
    // virtual void draw(std::ofstream& klatka, std::vector<Picture*> wekt)
    // {
    //     rysunek.make(klatka, rysunek.getSzer(), rysunek.getWysok());
    //     slonce.draw(klatka);
    //     talerz.draw(klatka);
    //     closer(klatka);
    //     klatka.close();
    // }

    void make(std::ofstream& klatka1, std::ofstream& klatka2, std::ofstream& klatka3, std::ofstream& klatka4, std::ofstream& klatka5, std::ofstream& klatka6,  Picture& rysunek, Sun& slonce, Plate& talerz)
    {        
        draw(klatka1, rysunek, slonce, talerz);  // klatka1
        draw(klatka2,rysunek, slonce, talerz);   // klatka2
        draw(klatka3,rysunek, slonce, talerz);   // klatka3
        draw(klatka4,rysunek, slonce, talerz);   // klatka4
        draw(klatka5,rysunek, slonce, talerz);   // klatka5
        draw(klatka6, rysunek, slonce, talerz);  // klatka6
    }

    // void make(std::ofstream& klatka1, std::ofstream& klatka2, std::ofstream& klatka3, std::ofstream& klatka4, std::ofstream& klatka5, std::ofstream& klatka6,  std::vector<Picture*> wek)
    // {      
    //     for(size_t i=0; i<wek.size(); i++)
    //     {  
    //     wek[i] -> draw(klatka1);
    //     wek[i] -> draw(klatka2);
    //     wek[i] -> draw(klatka3);
    //     wek[i] -> draw(klatka4);
    //     wek[i] -> draw(klatka5);
    //     wek[i] -> draw(klatka6);
    //     }        
    // }



    void doAll()
    {
        rysunek.resolutionChoice();
        std::ofstream klatka1 ("klatka1.svg");
        std::ofstream klatka2 ("klatka2.svg");
        std::ofstream klatka3 ("klatka3.svg");
        std::ofstream klatka4 ("klatka4.svg");
        std::ofstream klatka5 ("klatka5.svg");
        std::ofstream klatka6 ("klatka6.svg");

        //wektor.push_back(klatka1);
        //wektor.push_back(klatka2);
        //wektor.push_back(klatka3);
        //wektor.push_back(klatka4);
        //wektor.push_back(klatka5);
        //wektor.push_back(klatka6);

        slonce.makeSun(rysunek);
        talerz.makePlate(rysunek);
        make(klatka1, klatka2, klatka3, klatka4, klatka5, klatka6, rysunek, slonce, talerz);
        //make(klatka1, klatka2, klatka3, klatka4, klatka5, klatka6, cosRobi());
    }

    ~Animation() = default;

};

#endif