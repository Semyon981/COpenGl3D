#include <WinSock2.h>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
#include "Header.hpp"
#include "menu.hpp"
#include <fstream>
#include <string>
#include <glad/glad.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>
#include <glm/common.hpp>
#include <glm/vector_relational.hpp>
#include <glm/exponential.hpp>
#include <glm/ext.hpp>
#include <glm/fwd.hpp>



#pragma comment(lib, "Ws2_32.lib")
#define PI 3.14159265
#define CRT_SECURE_NO_WARNINGS
#define WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable:4996) 
using namespace std;
using namespace sf;


float loading = 0; // 0-100 %

float lightposition[] = { 0,0,1,0 };



void Init()
{
    gladLoadGL();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);   

}


int score[2] = {0,0};
bool CrCon; //true - create, false - connect;
SOCKET Connection;
float massivesend[16];
float massivereturn[16];
bool closethread = true;
Enemy en;
Player p;
Clock cl1;
float tm1;



void WaitCon()
{


}



void thr()
{
    while (closethread)
    {
        if (recv(Connection, (char*)&massivereturn, sizeof(massivereturn), NULL) != SOCKET_ERROR)
        {
            en.x = massivereturn[0];
            en.y = massivereturn[1];
            en.z = massivereturn[2];
            en.AngleZ = massivereturn[3];
            en.dirX = massivereturn[4];
            en.dirY = massivereturn[5];
            en.onGround = massivereturn[6];
            en.collisX = massivereturn[7];
            en.collisY = massivereturn[8];
            en.collisZ = massivereturn[9];
            en.jmp = massivereturn[10];
            en.tm = massivereturn[11];
            int hepe = massivereturn[12];
            p.health = 100 - (hepe % 10)*10;
            if (CrCon)
            {
                score[1] = massivereturn[13];             
            }
            else
            {
                score[0] = massivereturn[13];             
            }
            en.diX = massivereturn[14];
            en.diY = massivereturn[15];

            cl1.restart();
        }
    }
    
}








