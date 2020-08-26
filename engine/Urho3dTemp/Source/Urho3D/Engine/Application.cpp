#include "Application.h"
#include "Engine.h"

Application::Application(Context* pContext)
{
    m_pEngine = new Engine(pContext);
}

Application::~Application()
{

}

int Application::Run()
{
    Setup();
    if(m_pEngine->Initialize())
    {
        return 1;
    }
    Start();
    while (!m_pEngine->IsExiting())
    {
        m_pEngine->RunFrame();
    }
    Stop();
    return 0;
}