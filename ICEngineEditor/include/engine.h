#pragma once

namespace ICEngine
{
    class Application
    {
    public:

        Application();
        virtual ~Application();

        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        virtual int onStart(unsigned int window_width, unsigned int window_height);

        virtual void onUpdate();

        virtual void onDraw();
    };

    class Vector3
    {
    public:
        float x;
        float y;
        float z;
        Vector3();
        Vector3(float x, float y, float z);
    };

    class Transform
    {
    public:
        Vector3* position;
        Vector3* rotation;
        Vector3* scale;

        Transform();
        ~Transform();
    };

    void drawCube();

    void multTranslateMatrix(float x, float y, float z);
    void multScaleMatrix(float x, float y, float z);
    void multRotateXMatrix(float degrees);
    void multRotateYMatrix(float degrees);
    void multRotateZMatrix(float degrees);
}