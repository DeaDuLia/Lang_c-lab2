//
// Created by 1 on 28.03.2021.
//

#ifndef LAB2_TEST_NEUTRON_H
#define LAB2_TEST_NEUTRON_H
#include "ElementaryParticle.h"
#include "Particle.h"

class Neutron : public ElementaryParticle {
public:
    Neutron() : ElementaryParticle(1, 0) {

    }
};

#endif //LAB2_TEST_NEUTRON_H
