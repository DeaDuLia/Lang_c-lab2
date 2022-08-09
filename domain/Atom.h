//
// Created by 1 on 29.03.2021.
//

#ifndef LAB2_TEST_ATOM_H
#define LAB2_TEST_ATOM_H

#include <xstring>
#include "Particle.h"
#include "Proton.h"
#include "Neutron.h"
#include "Electron.h"
using namespace std;

class Atom :  public Particle{
private:
    string name;
    int protonCount = 0;
    int neutronCount = 0;
    int electronCount = 0;
    int particleCount = 0;
    ElementaryParticle **particles;
public:
    Atom (int protonCount, int neutronCount, int electronCount, string name);
    ~Atom(){
        for (int i = 0; i < particleCount; i++) {
            delete(particles[i]);
        }
        delete(particles);
    };
    string getName () {
        return this->name;
    }
    int getProtonCount () {
        return this->protonCount;
    }
    int getNeutronCount () {
        return this->neutronCount;
    }
    int getElectronCount () {
        return this->electronCount;
    }
    int getWeight () override{
        int weight = 0;
        for (int i = 0; i < particleCount ;i++) {
            weight += particles[i]->getWeight();
        }
        return weight;
    };
    int getCharge () override {
        int charge = 0;
        for (int i = 0;i < particleCount ;i++) {
            charge += particles[i]->getCharge();
        }
        return charge;
    };
};


#endif //LAB2_TEST_ATOM_H
