#pragma once
//封装属性对象，比如属性类型、属性名称、相当于万能类

class Variant
{
public:
	/** 数据类型 */
	enum EType
	{
		ET_NONE = 0,
		ET_FLOAT1,       /**< 1个float */
		ET_FLOAT2,		 /**< 2个float */
		ET_FLOAT3,		 /**< 3个float */
		ET_FLOAT4,		 /**< 4个float */
		ET_BOOL,		 /**< bool类型 */
		ET_INT,		 	 /**< int类型 */
		ET_STRING,		 /**< String类型 */
		ET_USER_DATA,    /**< void*类型，自定义数据类型 */
		ET_NUM
	};
	
};