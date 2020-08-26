#include "RefCounted.h"

RefCounted::RefCounted()
: m_nRef(0)
{
}

RefCounted::~RefCounted()
{
    assert(m_nRef == 0);
    m_nRef = -1;
}

void RefCounted::AddRef()
{
    m_nRef++;
}

void RefCounted::ReleaseRef()
{
    m_nRef--;
    if (m_nRef == 0)
    {
        delete this;
    }
    
}

int RefCounted::GetRefCount()const
{
    return m_nRef;
}