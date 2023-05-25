#include "iostream"

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Ninja.hpp"
#include "Team.hpp"

using namespace std;

namespace ariel{


    class Team2 : public Team{

        private:


        public:

        Team2(Character*);

        void add(Character*);
        void attack(Team*);
    };
}