                  //
// Created by tomasw on 7/26/18.
//

#include "Hand.h"

int Stone::play(Hand &v) {
    v.playWithStone(*this);
}
int Stone::playWithStone(Stone &v){
    return 0;
}
int Stone::playWithPaper(Paper &paper){
    return 1;
}
int Stone::playWithScissor(Scissor &scissor){
    return -1;
}
int Stone::playWithSpock(Spock &spock){
    return 1;
}
int Stone::playWithLizard(Lizard &lizard){
    return -1;
}

int Paper::play(Hand &v){
    v.playWithPaper(*this);
}
int Paper::playWithStone(Stone &v){
    return -1;
}
int Paper::playWithPaper(Paper &paper){
    return 0;
}
int Paper::playWithScissor(Scissor &scissor){
    return 1;
}
int Paper::playWithSpock(Spock &spock){
    return -1;
}
int Paper::playWithLizard(Lizard &lizard){
    return 1;
}

int Scissor::play(Hand &v){
    v.playWithScissor(*this);
}
int Scissor::playWithStone(Stone &v){
    return 1;
}
int Scissor::playWithPaper(Paper &paper){
    return -1;
}
int Scissor::playWithScissor(Scissor &scissor){
    return 0;
}
int Scissor::playWithSpock(Spock &spock){
    return 1;
}
int Scissor::playWithLizard(Lizard &lizard){
    return -1;
}


int Spock::play(Hand &v){
    v.playWithSpock(*this);
}
int Spock::playWithStone(Stone &v){
    return -1;
}
int Spock::playWithPaper(Paper &paper){
    return 1;
}
int Spock::playWithScissor(Scissor &scissor){
    return -1;
}
int Spock::playWithSpock(Spock &spock){
    return 0;
}
int Spock::playWithLizard(Lizard &lizard){
    return 1;
}

int Lizard::play(Hand &v){
    v.playWithLizard(*this);
}
int Lizard::playWithStone(Stone &v){
    return 1;
}
int Lizard::playWithPaper(Paper &paper){
    return -1;
}
int Lizard::playWithScissor(Scissor &scissor){
    return 1;
}
int Lizard::playWithSpock(Spock &spock){
    return -1;
}
int Lizard::playWithLizard(Lizard &lizard){
    return 0;
}