int main()
{
    
    ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3.3;
    settings.minorVersion = 3.3;
    settings.sRgbCapable = 0;
    int width = GetSystemMetrics(SM_CXSCREEN);
    int heigh = GetSystemMetrics(SM_CYSCREEN);
    //int width = 1920;
    //int heigh = 1080;
    float mnojitel =float(width) / float(heigh);
    Syst(width, heigh, mnojitel);

    Window window(VideoMode(width, heigh), "OpenGL",Style::Fullscreen, settings);
    window.setVerticalSyncEnabled(true);
    window.setActive(true);

    Init();
   
    LoadFont("Verdana_B_alpha.png", p.font);
    Object map[5];   
    Collada col;
    bool mapbool = true;
   
   
   
    int sizeobj = 0;
   

    int sizeEnemys = 1;
   
    setlocale(LC_ALL, "ru");

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1 * mnojitel, 0.1 * mnojitel, -0.1, 0.1, 0.2, 80);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);
   
    bool firststart = true;
    int fps = 0;
    bool running = true;
    Clock clo;
    float ttt;
    Clock clo1;
    float ttt1;
    Clock clock1;
    float time1;   
  
    bool Multipleer;

   

    Menu men;
    LoadFont("Verdana_B_alpha.png",men.fontf);
    window.setMouseCursorVisible(true);
    men.DrawMenu(window, Multipleer,CrCon);



    WSAData WsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &WsaData) != 0)
    {
        cout << "Oops! Error code 1" << endl;
        exit(1);
    }
    SOCKADDR_IN addr;
   

    



    if (Multipleer)
    {
        if (!CrCon)
        {
            cout << "Enter ip: ";
            char ip[100] = "26.109.56.214";
            //cin >> ip;
            int sizeofaddr = sizeof(addr);
            addr.sin_addr.s_addr = inet_addr(ip);
            addr.sin_port = htons(50000);
            addr.sin_family = AF_INET;

            Connection = socket(AF_INET, SOCK_STREAM, NULL);

            if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
            {
					cout << "Error: failed connect to server.\n";
					return 1;
			}
            else
            {
                cout << "Connected!" << endl;
            }

            p.x = 5.56;
            p.y = 17.22;
            p.z = -0.8;

        }
        else
        {
            int sizeofaddr = sizeof(addr);
            addr.sin_addr.s_addr = INADDR_ANY;
            addr.sin_port = htons(50000);
            addr.sin_family = AF_INET;

            SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
            bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
            listen(sListen, SOMAXCONN);

            Connection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
            cout << "Player Connected!" << endl;
            p.x = 4.21;
            p.y = -17;
            p.z = -0.8;
        }

    }
    else
    {
        p.x = 0;
    }


    //col.LoadObj("kub.dae", "light", window);
    map[0].LoadObj("Abdutex3.obj", "light", window,sizeobj);
    //map[1].LoadObj("DeadInside2.obj", "light", window);
    map[1].LoadObj("deadinsidetex3.obj", "light", window,sizeobj);
    map[2].LoadObj("deagle2.obj", "light", window, sizeobj);
    
    HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thr, 0, 0, NULL);

    window.setMouseCursorVisible(false);
    while (running)
    {
        time1 = clock1.getElapsedTime().asMicroseconds();
        clock1.restart();
        time1 = time1 / 1600;
        if (firststart) { time1 = 1;firststart = false; }
        ttt = clo.getElapsedTime().asSeconds();
        clo.restart();
        ttt1 = clo1.getElapsedTime().asSeconds();
        if (ttt1 >= 0.1)
        {
            fps = 1 / ttt;
            clo1.restart();            
        }
        tm1 = cl1.getElapsedTime().asSeconds();
        if (en.onGround)
        {
            tm1 = 0;

            en.tm = 0;
        }

        //Sleep(20);
       

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {

                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {

                glViewport(0, 0, event.size.width, event.size.height);
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }


        p.key(time1);
        p.gravity(time1);
        if (window.isOpen())
        {
            p.mou(window);
        }
        if (Multipleer)
        {
            massivesend[0] = p.x;
            massivesend[1] = p.y;
            massivesend[2] = p.z;
            massivesend[3] = p.AngleZ;
            massivesend[4] = p.dirX;
            massivesend[5] = p.dirY;
            massivesend[6] = p.onGround;
            massivesend[7] = p.collisX;
            massivesend[8] = p.collisY;
            massivesend[9] = p.collisZ;
            massivesend[10] = p.jmp;
            massivesend[11] = p.tm;
            if (p.shoot && p.popadanie)
            {
                en.hits += 1;
            }
            massivesend[12] = en.hits;
            if (CrCon)
            {
                score[0] = en.hits / 10;
                massivesend[13] = score[0];
            }
            else
            {
                score[1] = en.hits / 10;
                massivesend[13] = score[1];
            }
            massivesend[14] = p.diX;
            massivesend[15] = p.diY;
            send(Connection, (char*)&massivesend, sizeof(massivesend), NULL);    
        }
           
       
        
       
        en.key(time1);
        en.gravity(time1, tm1);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();       
        p.DrawCam();
      
        map[0].DrawObj(0, 0, 0, 1, 1, 1, 1,0,0,0, p,1); 
        
        if (!Multipleer)
        {
            map[1].DrawObj(1, 0, 0, 1, 1, 1, 1,0,0,45, p,1);
        }
        else
        {
            map[1].DrawObj(en.x, en.y, en.z, 1, 1, 1, 1,0,0, -massivereturn[3], p,1);
        }


        map[2].DrawObj(p.x + sin((p.AngleZ) / 180 * PI) * abs(sin(-(p.AngleX) / 180 * PI)) + p.xx * cos((p.AngleZ) / 180 * PI) + p.zz * cos(-p.AngleX / 180 * PI) * sin((p.AngleZ) / 180 * PI) + p.yy * sin(-p.AngleX / 180 * PI) * sin((p.AngleZ) / 180 * PI),
            p.y + cos((p.AngleZ) / 180 * PI) * abs(sin(-(p.AngleX) / 180 * PI)) + p.xx * -sin((p.AngleZ) / 180 * PI) + p.zz * cos(-p.AngleX / 180 * PI) * cos((p.AngleZ) / 180 * PI) + p.yy * sin(-p.AngleX / 180 * PI) *cos((p.AngleZ) / 180 * PI),
            p.z + p.h + -cos(-p.AngleX / 180 * PI) + p.zz * sin(-p.AngleX / 180 * PI) + p.yy * -cos(-p.AngleX / 180 * PI),
            1, 1, 1, 1, -p.AngleX - 90+p.wAngleX, 0, -p.AngleZ+p.wAngleZ, p, 0);

        //cout << p.y << " " << p.AngleZ << endl;
        
        //cout << p.AngleX << endl;

        //map[2].DrawObj(p.x , p.y , p.z + p.h , 1, 2, 2, 2, -p.AngleX - 90, 0, -p.AngleZ, p, 0);
        p.popal(map[1].maxX[0], map[1].maxY[0], map[1].maxZ[0], map[1].minX[0], map[1].minY[0], map[1].minZ[0]);
        
        p.drawfps(fps,score[0],score[1]);
       
        
        mapbool = true;
        for (int i = 0;i < sizeobj;i++)
        {
            for (int j = 0;j < map[i].sizeobj;j++)
            {
                if (map[i].checkcas(p,j) == true)
                {
                    mapbool = false;
                }
            }
        }
        if (mapbool)
        {
            p.collisX = 0;
            p.collisY = 0;
            p.collisZ = 0;
            p.onGround = false;
        }
           
        glPopMatrix();
        glFinish();
        


        window.display();
    }

    closethread = false;
    if (Multipleer)
    {
        WaitForSingleObject(thread, INFINITE);
        CloseHandle(thread);
    }

    return 0;
}