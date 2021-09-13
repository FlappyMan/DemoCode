#ifndef STATE_H_
#define STATE_H_


#include<iostream>

class State;
//Context类要维护一个具体state类的实例，这个实例保存当前的状态
//状态管理类
class Context{
private:
    State* state;
public:
    Context(State* state):state(state){};
    //获取当前状态
    void Request();
    //改变当前状态
    void ChangeState(State* state);
};


//抽象状态类
class State{
public:
    virtual void handle(Context* pContext) = 0;
    virtual ~State() = default;
protected:
    State(){}
};

class StateA : public State{
public:
    StateA(){};
    ~StateA() = default;
    virtual void handle(Context* pContext);
};

class StateB : public State{
public:
    StateB(){};
    ~StateB() = default;
    virtual void handle(Context* pContext);
};

class StateC : public State{
public:
    StateC(){};
    ~StateC() = default;
    virtual void handle(Context* pContext);
};

#endif

