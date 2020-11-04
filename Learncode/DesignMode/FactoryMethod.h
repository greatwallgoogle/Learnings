#pragma once
//////////////////////////////////////////////////////////////////////////
// 工厂方法模式
//////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>

using namespace std;

namespace FactoryMethod
{
	//模拟积分兑换

	//////////////////////////////////////////////////////////////////////////
	//一坨坨代码实现.....
	enum EAwardType
	{
		EAT_NONE,
		EAT_COUPON,
		EAT_GOODS,
		EAT_TOKEN
	};

	//入参
	class AwardReq
	{
	public:
		
		AwardReq() :m_eType(EAT_NONE){}
		~AwardReq(){}

		EAwardType	GetType(){ return m_eType; }
		EAwardType	GetType() const { return m_eType; }
		void		SetType(EAwardType eType){ m_eType = eType; }
		std::string GetUID(){ return m_strUID; }
		std::string GetUID() const { return m_strUID; }
		void		SetUID(std::string strUid){ m_strUID = strUid; }
		std::string GetAwardNumber(){ return m_strAwardNum; }
		std::string GetAwardNumber() const { return m_strAwardNum; }
		void        SetAwardNumber(std::string strNumber){ m_strAwardNum = strNumber; }
		std::string GetBizId(){ return m_strBizId; }
		std::string GetBizId() const { return m_strBizId; }
		void		SetBizId(std::string strId){ m_strBizId = strId; }
	private:
		EAwardType	m_eType;
		std::string	m_strUID;
		std::string m_strAwardNum;
		std::string m_strBizId;
	};

	class IService
	{
	public:
		IService(){}
		virtual ~IService(){}
	};

	//出参
	class AwardRes
	{
	public:
		AwardRes(){}
		virtual ~AwardRes(){}
		void	SetResultLog(const std::string & strLog){ m_strLog = strLog; }
	private:
		std::string m_strLog;
	};

	//////////////////////////////////////////////////////////////////////////
	//优惠券
	class Coupon : public AwardRes
	{
	public:
		Coupon(){}
		~Coupon(){}
	private:

	};

	class CouponResult
	{
	public:
		bool	GetCode(){ return true; }
	};

	class CouponService : public IService
	{
	public:
		CouponService() :IService(){}
		CouponResult SendCoupon(const std::string strUid, const std::string strCouponId, const std::string strUUID)
		{
			CouponResult res;
			return res;
		}
	};

	//////////////////////////////////////////////////////////////////////////
	//实物
	class Goods : public AwardRes
	{
	public:
		Goods(){}
		~Goods(){}
	private:

	};

	class DeliverReq
	{
	public:
		DeliverReq(){}
		~DeliverReq(){}
		void setUserName(std::string strName){}
		void setUserPhone(std::string strPhoneNum){}
		void setSku(){}
		void setSku(std::string strContent){}
		void setOrderId(std::string strContent){}
	private:

	};

	class GoodsService : public IService
	{
	public:
		GoodsService() :IService(){}
		bool DeliverGoods(DeliverReq req)
		{
			return false;
		}
	};
	//////////////////////////////////////////////////////////////////////////
	//爱奇艺兑换卡
	class IQIYIToken : public AwardRes
	{
	public:
		IQIYIToken(){}
		~IQIYIToken(){}
	private:

	};
	class IQIYITokenService : public IService
	{
	public:
		IQIYITokenService() :IService(){}
		bool GrantToken(std::string strMobileNum,std::string strCardId)
		{
			return false;
		}
	};
	//////////////////////////////////////////////////////////////////////////
	//逻辑处理
	class PrizeController
	{
	public:
		PrizeController(){}
		~PrizeController(){}

