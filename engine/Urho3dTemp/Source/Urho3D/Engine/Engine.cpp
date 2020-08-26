#include "Engine.h"
#include "Context.h"

Engine::Engine(Context* pContext)
: m_bInitialized(false)
, m_bExiting(false)
{

}

Engine::~Engine()
{

}

bool Engine::Initialize()
{
    if(m_bInitialized)
    {
        return true;
    }
}

void Engine::RunFrame()
{

}

void Engine::Exit()
{
    
}