#include "TypeInfo.h"

TypeInfo::TypeInfo(const char* szTypeName,const TypeInfo* pBaseInfo)
    : m_strType(szTypeName)
    , m_strTypeName(szTypeName)
    , m_pBaseTypeInfo(pBaseInfo)
{

}

bool TypeInfo::IsType(const char* szType)
{
    const TypeInfo* pCurrent = this;
    while (NULL != pCurrent)
    {
        if(pCurrent->GetType().c_str() == szType)
        {
            return true;
        }
        pCurrent = pCurrent->GetBaseTypeInfo();
    }
    return false;
}

bool TypeInfo::IsType(const TypeInfo* pTypeInfo)
{
    const TypeInfo* pCurrent = this;
    while (NULL != pCurrent)
    {
        if(pCurrent == pTypeInfo)
        {
            return true;
        }
        pCurrent = pCurrent->GetBaseTypeInfo();
    }
    return false;
}