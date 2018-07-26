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
    int play(Hand &v);
    int playWithStone(Stone &v);
    int playWithPaper(Paper &paper);
    int playWithScissor(Scissor &scissor);
    int playWithSpock(Spock &spock);
    int playWithLizard(Lizard &lizard);
};

class Paper : public Hand {
public:
    Paper() = default;
    int play(Hand &v);
    int playWithStone(Stone &v);
    int playWithPaper(Paper &paper);
    int playWithScissor(Scissor &scissor);
    int playWithSpock(Spock &spock);
    int playWithLizard(Lizard &lizard);
};

class Scissor : public Hand {
public:
    Scissor() = default;
    int play(Hand &v);
    int playWithStone(Stone &v);
    int playWithPaper(Paper &paper);
    int playWithScissor(Scissor &scissor);
    int playWithSpock(Spock &spock);
    int playWithLizard(Lizard &lizard);
};

class Spock : public Hand {
public:
    Spock() = default;
    int play(Hand &v);
    int playWithStone(Stone &v);
    int playWithPaper(Paper &paper);
    int playWithScissor(Scissor &scissor);
    int playWithSpock(Spock &spock);
    int playWithLizard(Lizard &lizard);
};

class Lizard: public Hand {
public:
    Lizard() = default;
    int play(Hand &v);
    int playWithStone(Stone &v);
    int playWithPaper(Paper &paper);
    int playWithScissor(Scissor &scissor);
    int playWithSpock(Spock &spock);
    int playWithLizard(Lizard &lizard);
};


#endif //CPP_HAND_H
