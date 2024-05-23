#ifndef TRAINERTEST_H
#define TRAINERTEST_H

#include "Trainer.h"

class TrainerTest{
    private:
        Trainer trainer;
    public:
        void testAddPokemon(); // Tests adding Pokemon to Trainer's Pokemon* vector 
        void testReplacePokemon(); // Tests removing and replacing a Pokemon in Trainer's Pokemon* vector 
        void testSetActivePokemon(); // Tests setting the Trainer's activePokemon attribute 
        void testPartyFainted(); // Tests partyFainted function in Trainer class works as expected
};


#endif