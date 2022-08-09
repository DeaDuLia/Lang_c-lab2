//
// Created by 1 on 30.03.2021.
//

#ifndef LAB2_TEST_ELEMENTARYPARTICLE_H
#define LAB2_TEST_ELEMENTARYPARTICLE_H
#include "Particle.h"

class ElementaryParticle{
private:
    int weight = 0;
    int charge = 0;
public:
    ElementaryParticle () {
        this->weight = 0;
        this->charge = 0;
    }
    ElementaryParticle (int weight, int charge = 1) {
        this->weight = weight;
        this->charge = charge;
    }
    virtual int getWeight ();
    virtual int getCharge ();
};


#endif //LAB2_TEST_ELEMENTARYPARTICLE_H
