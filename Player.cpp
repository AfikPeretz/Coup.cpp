#include "Player.hpp"
#include <iostream>


namespace coup {

    Player::Player(Game game, string name, string role_name, bool isPlaying, bool isAlive){
        this -> game = game;
        this -> coin = 0;
        this -> name = name;
        this -> role_name = role_name;
        this -> isPlaying = true;
        this -> isAlive = true;
    }


    void Player::coup(Player &player){
        
    }


    void Player::income(){
        
    }

    void Player::foreign_aid(){

    }

    int Player::coins(){
        
        return this->coin;
    }

    void Player::role(){

    }
}