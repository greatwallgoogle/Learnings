#include <iostream>
using namespace std;

//简单工厂模式，实现一个创建对象的函数，根据指定的类型或参数创建匹配的对象。
//简单工厂模式下，工厂类比较复杂，当增加具体产品类时，同时要改动工厂类的创建函数，不符合开闭原则。

class Button
{
public :
    Button(){}
    virtual ~Button(){}
    virtual void UpdateShape() = 0;
public:
    static string BtnType;
};

string Button::BtnType = "Button";

//-----------------------------------------
class CircleBtn : public Button
{
public :
    CircleBtn(){}
    virtual void UpdateShape()
    {
        cout <<"CircleBtn::UpdateShape: "<<BtnType<<endl;
    }
public:
    static string BtnType;
};
string CircleBtn::BtnType = "CircleBtn";
//-----------------------------------------
class RectBtn: public Button
{
public :
    RectBtn(){}
    virtual void UpdateShape()
    {
        cout <<"RectBtn::UpdateShape: "<<BtnType<<endl;
    }
public:
    static string BtnType;
};
string RectBtn::BtnType = "RectBtn";
//-----------------------------------------

//factory
class BtnFactory
{
public :
    BtnFactory(){}
    ~BtnFactory(){}
    static BtnFactory* CreateBtnFactory()
    {
        return new BtnFactory();
    }
    static void DestoryBtnFactory(BtnFactory*& pFactory)
    {
        if(pFactory)
        {
            delete pFactory;
            pFactory = NULL;
        }
    }
    Button* CreateButton(const char* szType)
    {
        if(NULL == szType)
        {
            return NULL;
        }
        if(CircleBtn::BtnType == szType)
        {
            return new CircleBtn();
        }
        else if(RectBtn::BtnType == szType)
        {
            return new RectBtn();
        }
        return NULL;
    }
};

int main()
{
    cout<<"hello world.."<<endl;
    BtnFactory* pBtnFactory = BtnFactory::CreateBtnFactory();
    Button* pBtn = pBtnFactory->CreateButton(RectBtn::BtnType.c_str());
    if(pBtn)
    {
        pBtn->UpdateShape();
        delete pBtn;
    }
    BtnFactory::DestoryBtnFactory(pBtnFactory);
    return 0;
}