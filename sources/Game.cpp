#include "Game.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Player.hpp"



namespace coup {



    Game::Game() {
        gameRuning = false;
        TheWinner = "";
        curPlayer = 0;
        size_t size = roles.size();
        for (string role : roleList){
            pair<string, vector<Player* >> pair = {role, vector<Player* >()};
            if (size >= MaxPlayers){
                throw invalid_argument("too many players");
            }
            roles.insert(pair);
        }
    }



    string Game::turn(){
        string s = this -> playerList.at(this -> curPlayer) -> name;
        return s;
    }


    void Game::endTurn(){
    size_t playerLIstSize = this -> playerList.size();
    if ( playerLIstSize <=  MinPlayers || playerLIstSize >=  MaxPlayers){
        throw invalid_argument("The number of players does not match the requirements");
    }
    this -> gameRuning = true;
    this -> curPlayer = (this -> curPlayer + 1) % playerLIstSize;
    while (this -> playerList.at(this -> curPlayer) -> isPlaying == false){
        this -> curPlayer = (this -> curPlayer + 1) % playerLIstSize;
    }
    this->removePCBB();
    Player &cp = *this->playerList.at(this->curPlayer);
    size_t x = 0;
    if (cp.roleName == "Assassin" || cp.roleName == "Captain"){
        if (cp.roleName == "Assassin"){
            Assassin &assassin = dynamic_cast<Assassin &>(cp);
            x++;
            assassin.sCoup = nullptr;
        }
        if (cp.roleName == "Captain"){
            Captain &captain = dynamic_cast<Captain &>(cp);
            x--;
            captain.bS = nullptr;
        }
    }
}


    string Game::winner(){
        int count = 0;
        for (Player *p : this -> playerList){
            if (p -> dead() == true){
                count++;
            }
        }
        if (count != 1){
            throw invalid_argument("the game is not over yet");
        }
        else{
            for (Player *p : this->playerList){
                if (p -> dead() == false){
                    TheWinner = p -> name;
                    return TheWinner;
                }
            }
        } 
    }


    vector<string> Game::players(){
        vector<string> PlayerNames;
        for (Player *player : this -> playerList){
            if (player -> dead() == false){
                PlayerNames.push_back(player -> name);
            }
        }
        return PlayerNames;
    }


    void Game::addPlayer(Player &p){
        size_t size = this->playerList.size();
        p.playerNumber = size;
        if (size > MaxPlayers || gameRuning == false){
            throw invalid_argument("can not add players");
        }
        this->playerList.push_back(&p);
        //this->roles.at(p.roleName).push_back(&p);
    }


    void Game::addB(Player* p, const string &a){
        this -> roles.at(a).push_back(p);
    }


    bool Game::blockPosibly(Player &p, const string &mr){
        vector<Player *> &pp = this -> roles.at(mr);
        bool ans = true;
        size_t i = 0;
        for (Player *pl : pp){
            if (pl->name == p.name){
                pp.erase(pp.begin() + i);
                return ans;
            }
            i++;
        }
        return !ans;
    }

    void Game::removePCBB(){
        size_t x = 6;
        Player *pl = this -> playerList.at(this -> curPlayer);
        for (auto &pair : this -> roles){
            x++;
            size_t i = 0;
            vector<coup::Player* > &pr = this -> roles.at(pair.first);
            for (Player *ppl : pr){
                if (ppl -> name == pl -> name){
                    x--;
                    pr.erase(pr.begin() + i);
                }
                i++;
                x++;
            }
        }

    }


}