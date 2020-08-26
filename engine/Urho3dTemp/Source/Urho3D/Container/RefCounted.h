#pragma once

class RefCounted
{
public:
                RefCounted();
    virtual     ~RefCounted();
    /// Prevent copy construction.
    RefCounted(const RefCounted& rhs) = delete;
    /// Prevent assignment.
    RefCounted& operator =(const RefCounted& rhs) = delete;
    /// Increment reference count. 
    void        AddRef();
    /// Decrement reference count and delete self if no more references.
    void        ReleaseRef();
    /// Return reference count.
    int         GetRefCount() const;
private:
    /// Reference count. If below zero, the object has been destroyed.
    int         m_nRef;
};

