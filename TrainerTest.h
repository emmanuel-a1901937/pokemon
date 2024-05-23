#ifndef TRAINERTEST_H
#define TRAINERTEST_H

#include "Trainer.h"

class TrainerTest{
    private:
        Trainer trainer;
    public:
        void testAddPokemon();
        void testReplacePokemon();
        void testSetActivePokemon();
        void testPartyFainted();
};


#endif