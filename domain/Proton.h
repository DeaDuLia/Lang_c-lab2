//
// Created by 1 on 28.03.2021.
//

#ifndef LAB2_TEST_PROTON_H
#define LAB2_TEST_PROTON_H
#include "ElementaryParticle.h"
#include "Particle.h"

class Proton : public ElementaryParticle  {
public:
    Proton() : ElementaryParticle(1, 1) {}
};


#endif //LAB2_TEST_PROTON_H
