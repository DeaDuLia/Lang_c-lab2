//
// Created by 1 on 29.03.2021.
//

#include "Molecule.h"
Molecule::Molecule(int atomsCount, Atom **atomss) {
    this->atomsCount = atomsCount;
    atoms = new Particle*[atomsCount];
    for (int i = 0; i < atomsCount; i++) {
        int prtn = atomss[i]->getProtonCount();
        int ntrn = atomss[i]->getNeutronCount();
        int elctr = atomss[i]->getElectronCount();
        atoms[i] = new Atom(prtn, ntrn , elctr, name);
        name = name + atomss[i]->getName();
    }
}