		AwardRes* AwardToUser(const AwardReq& awardReq)
		{
			AwardRes* pRes = nullptr;
			switch (awardReq.GetType())
			{
			case EAT_COUPON:
			{
				pRes = new Coupon();
				CouponService* pSer = new CouponService();
				CouponResult res = pSer->SendCoupon(awardReq.GetUID(), awardReq.GetAwardNumber(), awardReq.GetBizId());
				pRes->SetResultLog(res.GetCode() ? "Successd!" : "Failded!");
				delete pSer;
			}
				break;
			case EAT_GOODS:
			{
				pRes = new Goods();
				GoodsService* pSer = new GoodsService();
				DeliverReq deliverReq;
				deliverReq.setUserName(queryUserName(awardReq.GetUID()));
				deliverReq.setUserPhone(queryUserPhoneNumber(awardReq.GetUID()));
				deliverReq.setSku(awardReq.GetAwardNumber());
				deliverReq.setOrderId(awardReq.GetBizId());
				bool bRet = pSer->DeliverGoods(deliverReq);
				pRes->SetResultLog(bRet ? "Successd!" : "Failded!");
				delete pSer;
			}
				break;
			case EAT_TOKEN:
				pRes = new IQIYIToken();
				IQIYITokenService* pSer = new IQIYITokenService();
				pSer->GrantToken(queryUserPhoneNumber(awardReq.GetUID()), awardReq.GetAwardNumber());
				pRes->SetResultLog("Successd!");
				delete pSer;
				break;
			default:
				break;
			}
			return pRes;
		}


		std::string queryUserName(std::string uid)
		{
			return "Test";
		}
		std::string queryUserPhoneNumber(std::string uid)
		{
			return "15078915602";
		}
	};


	//////////////////////////////////////////////////////////////////////////
	//工厂方法模式

	class Variant
	{
	public:
		Variant(){}
		~Variant(){}

	};

	class IServiceFactory
	{
	public:
		IServiceFactory(){}
		virtual ~IServiceFactory(){}
		virtual void SendCommodity(std::string strUid, std::string strCommodityId, std::string strBizId, Variant& var) = 0;
		EAwardType	GetType(){ return AWAER_TYPE; }
	public:
		static EAwardType AWAER_TYPE;
	};

	FactoryMethod::EAwardType IServiceFactory::AWAER_TYPE = EAT_NONE;

	class CouponServiceFactory : public IServiceFactory
	{
	public:
		CouponServiceFactory(){}
		virtual ~CouponServiceFactory(){}
		virtual void SendCommodity(std::string strUid, std::string strCommodityId, std::string strBizId, Variant& var)override
		{
			//处理逻辑
		}
		EAwardType	GetType(){ return AWAER_TYPE; }
	public:
		static EAwardType AWAER_TYPE;
	};

	FactoryMethod::EAwardType CouponServiceFactory::AWAER_TYPE = EAT_COUPON;

	class GoodsServiceFactory : public IServiceFactory
	{
	public:
		GoodsServiceFactory(){}
		virtual ~GoodsServiceFactory(){}
		virtual void SendCommodity(std::string strUid, std::string strCommodityId, std::string strBizId, Variant& var)override
		{
			//处理逻辑
		}
		EAwardType	GetType(){ return AWAER_TYPE; }
	public:
		static EAwardType AWAER_TYPE;
	};
	FactoryMethod::EAwardType GoodsServiceFactory::AWAER_TYPE = EAT_GOODS;

	class IQIYITokenServiceFactory : public IServiceFactory
	{
	public:
		IQIYITokenServiceFactory(){}
		virtual ~IQIYITokenServiceFactory(){}
		virtual void SendCommodity(std::string strUid, std::string strCommodityId, std::string strBizId, Variant& var)override
		{
			//处理逻辑
		}
		EAwardType	GetType(){ return AWAER_TYPE; }
	public:
		static EAwardType AWAER_TYPE;
	};

	FactoryMethod::EAwardType IQIYITokenServiceFactory::AWAER_TYPE = EAT_TOKEN;

	class ServiceFactoryManager
	{
	public:
		template <class T>
		void Register()
		{
			T* pFty = new T();
			m_aFactorys.push_back(pFty);
		}
		void CollectFactory()
		{
			Register<CouponServiceFactory>();
			Register<GoodsServiceFactory>();
			Register<IQIYITokenServiceFactory>();
		}

		void ReleaseFactory()
		{
			for (int i = 0; i < m_aFactorys.size();i++)
			{
				delete m_aFactorys[i];
			}
			m_aFactorys.clear();
		}
		IServiceFactory* GetServiceFactory(EAwardType eType)
		{
			for (IServiceFactory* pFacty : m_aFactorys)
			{
				if (pFacty->GetType() == eType)
					return pFacty;
			}
			return NULL;
		}
	protected:
		vector<IServiceFactory*> m_aFactorys;
	};
};