#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string coup::Game::turn(){
    string s = this->listOfPlayer.at(this->cur_p)->name;
    return s;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Game::addParticipants(coup::Player &p){
    bool a = false;
    size_t x = 0;
    if (this->isthegamestart == a && this->listOfPlayer.size() < maximumParticipants){
        this->listOfPlayer.push_back(&p);
        x++;
    }
    else{
        x++;
        throw runtime_error("Participants list is full");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> coup::Game::players(){
    vector<string> n;
    size_t x = 0;
    for (coup::Player *p : this -> listOfPlayer){
        if (p -> iStilNotDead()){
            x++;
            n.push_back(p -> name);
            x--;
        }
        x++;
    }
    return n;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool coup::Game::Blockable(coup::Player &pb, const string &mr){
    vector<coup::Player *> &pp = this->blockmap.at(mr);
    bool ans = true;
    long l = 0;
    for (const coup::Player *p : pp){
        if (p -> name == pb.name){
            pp.erase(pp.begin() + l);
            return ans;
        }
        l++;
    }

    return !ans;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Game::endThisTurn(){
    size_t size = this -> listOfPlayer.size();
    if (size == 0 || size == 1){
        throw "need more Participants";
    }
    bool ans = true;
    if (!this->isthegamestart){
        this->isthegamestart = ans;
    }
    else if (this -> bts){
        this-> bts = !ans;
    }
    this -> cur_p = (this -> cur_p + 1) % size;
    while (!this -> listOfPlayer.at(this->cur_p) -> isPlaying){
        this -> cur_p = (this -> cur_p + 1) % size;
    }
    this->rbpfl();
    coup::Player &cp = *this -> listOfPlayer.at(this->cur_p);
    if (cp.roleName == "Assassin" || cp.roleName == "Captain"){
        if (cp.roleName == "Assassin"){
        coup::Assassin &assassin = dynamic_cast<Assassin &> (cp);
        assassin.sc = nullptr;
        }
        else if (cp.roleName == "Captain")
        {
        coup::Captain &captain = dynamic_cast<Captain &> (cp);
        captain.stf= nullptr;
        }
    }
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string coup::Game::winner(){
    size_t size = this->listOfPlayer.size();
    size_t cnt = 0;
    string wn;
    if (size < 1 || size == 1){
        throw "need more Participants";
    }
    for (coup::Player *p : this->listOfPlayer){
        if (p -> isPlaying){
            cnt++;
            wn = p -> name;
        }
    }
    size_t x = 0;
    if (cnt != 1){
        throw "too many Participants";
    }
    x++;
    return wn;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Game::insertToBlockableList(coup::Player *p, const string &br){
    size_t x = 0;
    this -> blockmap.at(br).push_back(p);
    x++;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Game::rbpfl(){
    coup::Player *p = this -> listOfPlayer.at(this -> cur_p);
    for (auto &couple : this -> blockmap){
        long x = 0;
        vector<coup::Player *> &pbr = this -> blockmap.at(couple.first);
        long l = 0;
        for (coup::Player *pp : pbr){
            if (pp -> name == p -> name){
                x++;
                pbr.erase(pbr.begin() + l);
            }
            l++;
            x++;
        }
    }
}


