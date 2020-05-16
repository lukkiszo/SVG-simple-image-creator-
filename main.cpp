/* Opracowac program obiektowy, ktorego celem funkcjonalnym jest generowanie
kilku powiazanych grafik wektorowych formatu svg.

W celu generowania powiazanych grafik wektorowych nalezy wykorzystac powiazane ze soba obiekty minimum 2 roznych klas.

Uwagi:
Do generowania obrazow svg mozna uzyc swobodnie dostepnych edytorow graficznych.

Obrazy svg powinny byc maksymalnie proste np.
a) latajacy talerz, ktory pochyla sie w trakcie lotu
b) Tlo stale to np. slonce - kolko z promieniami

Podejscie takie umozliwia relatywnie prosta dekompozycje zadania na klasy, np:
a) klasa talerz (pola wspolrzedne, srednica, nachylenie)
b) klasa slonce (pola wspolrzedne odcinkow)

Main zawiaduje potencjalnymi danymi wejsciowymi i przebiegiem generacji obrazow.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "Sun.h"
#include "Plate.h"
#include "Picture.h"
#include "Animation.h"


int main()
{ 
    Animation animacja;
    animacja.doAll();   
}

/* TO DO LIST
 * 1. wprowadzic wektory
 * 2. wprowadzic obsluge wyjatkow
 * 3. polaczenie klatek w jedna animacje
 *
*/