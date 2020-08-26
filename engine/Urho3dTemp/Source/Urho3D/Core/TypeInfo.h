#pragma once
#include <string>

class TypeInfo
{
public:
    TypeInfo(const char* szTypeName,const TypeInfo* pBaseInfo);
    bool                 IsType(const char* szType);
    bool                 IsType(const TypeInfo* pTypeInfo);
    std::string          GetType() const {return m_strType;}
    std::string          GetTypeName() const {return m_strTypeName;}
    const TypeInfo*      GetBaseTypeInfo() const {return m_pBaseTypeInfo;}
private:
    std::string          m_strType;
    std::string          m_strTypeName;
    const TypeInfo*      m_pBaseTypeInfo;
};

