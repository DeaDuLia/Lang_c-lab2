//
// Created by 1 on 28.03.2021.
//

#ifndef LAB2_TEST_ELECTRON_H
#define LAB2_TEST_ELECTRON_H
#include "ElementaryParticle.h"
#include "Particle.h"


class Electron : public ElementaryParticle {
public:
    Electron() : ElementaryParticle(0, -1) {

    }
};


#endif //LAB2_TEST_ELECTRON_H
