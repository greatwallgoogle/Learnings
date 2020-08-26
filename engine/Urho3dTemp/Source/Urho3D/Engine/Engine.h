#pragma once

class Context;

//管理所有子系统
class Engine
{
public:
    Engine(Context* pContext);
    ~Engine();

    /// Initialize engine using parameters given and show the application window. Return true if successful.
    bool Initialize();
    /// Run one frame.
    void RunFrame();
    /// Close the graphics window and set the exit flag. No-op on iOS/tvOS, as an iOS/tvOS application can not legally exit.
    void Exit();
    /// Return whether engine has been initialized.
    bool IsInitialized() const { return m_bInitialized; }
    /// Return whether exit has been requested.
    bool IsExiting() const { return m_bExiting; }
private:
    /// Initialized flag.
    bool m_bInitialized;
    /// Exiting flag.
    bool m_bExiting;
};

