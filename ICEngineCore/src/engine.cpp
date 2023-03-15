#include <GLFW/glfw3.h>
#include <iostream>
#include <engine.h>
#include <cmath>

namespace ICEngine
{

    Transform transform;
    
    float rotationAngle = 5;
    float scaleValue = 0.1f;

    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_W && action == GLFW_PRESS) {
            transform.rotation->x += rotationAngle;
        }

        if (key == GLFW_KEY_S && action == GLFW_PRESS) {
            transform.rotation->x -= rotationAngle;
        }

        if (key == GLFW_KEY_A && action == GLFW_PRESS) {
            transform.rotation->y += rotationAngle;
        }

        if (key == GLFW_KEY_D && action == GLFW_PRESS) {
            transform.rotation->y -= rotationAngle;
        }

        if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
            transform.rotation->z += rotationAngle;
        }

        if (key == GLFW_KEY_E && action == GLFW_PRESS) {
            transform.rotation->z -= rotationAngle;
        }

        if (key == GLFW_KEY_EQUAL && action == GLFW_PRESS) {
            transform.scale->x += scaleValue;
            transform.scale->y += scaleValue;
            transform.scale->z += scaleValue;
        }

        if (key == GLFW_KEY_MINUS && action == GLFW_PRESS) {
            transform.scale->x -= scaleValue;
            transform.scale->y -= scaleValue;
            transform.scale->z -= scaleValue;
        }


        if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }

         if (key == GLFW_KEY_X && action == GLFW_PRESS) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
            
    }

    int Application::onStart(unsigned int window_width, unsigned int window_height)
    {
         GLFWwindow* window;

        if (!glfwInit())
            return -1;
        window = glfwCreateWindow(window_width, window_height, "Lab2", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);

        glfwSetKeyCallback(window, key_callback);

        glEnable(GL_CULL_FACE);

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        GLfloat* matrix = new GLfloat[16]{1, 0, 0, 0, 0, 1, 0, 0, -(float)std::cos(30 * 3.14 / 180), -(float)std::sin(30 * 3.14 / 180), 1, 0, 0, 0, 0, 1};
        glMultMatrixf(matrix);
        delete matrix;

        while (!glfwWindowShouldClose(window))
        {
            onDraw();

            glfwSwapBuffers(window);

            glfwPollEvents();

            onUpdate();
        }

        glPopMatrix();

        glfwTerminate();
        return 0;
    }

    void Application::onUpdate()
    {

    }

    void Application::onDraw()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        multScaleMatrix(0.1, 0.1, 0.1);
        multTranslateMatrix(2, 0, -4);
        drawCube();
        glPopMatrix();
        glPushMatrix();
        glLoadIdentity();
        multRotateXMatrix(transform.rotation->x);
        multRotateYMatrix(transform.rotation->y);
        multRotateZMatrix(transform.rotation->z);
        multScaleMatrix(transform.scale->x, transform.scale->y, transform.scale->z);
        drawCube();
        glPopMatrix();
    }

    Vector3::Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3::Vector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Transform::Transform()
    {
        position = new Vector3();
        rotation = new Vector3();
        scale = new Vector3(1.0f, 1.0f, 1.0f);
    }
    Transform::~Transform()
    {
        delete position;
        delete rotation;
        delete scale;
    }

    void drawCube()
    {
        glBegin(GL_QUADS);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, -1, 1);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, -1, -1);

        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, -1, -1);

        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, -1, 1);

        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 1, 1);

        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(1, -1, 1);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
    
        glEnd();
    }

    void multScaleMatrix(float x, float y, float z)
    {
        GLfloat* matrix = new GLfloat[16]{x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1};
        glMultMatrixf(matrix);
        delete matrix;
    }
    void multRotateXMatrix(float degrees)
    {
        GLfloat* matrix = new GLfloat[16]{1, 0, 0, 0, 0, (float)std::cos(degrees * 3.14 / 180), -(float)std::sin(degrees * 3.14 / 180), 0, 0, (float)std::sin(degrees * 3.14 / 180), (float)std::cos(degrees * 3.14 / 180), 0, 0, 0, 0, 1};
        glMultMatrixf(matrix);
        delete matrix;
    }
    void multRotateYMatrix(float degrees)
    {
        GLfloat* matrix = new GLfloat[16]{(float)std::cos(degrees * 3.14 / 180), 0, (float)std::sin(degrees * 3.14 / 180), 0, 0, 1, 0, 0, -(float)std::sin(degrees * 3.14 / 180), 0, (float)std::cos(degrees * 3.14 / 180), 0, 0, 0, 0, 1};
        glMultMatrixf(matrix);
        delete matrix;
    }

    void multTranslateMatrix(float x, float y, float z)
    {
        glTranslatef(x, y, z);
    }

    void multRotateZMatrix(float degrees)
    {
        GLfloat* matrix = new GLfloat[16]{(float)std::cos(degrees * 3.14 / 180), -(float)std::sin(degrees * 3.14 / 180), 0, 0, (float)std::sin(degrees * 3.14 / 180), (float)std::cos(degrees * 3.14 / 180), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
        glMultMatrixf(matrix);
        delete matrix;
    }
}