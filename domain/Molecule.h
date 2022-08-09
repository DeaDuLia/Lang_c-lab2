//
// Created by 1 on 29.03.2021.
//

#ifndef LAB2_TEST_MOLECULE_H
#define LAB2_TEST_MOLECULE_H
#include "Atom.h"
#include "xstring"
#include "Particle.h"

class Molecule : public  Particle{
public:
    int atomsCount = 0;
    Particle **atoms;
    string name = "";
public:
    Molecule (int atomsCount, Atom **atomss);
    ~Molecule() {
        for (int i = 0; i < atomsCount; i++) {
            delete(atoms[i]);
        }
        delete(atoms);
    }

    int getWeight () override{
        int weight = 0;
        for (int i = 0; i < atomsCount; i++) {
            weight += atoms[i]->getWeight();
        }
        return weight;
    };
    int getCharge () override{
        int charge = 0;
        for (int i = 0;i < atomsCount ;i++) {
            charge += atoms[i]->getCharge();
        }
        return charge;
    };
};


#endif //LAB2_TEST_MOLECULE_H
