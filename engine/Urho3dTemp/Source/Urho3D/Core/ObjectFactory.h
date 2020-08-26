#pragma once

#include "RefCounted.h"

class Context;

/// Base class for object factories.
class ObjectFactory 
    :public RefCounted
{
public:
    ObjectFactory(Context* pContext);
    ~ObjectFactory();

private:
    /// Execution context.
    Context*        m_pContext;
};

