//封装属性对象，比如属性类型、属性名称、相当于万能类

class Variant
{
public:
	/** 数据类型 */
	enum EType
	{
		VT_NONE = 0,
		VT_FLOAT1,       /**< 1个float */
		VT_FLOAT2,		 /**< 2个float */
		VT_FLOAT3,		 /**< 3个float */
		VT_FLOAT4,		 /**< 4个float */
		VT_BOOL,		 /**< bool类型 */
		VT_INT,		 	 /**< int类型 */
		VT_STRING,		 /**< String类型 */
		VT_USER_DATA,    /**< void*类型，用户自定义数据类型 */
		VT_NUM
	};
	
};