 #include <Urho3D/Urho3DAll.h>

using namespace Urho3D;
/**
* Using the convenient Application API we don't have
* to worry about initializing the engine or writing a main.
* You can probably mess around with initializing the engine
* and running a main manually, but this is convenient and portable.
*/
class MyApp : public Application
{
public:
    /**
    * This happens before the engine has been initialized
    * so it's usually minimal code setting defaults for
    * whatever instance variables you have.
    * You can also do this in the Setup method.
    */
    MyApp(Context * context) : Application(context){}

    /**
    * This method is called before the engine has been initialized.
    * Thusly, we can setup the engine parameters before anything else
    * of engine importance happens (such as windows, search paths,
    * resolution and other things that might be user configurable).
    */
    virtual void Setup()
    {
        // These parameters should be self-explanatory.
        // See http://urho3d.github.io/documentation/1.7/_main_loop.html
        // for a more complete list.
        engineParameters_[EP_FULL_SCREEN] = false;
        engineParameters_[EP_WINDOW_WIDTH] = 720;
        engineParameters_[EP_WINDOW_HEIGHT] = 720;
        engineParameters_[EP_WINDOW_RESIZABLE] = true;
    }

    /**
    * This method is called after the engine has been initialized.
    * This is where you set up your actual content, such as scenes,
    * models, controls and what not. Basically, anything that needs
    * the engine initialized and ready goes in here.
    */
    virtual void Start()
    {
        // We will be needing to load resources.
        // All the resources used in this example comes with Urho3D.
        ResourceCache* cache = GetSubsystem<ResourceCache>();
        Font* font = cache->GetResource<Font>("Fonts/Anonymous Pro.ttf");

        // create some text.
        SharedPtr<Text> text_(new Text(context_));
        // Set string to display.
        text_->SetText("Hellow World For Custom urho3d project 01");

        // If the engine cannot find the font, it comes with Urho3D.
        // Set the environment variables URHO3D_HOME, URHO3D_PREFIX_PATH or
        // change the engine parameter "ResourcePrefixPath" in the Setup method.
        text_->SetFont(font,40);
        text_->SetColor(Color(1,1,0));
        text_->SetAlignment(HA_CENTER, VA_CENTER);
        GetSubsystem<UI>()->GetRoot()->AddChild(text_);
        
        CreateSprite();
    }

    /**
    * Good place to get rid of any system resources that requires the
    * engine still initialized. You could do the rest in the destructor,
    * but there's no need, this method will get called when the engine stops,
    * for whatever reason (short of a segfault).
    */
    virtual void Stop(){ }
    
    
    void CreateSprite()
    {
        //获取ResourceCache子系统
        ResourceCache* cache = GetSubsystem<ResourceCache>();
        //加载纹理资源
        Texture2D* pTexture = cache->GetResource<Texture2D>("Textures/Spot.png");
        
        //创建图片对象
        SharedPtr<Sprite> sprite(new Sprite(context_));
        //设置纹理
        sprite->SetTexture(pTexture);
        //设置左上角的位置
        sprite->SetPosition(Vector2(0,0));
        //同样也是设置左上角的位置
//        sprite->SetAlignment(HA_CENTER, VA_CENTER);
        //设置尺寸,默认为0
        sprite->SetSize(500, 500);
        
        //获取UI子系统
        UI* ui = GetSubsystem<UI>();
        //添加图片
        ui->GetRoot()->AddChild(sprite);
    }
};

/**
* This macro is expanded to (roughly, depending on OS) this:
*
* > int RunApplication()
* > {
* > Urho3D::SharedPtr<Urho3D::Context> context(new Urho3D::Context());
* > Urho3D::SharedPtr<className> application(new className(context));
* > return application->Run();
* > }
* >
* > int main(int argc, char** argv)
* > {
* > Urho3D::ParseArguments(argc, argv);
* > return function;
* > }
*/
URHO3D_DEFINE_APPLICATION_MAIN(MyApp)
