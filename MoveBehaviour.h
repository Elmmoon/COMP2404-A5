/*The set of Behaviour Classes that control the movements of the participants.*/

#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

class MoveBehaviour{
    public:
        MoveBehaviour();
        virtual ~MoveBehaviour();
        virtual void move(int, int, int&, int&) = 0;
};

class EscapeeBehaviour : public MoveBehaviour{
    public:
        EscapeeBehaviour();
        virtual ~EscapeeBehaviour();
        virtual void move(int, int, int&, int&);
};

class RescuedBehaviour : public MoveBehaviour{
    public:
        RescuedBehaviour();
        virtual ~RescuedBehaviour();
        virtual void move(int, int, int&, int&);
};

class RescuerBehaviour : public MoveBehaviour{
    public:
        RescuerBehaviour();
        virtual ~RescuerBehaviour();
        void move(int, int, int&, int&);
};

class VillainBehaviour : public MoveBehaviour{
    public:
        VillainBehaviour();
        virtual ~VillainBehaviour();
        void move(int, int, int&, int&);
};

#endif