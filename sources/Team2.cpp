#include "Team2.hpp"

namespace ariel{

    Team2::Team2(Character* leader):Team(leader){}

    void Team2::add(Character* new_teammate){
        if(new_teammate == nullptr){
            throw std::runtime_error("Teammate cannot be null");
        }
        else if(getTeamMembers().size() >= 10){
            throw std::runtime_error("Team is full");
        }
        else if(new_teammate->getAlreadyInTeam()){
            throw std::runtime_error("Teammate is already in a team");
        }
        else{
            vector new_team = getTeamMembers();
            new_team.push_back(new_teammate);
            new_teammate->setAlreadyInTeam(true);
            setTeamMembers(new_team);
        }
    }

    void Team2::attack(Team* team){
        
    }
    
}