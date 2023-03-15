#include <engine.h>
#include <iostream>

class MyApplication : public ICEngine::Application
{
    
};

int main() {
    auto application = std::make_unique<MyApplication>();
    int code = application->onStart(640, 640);
    std::cin.get();
    return code;
}