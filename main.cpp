#include <iostream>
#include <thread>
#include <chrono>
#include <reticle.h>

#define ITER 40
#define MREZ 4

using namespace std;

int fib(int n)
{
    if(n <= 1)  return n;
    else        return fib(n-1) + fib(n-2);
}

int main()
{
    cout << "Hello world!" << endl;

    RetiRenderer::setReticleRootDirectory("D:\\Dev\\GitRepos\\ProjectReticle\\Reticle");

    RetiRenderer::init();
    RetiRenderer ret;

    /*float* verts = new float[MREZ * MREZ * 3];
    float* texes = new float[MREZ * MREZ * 2];

    for(int i = 0; i < MREZ; i++)
    {
        for(int j = 0; j < MREZ; j++)
        {
            verts[i * MREZ + j] = 1.0 * i / MREZ;
            verts[i * MREZ + j + 1] = 1.0 * j / MREZ;
            verts[i * MREZ + j + 2] = 0;
            texes[i * MREZ + j] = 1.0 * i / MREZ;
            texes[i * MREZ + j + 1] = 1.0 * j / MREZ;
            cout << " ("    << verts[i * MREZ + j] << "," << verts[i * MREZ + j + 1]
                            << "," << verts[i * MREZ + j + 2] << ")";
        }
        cout << endl;
    }

    unsigned int* tris = new unsigned int[(MREZ-1) * (MREZ-1) * 6];

    for(int i = 0; i < MREZ-1; i++)
        for(int j = 0; j < MREZ-1; j++)
        {
            int k = i * MREZ + j;
            tris[k] = k;
            tris[k + 1] = k + 1;
            tris[k + 2] = k + MREZ + 1;
            tris[k + 3] = k;
            tris[k + 4] = k + MREZ + 1;
            tris[k + 5] = k + MREZ;
            cout << "( " << tris[k] << "," << tris[k+1] << "," << tris[k+2] << ")" << endl;
            cout << "( " << tris[k+3] << "," << tris[k+4] << "," << tris[k+5] << ")" << endl;
        }

    RetiMesh mesh(verts, texes, MREZ * MREZ, tris, 2 * (MREZ-1) * (MREZ-1));
    RetiSceneObject obj;
    obj.addMesh(&mesh);*/

    //RetiSceneObject obj("D:\\Dex\\WZTFZ\\Sources\\Assets\\Models\\Collection3D\\Aircrafts\\28HORNET_jet\\HORNET_L.3DS");
    //RetiSceneObject obj("D:\\Dev\\OpenGL\\Assimp\\assimp-3.1.1\\assimp-3.1.1\\test\\models\\Collada\\duck.dae");
    RetiSceneObject obj("D:\\Dex\\WZTFZ\\Sources\\Assets\\Models\\Electronics\\Keyboard and Mouse\\Keyboard Apple Wireless N010413.3DS");
    //RetiSceneObject obj("D:\\Dex\\WZTFZ\\Sources\\Assets\\Models\\Guns\\Ump5\\UMP.3DS");
    //RetiSceneObject obj("D:\\Dev\\OpenGL\\ProjectReticle\\Tests\\ProblematicKeyboard.3ds");

    obj.getTransform().scaleTransform(1, 1, 1);
    obj.getTransform().rotateTransform(3.14, 1, 0, 0);
    obj.getTransform().translateTransform(0, 0, -3);

    ret.addSceneObject(&obj);

    ret.startRenderer();

    chrono::duration<float, std::milli> ms_1(1);

    for(int i = 0; i < 3000; i++)
    {
        std::this_thread::sleep_for(ms_1);
        obj.getTransform().rotateTransform(0.003, 0, 0, 1);
    }

    char x;
    cout << "If you type in anything at all, or even just press enter,..." << endl;
    cin >> x;

    ret.stopRenderer();

    cout << "I QUIT!" << endl;

    return 0;
}
