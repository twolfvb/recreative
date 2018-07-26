//
// Created by tomasw on 7/26/18.
//

#ifndef CPP_HAND_H
#define CPP_HAND_H
class Stone;
class Paper;
class Scissor;
class Spock;
class Lizard;

class Hand {
public:
    virtual int play(Hand &v) = 0;
    virtual int playWithStone(Stone &stone) = 0;
    virtual int playWithPaper(Paper &paper) = 0;
    virtual int playWithScissor(Scissor &scissor) = 0;
    virtual int playWithSpock(Spock &spock) = 0;
    virtual int playWithLizard(Lizard &lizard) = 0;
};

class Stone : public Hand {
public:
    Stone() = default;
    int play(Hand &v){
        v.playWithStone(*this);
    }
    int playWithStone(Stone &v){
        return 0;
    }
    int playWithPaper(Paper &paper){
        return 1;
    }
    int playWithScissor(Scissor &scissor) {
        return -1;
    }
    int playWithSpock(Spock &spock){
        return 1;
    }
    int playWithLizard(Lizard &lizard){
        return -1;
    }
};

class Paper : public Hand {
public:
    Paper() = default;
    int play(Hand &v){
        v.playWithPaper(*this);
    }
    int playWithStone(Stone &v){
        return -1;
    }
    int playWithPaper(Paper &paper){
        return 0;
    }
    int playWithScissor(Scissor &scissor){
        return 1;
    }
    int playWithSpock(Spock &spock){
        return -1;
    }
    int playWithLizard(Lizard &lizard){
        return 1;
    }
};

class Scissor : public Hand {
public:
    Scissor() = default;
    int play(Hand &v){
        v.playWithScissor(*this);
    }
    int playWithStone(Stone &v){
        return 1;
    }
    int playWithPaper(Paper &paper){
        return -1;
    }
    int playWithScissor(Scissor &scissor){
        return 0;
    }
    int playWithSpock(Spock &spock){
        return 1;
    }
    int playWithLizard(Lizard &lizard){
        return -1;
    }
};

class Spock : public Hand {
public:
    Spock() = default;
    int play(Hand &v){
        v.playWithSpock(*this);
    }
    int playWithStone(Stone &v){
        return -1;
    }
    int playWithPaper(Paper &paper){
        return 1;
    }
    int playWithScissor(Scissor &scissor){
        return -1;
    }
    int playWithSpock(Spock &spock){
        return 0;
    }
    int playWithLizard(Lizard &lizard){
        return 1;
    }
};

class Lizard: public Hand {
public:
    Lizard() = default;
    int play(Hand &v){
        v.playWithLizard(*this);
    }
    int playWithStone(Stone &v){
        return 1;
    }
    int playWithPaper(Paper &paper){
        return -1;
    }
    int playWithScissor(Scissor &scissor){
        return 1;
    }
    int playWithSpock(Spock &spock){
        return -1;
    }
    int playWithLizard(Lizard &lizard){
        return 0;
    }
};


#endif //CPP_HAND_H
