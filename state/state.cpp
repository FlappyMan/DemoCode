#include "state.h"

void Context::Request()
{
    state->handle(this);
}

void Context::ChangeState(State* state)
{
    this->state = state;
}

void StateA::handle(Context* pContext)
{
    std::cout << "StateA";
    std::cout << " 改变状态为B " << std::endl;
    pContext->ChangeState(new StateB());
}

void StateB::handle(Context* pContext)
//执行该状态的行为并改变状态
{
    std::cout << "StateB";
    std::cout << " 改变状态为C " << std::endl;
    pContext->ChangeState(new StateC());
}

void StateC::handle(Context* pContext)
{
    std::cout << "StateC";
    std::cout << " 改变状态为A " << std::endl;
    pContext->ChangeState(new StateA());
}
