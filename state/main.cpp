#include<iostream>
#include"state.h"
using namespace std;


int main()
{
    State* pState = new StateA();
    Context* pContext = new Context(pState);

    enum{CNT=10};
    for (size_t i = 0; i < CNT; i++)
    {
        pContext->Request();
    }

    delete pState;
    delete pContext;
    return 0;
}

