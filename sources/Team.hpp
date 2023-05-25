#pragma once
#include "iostream"
#include <vector>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel{


    class Team{

        private:
            Character* leader;
            vector<Character*> myTeam;

        public:

        Team(Character*);

        void add(Character*);
        int stillAlive();
        void attack(Team*);
        void print();

        void setTeamMembers(vector<Character*> team){
            myTeam = team;
        }

        vector<Character*> getTeamMembers(){
            return myTeam;
        }

        ~Team();
    };
}