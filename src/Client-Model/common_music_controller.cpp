#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "common_music_controller.h"


using namespace sf;

MusicController::MusicController(){
    attack.openFromFile("resources/sounds/attack.mp3");
    predifine1.openFromFile("resources/sounds/neutral.mp3");
    predifine2.openFromFile("resources/sounds/neutral2.mp3");
    this->is_attacking = false;
}

void MusicController::reproduceAttacking(){
    if(!is_attacking){
        predifine1.stop();
        predifine2.stop();
        attack.play();
        is_attacking = true;
    }
}

void MusicController::reproducePredifine(){
    if(is_attacking){
        is_attacking = false;
        attack.stop();
    } else {
        if(Music::Status::Stopped == predifine1.getStatus()){
            predifine2.play();
        } else {
            predifine2.play();
        }
    }
}