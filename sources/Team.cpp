#include "Team.hpp"

namespace ariel{

    Team::Team(Character* leader):leader(leader){
        add(leader);
    }

    void Team::add(Character* new_teammate) {
        // Check if the new teammate is null. If so, throw an exception.
        if(new_teammate == nullptr) {
            throw std::runtime_error("Teammate cannot be null");
        }
        // Check if the team is already full (10 characters). If so, throw an exception.
        else if(myTeam.size() >= 10) {
            throw std::runtime_error("Team is full");
        }
        // Check if the new teammate is already in a team. If so, throw an exception.
        else if(new_teammate->getAlreadyInTeam()) {
            throw std::runtime_error("Teammate is already in a team");
        }
        else {
            // Add the new teammate to the team and mark the teammate as being in a team.
            myTeam.push_back(new_teammate);
            new_teammate->setAlreadyInTeam(true);

            // Create a new sorted team vector.
            vector<Character *> sorted_team;

            // First, add all Cowboy characters to the sorted team.
            for (Character* c : myTeam) {
                if (Cowboy* cowboy = dynamic_cast<Cowboy*>(c)) {
                    sorted_team.push_back(cowboy);
                }
            }
            // Then, add all Ninja characters to the sorted team.
            for (Character* c : myTeam) {
                if (Ninja* ninja = dynamic_cast<Ninja*>(c)) {
                    sorted_team.push_back(ninja);
                }
            }

            // Replace the old team with the sorted team.
            myTeam = sorted_team;
        }
    }   


    int Team::stillAlive(){
        int counter = 0;
        for(Character* c: myTeam){
            if(c->isAlive()){
                counter++;
            }
        }
        return counter;
    }


    void Team::attack(Team* other){
        double minDist = std::numeric_limits<double>::max();
        if(other == nullptr){
            throw std::invalid_argument("Team cannot be null");
        }
        else if(!stillAlive() || !other->stillAlive()){
            throw std::runtime_error("Team is dead");
        }
        //handle with non leader case
        else if(!leader->isAlive()){
            //Find a new leader
            for(Character* c : myTeam){
                double currDist = leader->distance(c);
                if(c->isAlive() && currDist < minDist){
                    leader = c;
                    minDist = currDist;
                }
            }
        }

        // choose victim
        minDist = std::numeric_limits<double>::max();
        Character* victim = nullptr;
        
        for(Character* c : other->myTeam){
            if(c->isAlive()){
                double distance = leader->distance(c);
                if(distance < minDist){
                    minDist = distance;
                    victim = c;
                }
            }
        }

        //get alive team members
        vector<Character*> aliveMembers;
        for(Character* c : myTeam){
            if(c->isAlive()){
                aliveMembers.push_back(c);
            }
        }

        //per member: hit victim
        for(Character* c : aliveMembers){
            if (victim->isAlive()){
                c->attack(victim);

            }
        
        }

        
        if(victim != nullptr){
            leader->attack(victim);
        }
        // continue to attack the victim who is closest to our leader
    }


    void Team::print(){
        for(Character* c : myTeam){
            cout << c->print() << endl;
        }
    }

    Team::~Team(){
        for (Character* c : myTeam) {
            delete c;
        }
    }
}