//
// Created by 1 on 29.03.2021.
//

#include "Atom.h"
Atom::Atom (int protonCount, int neutronCount, int electronCount, string name) {
    particleCount = protonCount + neutronCount + electronCount;
    particles = new ElementaryParticle*[particleCount];
    int ind = 0;
    for (int i = 0; i < protonCount ; i++, ind++) {
        Proton * prtn = new Proton();
        particles[ind] = prtn;
    }
    for (int i = 0; i < neutronCount ; i++, ind++) {
        particles[ind] = new Neutron();

    }
    for (int i = 0; i < electronCount; i++, ind++) {
        particles[ind] = new Electron();
    }
    this->protonCount = protonCount;
    this->neutronCount = neutronCount;
    this->electronCount = electronCount;
    this->name = name;
}
