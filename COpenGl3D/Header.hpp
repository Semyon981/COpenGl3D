#include <iostream>
#include <fstream>
#include <string>
#include <tinyxml/tinyxml.h>
#include <glad/glad.h>     
#include <glm/glm.hpp>
#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>
#include <glm/common.hpp>
#include <glm/vector_relational.hpp>
#include <glm/exponential.hpp>
#include <glm/ext.hpp>
#include <glm/fwd.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdarg.h>
#include <Windows.h>
using namespace std;
using namespace sf;

using namespace glm;
#define PI 3.14159265

int width;
int heigh;
float mnojitel;

void Syst(int w, int h, float m)
{
    width = w;
    heigh = h;
    mnojitel = m;
}


int GetNumSymb(char symb)
{
    setlocale(LC_ALL, "ru");
    if (symb == ' ') { return 0; }
    else if (symb == '!') { return 33; }
    //else if (symb == '0') { return 34; }
    else if (symb == '"') { return 35; }
    else if (symb == '#') { return 36; }
    else if (symb == '$') { return 37; }
    else if (symb == '%') { return 38; }
    else if (symb == '(') { return 40; }
    else if (symb == ')') { return 41; }
    else if (symb == '*') { return 42; }
    else if (symb == '+') { return 43; }
    else if (symb == ',') { return 44; }
    else if (symb == '-') { return 45; }
    else if (symb == '.') { return 46; }
    else if (symb == '/') { return 47; }
    else if (symb == '0') { return 48; }
    else if (symb == '1') { return 49; }
    else if (symb == '2') { return 50; }
    else if (symb == '3') { return 51; }
    else if (symb == '4') { return 52; }
    else if (symb == '5') { return 53; }
    else if (symb == '6') { return 54; }
    else if (symb == '7') { return 55; }
    else if (symb == '8') { return 56; }
    else if (symb == '9') { return 57; }
    else if (symb == ':') { return 58; }
    else if (symb == ';') { return 59; }
    else if (symb == '<') { return 60; }
    else if (symb == '=') { return 61; }
    else if (symb == '>') { return 62; }
    if (symb == '?') { return 63; }
    else if (symb == '@') { return 64; }
    else if (symb == 'A') { return 65; }
    else if (symb == 'B') { return 66; }
    else if (symb == 'C') { return 67; }
    else if (symb == 'D') { return 68; }
    else if (symb == 'E') { return 69; }
    else if (symb == 'F') { return 70; }
    else if (symb == 'G') { return 71; }
    else if (symb == 'H') { return 72; }
    else if (symb == 'I') { return 73; }
    else if (symb == 'J') { return 74; }
    else if (symb == 'K') { return 75; }
    else if (symb == 'L') { return 76; }
    else if (symb == 'M') { return 77; }
    else if (symb == 'N') { return 78; }
    else if (symb == 'O') { return 79; }
    else if (symb == 'P') { return 80; }
    else if (symb == 'Q') { return 81; }
    else if (symb == 'R') { return 82; }
    else if (symb == 'S') { return 83; }
    else if (symb == 'T') { return 84; }
    else if (symb == 'U') { return 85; }
    else if (symb == 'V') { return 86; }
    else if (symb == 'W') { return 87; }
    else if (symb == 'X') { return 88; }
    else if (symb == 'Y') { return 89; }
    else if (symb == 'Z') { return 90; }
    else if (symb == '[') { return 91; }
    else if (symb == ']') { return 93; }
    else if (symb == '^') { return 94; }
    else if (symb == '_') { return 95; }
    else if (symb == 'a') { return 97; }
    else if (symb == 'b') { return 98; }
    else if (symb == 'c') { return 99; }
    else if (symb == 'd') { return 100; }
    else if (symb == 'e') { return 101; }
    else if (symb == 'f') { return 102; }
    else if (symb == 'g') { return 103; }
    else if (symb == 'h') { return 104; }
    else if (symb == 'i') { return 105; }
    else if (symb == 'j') { return 106; }
    else if (symb == 'k') { return 107; }
    else if (symb == 'l') { return 108; }
    else if (symb == 'm') { return 109; }
    else if (symb == 'n') { return 110; }
    else if (symb == 'o') { return 111; }
    else if (symb == 'p') { return 112; }
    else if (symb == 'q') { return 113; }
    else if (symb == 'r') { return 114; }
    else if (symb == 's') { return 115; }
    else if (symb == 't') { return 116; }
    else if (symb == 'u') { return 117; }
    else if (symb == 'v') { return 118; }
    else if (symb == 'w') { return 119; }
    else if (symb == 'x') { return 120; }
    else if (symb == 'y') { return 121; }
    else if (symb == 'z') { return 122; }
    else if (symb == '{') { return 123; }
    else if (symb == '|') { return 124; }
    else if (symb == '}') { return 125; }
    else if (symb == 'Ё') { return 168; }
    else if (symb == 'ё') { return 184; }
    else if (symb == 'А') { return 192; }
    else if (symb == 'Б') { return 193; }
    else if (symb == 'В') { return 194; }
    else if (symb == 'Г') { return 195; }
    else if (symb == 'Д') { return 196; }
    else if (symb == 'Е') { return 197; }
    else if (symb == 'Ж') { return 198; }
    else if (symb == 'З') { return 199; }
    else if (symb == 'И') { return 200; }
    else if (symb == 'Й') { return 201; }
    else if (symb == 'К') { return 202; }
    else if (symb == 'Л') { return 203; }
    else if (symb == 'М') { return 204; }
    else if (symb == 'Н') { return 205; }
    else if (symb == 'О') { return 206; }
    else if (symb == 'П') { return 207; }
    else if (symb == 'Р') { return 208; }
    else if (symb == 'С') { return 209; }
    else if (symb == 'Т') { return 210; }
    else if (symb == 'У') { return 211; }
    else if (symb == 'Ф') { return 212; }
    else if (symb == 'Х') { return 213; }
    else if (symb == 'Ц') { return 214; }
    else if (symb == 'Ч') { return 215; }
    else if (symb == 'Ш') { return 216; }
    else if (symb == 'Щ') { return 217; }
    else if (symb == 'Ъ') { return 218; }
    else if (symb == 'Ы') { return 219; }
    else if (symb == 'Ь') { return 220; }
    else if (symb == 'Э') { return 221; }
    if (symb == 'Ю') { return 222; }
    else if (symb == 'Я') { return 223; }
    else if (symb == 'а') { return 224; }
    else if (symb == 'б') { return 225; }
    else if (symb == 'в') { return 226; }
    else if (symb == 'г') { return 227; }
    else if (symb == 'д') { return 228; }
    else if (symb == 'е') { return 229; }
    else if (symb == 'ж') { return 230; }
    else if (symb == 'з') { return 231; }
    else if (symb == 'и') { return 232; }
    else if (symb == 'й') { return 233; }
    else if (symb == 'к') { return 234; }
    else if (symb == 'л') { return 235; }
    else if (symb == 'м') { return 236; }
    else if (symb == 'н') { return 237; }
    else if (symb == 'о') { return 238; }
    else if (symb == 'п') { return 239; }
    else if (symb == 'р') { return 240; }
    else if (symb == 'с') { return 241; }
    else if (symb == 'т') { return 242; }
    else if (symb == 'у') { return 243; }
    else if (symb == 'ф') { return 244; }
    else if (symb == 'х') { return 245; }
    else if (symb == 'ц') { return 246; }
    else if (symb == 'ч') { return 247; }
    else if (symb == 'ш') { return 248; }
    else if (symb == 'щ') { return 249; }
    else if (symb == 'ъ') { return 250; }
    else if (symb == 'ы') { return 251; }
    else if (symb == 'ь') { return 252; }
    else if (symb == 'э') { return 253; }
    else if (symb == 'ю') { return 254; }
    else if (symb == 'я') { return 255; }


}
void DrawTxt(string text, int x, int y, float scale, unsigned int font)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, heigh, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    glUseProgram(0);
    glPushMatrix();


    for (int i = 0; i < text.length(); i++)
    {
        int numsymb = GetNumSymb(text[i]);
        float aaa = float(1) / float(16);
        int symbX = int(numsymb % 16);
        int symbY = int(numsymb / 16);
        float texCoord[8] = { symbX * aaa,aaa + symbY * aaa,   aaa + symbX * aaa,aaa + symbY * aaa,   aaa + symbX * aaa, symbY * aaa,   symbX * aaa, symbY * aaa };
        float vertex[8] = { i * 32 * scale + x,heigh - 32 * scale - y,  32 * scale + i * 32 * scale + x,heigh - 32 * scale - y,  32 * scale + i * 32 * scale + x,heigh - y,  i * 32 * scale + x,heigh - y };


        glColor4f(1, 1, 1, 1);
        glAlphaFunc(GL_GREATER, 0.2f);
        glBindTexture(GL_TEXTURE_2D, font);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertex);
        glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glBindTexture(GL_TEXTURE_2D, 0);

    }


    glPopMatrix();






}
void LoadFont(const char name[], unsigned int& font)
{
    int www, hhh, cnt;
    unsigned char* data = stbi_load(name, &www, &hhh, &cnt, 0);
    glGenTextures(1, &font);
    glBindTexture(GL_TEXTURE_2D, font);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, www, hhh, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}
class Player
{
public:
    float x = 0, y = 0, z = 0;
    float dx = 0, dy = 0, dz = 0;
    float AngleX = 1, AngleZ = 0;
    float MouseX, MouseY, mdx, mdy;
    float sensivity = 0.45;
    int collisX = 0;
    int collisY = 0;
    int collisZ = 0;
    float speed = 1;
    bool onGround;
    unsigned int font;
    int fps = 0;
    float w = 1, h = 2;
    float maximumz = 0;
    int symb = 16;
    float symbX, symbY;
    bool bhop = true;
    float jmp = 0;
    float jmpsize = 1;
    float jmptime = 1;
    Clock cl;
    float tm;

    float xx = 0.25;
    float yy = -0.35;
    float zz = -0.15;

    float wAngleZ = 0;
    float wAngleX = 0;
    Clock wclock;
    float wtime;

    float xw = 0.25;
    float yw = -0.35;
    float zw = -0.15;

    Clock clX;
    float tmX = 1;
    float tmX1 = 1;
    float tmX2 = 1;
    Clock clY;
    float tmY = 1;
    float tmY1 = 1;
    float tmY2 = 1;

    bool firststart = true;
    bool spaceunpressed = true;

    float dirX = 0;
    float dirY = 0;
    int diX = 0;
    int diY = 0;
    int diXlast = 0;
    int diYlast = 0;
    int vspX = 0;
    int vspY = 0;


    Clock clocksh;
    float timesh;
    float dAngleX;
    float lAngleX;

    int health = 100;
    bool shoot = false;
    bool mouseunpressed = true;
    Clock chasu;
    float shoottimer;
    bool popadanie = false;

    Clock wclX;
    Clock wclY;
    float wtmx;
    float wtmy;

    void drawfps(int fps, int score1, int score2)
    {

        DrawTxt(to_string(fps), 0, 0, 1, font);
        DrawTxt(to_string(health), 0, heigh - 32, 1, font);
        if (score1 < 10)
        {
            DrawTxt(to_string(score1), width / 2 - 32, 0, 1, font);
        }
        else
        {
            DrawTxt(to_string(score1), width / 2 - 64, 0, 1, font);
        }
        DrawTxt(to_string(score2), width / 2, 0, 1, font);

        glPushMatrix();
        if (popadanie)
        {
            glColor4f(shoottimer, 1, shoottimer, 1);
        }
        else
        {
            glColor4f(1, shoottimer, shoottimer, 1);
        }


        glAlphaFunc(GL_GREATER, 0.2f);
        glBegin(GL_POINTS);

        glVertex2f(width / 2, heigh / 2 - 4);
        glVertex2f(width / 2 + 1, heigh / 2 - 4);
        glVertex2f(width / 2 - 1, heigh / 2 - 4);
        glVertex2f(width / 2, heigh / 2 - 5);
        glVertex2f(width / 2 + 1, heigh / 2 - 5);
        glVertex2f(width / 2 - 1, heigh / 2 - 5);
        glVertex2f(width / 2, heigh / 2 - 6);
        glVertex2f(width / 2 + 1, heigh / 2 - 6);
        glVertex2f(width / 2 - 1, heigh / 2 - 6);
        glVertex2f(width / 2, heigh / 2 - 7);
        glVertex2f(width / 2 + 1, heigh / 2 - 7);
        glVertex2f(width / 2 - 1, heigh / 2 - 7);

        glVertex2f(width / 2, heigh / 2 + 4);
        glVertex2f(width / 2 + 1, heigh / 2 + 4);
        glVertex2f(width / 2 - 1, heigh / 2 + 4);
        glVertex2f(width / 2, heigh / 2 + 5);
        glVertex2f(width / 2 + 1, heigh / 2 + 5);
        glVertex2f(width / 2 - 1, heigh / 2 + 5);
        glVertex2f(width / 2, heigh / 2 + 6);
        glVertex2f(width / 2 + 1, heigh / 2 + 6);
        glVertex2f(width / 2 - 1, heigh / 2 + 6);
        glVertex2f(width / 2, heigh / 2 + 7);
        glVertex2f(width / 2 + 1, heigh / 2 + 7);
        glVertex2f(width / 2 - 1, heigh / 2 + 7);

        glVertex2f(width / 2 + 4, heigh / 2);
        glVertex2f(width / 2 + 4, heigh / 2 + 1);
        glVertex2f(width / 2 + 4, heigh / 2 - 1);
        glVertex2f(width / 2 + 5, heigh / 2);
        glVertex2f(width / 2 + 5, heigh / 2 + 1);
        glVertex2f(width / 2 + 5, heigh / 2 - 1);
        glVertex2f(width / 2 + 6, heigh / 2);
        glVertex2f(width / 2 + 6, heigh / 2 + 1);
        glVertex2f(width / 2 + 6, heigh / 2 - 1);
        glVertex2f(width / 2 + 7, heigh / 2);
        glVertex2f(width / 2 + 7, heigh / 2 + 1);
        glVertex2f(width / 2 + 7, heigh / 2 - 1);

        glVertex2f(width / 2 - 4, heigh / 2);
        glVertex2f(width / 2 - 4, heigh / 2 + 1);
        glVertex2f(width / 2 - 4, heigh / 2 - 1);
        glVertex2f(width / 2 - 5, heigh / 2);
        glVertex2f(width / 2 - 5, heigh / 2 + 1);
        glVertex2f(width / 2 - 5, heigh / 2 - 1);
        glVertex2f(width / 2 - 6, heigh / 2);
        glVertex2f(width / 2 - 6, heigh / 2 + 1);
        glVertex2f(width / 2 - 6, heigh / 2 - 1);
        glVertex2f(width / 2 - 7, heigh / 2);
        glVertex2f(width / 2 - 7, heigh / 2 + 1);
        glVertex2f(width / 2 - 7, heigh / 2 - 1);

        glEnd();
        glPopMatrix();




    }
    
    
    void popal(float maxX, float maxY, float maxZ, float minX, float minY, float minZ)
    {

        bool daa = false;
        float xcoord;
        float ycoord;
        float zcoord;
        if (shoot)
        {
           
            float CamFront[3] = { abs(sin(-AngleX / 180 * PI)) * sin(AngleZ / 180 * PI), abs(sin(-AngleX / 180 * PI)) * cos(AngleZ / 180 * PI), -cos(-AngleX / 180 * PI) };
            CamFront[0] /= 2;
            CamFront[1] /= 2;
            CamFront[2] /= 2;
            for (int i = 0; i < 100; i++)
            {
                xcoord = x + CamFront[0] * i;
                ycoord = y + CamFront[1] * i;
                zcoord = z + h + CamFront[2] * i;

                if (xcoord <= maxX && xcoord >= minX && ycoord <= maxY && ycoord >= minY && zcoord <= maxZ && zcoord >= minZ)
                {
                    daa = true;
                    popadanie = true;
                    i = 100;
                }
            }
            /*float maX[3] = {1,0,0};
            float miX[3] = {-1,0,0};
            float maY[3] = { 0,1,0 };
            float miY[3] = { 0,-1,0 };
            float maZ[3] = { 0,0,1 };
            float miZ[3] = { 0,0,-1 };

            float cm[6];
            cm[0] = maX[0] * CamFront[0] + maX[1] * CamFront[1] + maX[1] * CamFront[1];
            cm[1] = miX[0] * CamFront[0] + miX[1] * CamFront[1] + miX[1] * CamFront[1];
            cm[2] = maY[0] * CamFront[0] + maY[1] * CamFront[1] + maY[1] * CamFront[1];
            cm[3] = miY[0] * CamFront[0] + miY[1] * CamFront[1] + miY[1] * CamFront[1];
            cm[4] = maZ[0] * CamFront[0] + maZ[1] * CamFront[1] + maZ[1] * CamFront[1];
            cm[5] = miZ[0] * CamFront[0] + miZ[1] * CamFront[1] + miZ[1] * CamFront[1];

            float tm[6];
            tm[0] = -(maX[0] * x + maX[1] * y + maX[1] * z + maxX) / cm[0];
            tm[1] = -(miX[0] * x + miX[1] * y + miX[1] * z + minX) / cm[1];
            tm[2] = -(maY[0] * x + maY[1] * y + maY[1] * z + maxY) / cm[2];
            tm[3] = -(miY[0] * x + miY[1] * y + miY[1] * z + minY) / cm[3];
            tm[4] = -(maZ[0] * x + maZ[1] * y + maZ[1] * z + maxZ) / cm[4];
            tm[5] = -(miZ[0] * x + miZ[1] * y + miZ[1] * z + minZ) / cm[5];

            int maas[2];
            int ggg = 0;
            for (int i = 0; i < 6; i++)
            {
                if (cm[i] > 0)
                {
                    maas[ggg] = i;
                    ggg++;
                }               
            }
            float xv1 = x + CamFront[0] * tm[maas[0]];
            float yv1 = y + CamFront[1] * tm[maas[0]];
            float zv1 = z + CamFront[2] * tm[maas[0]];

            float xv2 = x + CamFront[0] * tm[maas[1]];
            float yv2 = y + CamFront[1] * tm[maas[1]];
            float zv2 = z + CamFront[2] * tm[maas[1]];

            
            if (maas[0] < 2)
            {
                if (yv1<maxY && yv1 > minY && zv1<maxZ && zv1 > minZ)
                {
                    daa = true;
                    popadanie = true;
                }
            }
            else if (maas[0] >= 2 && maas[0] < 4)
            {
                if (xv1<maxX && xv1 > minX && zv1<maxZ && zv1 > minZ)
                {
                    daa = true;
                    popadanie = true;
                }
            }
            else if  (maas[0] >= 4)
            {
                if (yv1<maxY && yv1 > minY && xv1<maxX && xv1 > minX)
                {
                    daa = true;
                    popadanie = true;
                }
            }*/

           
            


            if (!daa)
            {
                popadanie = false;
            }
        }
       
    }

    void gravity(float time)
    {


        if (Keyboard::isKeyPressed(Keyboard::Space) && spaceunpressed) //if(Input.GetKeyDown(KeyCode.Space))
        {
            if (onGround)
            {
                cl.restart();
                onGround = false;
                jmp = 0.3;
            }
        }
        if (!Keyboard::isKeyPressed(Keyboard::Space))
        {
            spaceunpressed = true;
            if (onGround)
            {
                jmp = 0;
            }
        }
        else
        {
            if (!bhop) spaceunpressed = false;
        }

        if (collisZ == -1)
        {
            jmp = 0;
        }

        if (firststart)
        {
            cl.restart();
            firststart = false;
            time = 1;
        }

        tm = cl.getElapsedTime().asSeconds();



        if (!onGround)
        {
            dz = jmp * time - tm * time;
        }
        else
        {
            cl.restart();

        }
        /*f(maximumz < z)
        {
            maximumz = z;
            cout << maximumz << endl;
        }*/

    }
    void key(float time)
    {




        if (diX == 0)
        {
            if (vspX == 0)
            {
                clX.restart();
                vspX = 1;
            }
            tmX = tmX1 - clX.getElapsedTime().asSeconds() * 8;
            tmX2 = tmX;
            if (tmX < 0 || collisX != 0 || collisY != 0)
            {
                tmX = 0;
                tmX2 = tmX;
            }
        }
        else
        {
            if (vspX == 1)
            {
                clX.restart();
                vspX = 0;
            }
            tmX = tmX2 + clX.getElapsedTime().asSeconds() * 8;
            tmX1 = tmX;
            if (tmX > 1)
            {
                tmX = 1;
                tmX1 = tmX;
            }
        }


        if (diY == 0)
        {
            if (vspY == 0)
            {
                clY.restart();
                vspY = 1;
            }
            tmY = tmY1 - clY.getElapsedTime().asSeconds() * 8;
            tmY2 = tmY;
            if (tmY < 0 || collisX != 0 || collisY != 0)
            {
                tmY = 0;
                tmY2 = tmY;
            }

        }
        else
        {
            if (vspY == 1)
            {
                clY.restart();
                vspY = 0;
            }
            tmY = tmY2 + clY.getElapsedTime().asSeconds() * 8;
            tmY1 = tmY;
            if (tmY > 1)
            {
                tmY = 1;
                tmY1 = tmY;
            }

        }


        if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D))
        {

            diX = 0;
            diY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::D))
        {

            diY = 0;
            if (tmY == 0 || dirY < 0)
            {
                dirY = -1;
                diY = -1;
            }
            diX = 0;

        }
        else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D))
        {
            diY = 0;
            if (tmY == 0 || dirY > 0)
            {
                dirY = 1;
                diY = 1;
            }
            diX = 0;

        }
        else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S))
        {
            diX = 0;
            if (tmX == 0 || dirX < 0)
            {
                dirX = -1;
                diX = -1;
            }


            diY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::D))
        {
            diX = 0;
            if (tmX == 0 || dirX > 0)
            {
                dirX = 1;
                diX = 1;
            }


            diY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::S))
        {

            diX = 0;
            diY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D))
        {

            diX = 0;
            diY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::A))
        {

            if (tmX == 0 || dirX < 0)
            {
                dirX = -sqrt(2) / 2;
                diX = -1;
            }
            if (tmY == 0 || dirY > 0)
            {
                dirY = sqrt(2) / 2;
                diY = 1;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::D))
        {

            if (tmX == 0 || dirX > 0)
            {
                dirX = sqrt(2) / 2;
                diX = 1;
            }
            if (tmY == 0 || dirY > 0)
            {
                dirY = sqrt(2) / 2;
                diY = 1;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::A))
        {

            if (tmX == 0 || dirX < 0)
            {
                dirX = -sqrt(2) / 2;
                diX = -1;
            }
            if (tmY == 0 || dirY < 0)
            {
                dirY = -sqrt(2) / 2;
                diY = -1;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::D))
        {

            if (tmX == 0 || dirX > 0)
            {
                dirX = sqrt(2) / 2;
                diX = 1;
            }
            if (tmY == 0 || dirY < 0)
            {
                dirY = -sqrt(2) / 2;
                diY = -1;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::W))
        {
            diY = 0;
            if (tmY == 0 || dirY > 0)
            {
                dirY = 1;
                diY = 1;
            }
            diX = 0;

        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            diY = 0;
            if (tmY == 0 || dirY < 0)
            {
                dirY = -1;
                diY = -1;
            }
            diX = 0;

        }
        else if (Keyboard::isKeyPressed(Keyboard::A))
        {
            diX = 0;

            if (tmX == 0 || dirX < 0)
            {
                dirX = -1;
                diX = -1;
            }


            diY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::D))
        {
            diX = 0;
            if (tmX == 0 || dirX > 0)
            {
                dirX = 1;
                diX = 1;
            }


            diY = 0;
        }
        else
        {

            diX = 0;
            diY = 0;
        }



        
        shoottimer = chasu.getElapsedTime().asSeconds();
        timesh = clocksh.getElapsedTime().asSeconds();
        if (shoottimer > 1)
        {
            shoottimer = 1;
        }

        if (Mouse::isButtonPressed(Mouse::Left) && mouseunpressed && wAngleX == 0)
        {
            
            shoot = true;
            wclock.restart();
            chasu.restart();
          
        }
        else
        {
            shoot = false;
        }
        if (!Mouse::isButtonPressed(Mouse::Left))
        {
            mouseunpressed = true;
        }
        else
        {
            mouseunpressed = false;
        }
        wtime = 0.15 - wclock.getElapsedTime().asSeconds();

        if (wtime > -0.15)
        {
            wAngleX += wtime*time*2;
        }
        else
        {
            wAngleX = 0;
        }
       

        if (diXlast != diX)
        {
            diXlast = diX;
            wclX.restart();
        }
        if (diYlast != diY)
        {
            diYlast = diY;
            wclY.restart();
        }

        if (diX != 0)
        {
            wtmx = wclX.getElapsedTime().asSeconds() * 15;
            if (wtmx > 1)
            {
                wtmx = 1;
            }
            wtmx *= diX;
        }      
        else
        {
            wtmx = 1 - wclX.getElapsedTime().asSeconds() * 15;
            if (wtmx < 0)
            {
                wtmx = 0;
            }
            if (dirX < 0)
            {
                wtmx *= -1;
            }
        }


        if (diY != 0)
        {
            wtmy = wclY.getElapsedTime().asSeconds() * 15;
            if (wtmy > 1)
            {
                wtmy = 1;
            }
            wtmy *= diY;
        }
        else
        {
            wtmy = 1 - wclY.getElapsedTime().asSeconds() * 15;
            if (wtmy < 0)
            {
                wtmy = 0;
            }
            if (dirY < 0)
            {
                wtmy *= -1;
            }
        }


        dy = cos((PI * AngleZ) / 180) * time * speed * 0.15 * dirY * tmY + -sin((PI * AngleZ) / 180) * time * speed * 0.15 * dirX * tmX;
        dx = sin((PI * AngleZ) / 180) * time * speed * 0.15 * dirY * tmY + cos((PI * AngleZ) / 180) * time * speed * 0.15 * dirX * tmX;


        yy = yw - wtmy * 0.02;
        xx = xw - wtmx * 0.02;



        if (Keyboard::isKeyPressed(Keyboard::N))
        {
            dx = 0;
            dy = 0;
            x = 0;
            y = 0;
            z = -0.3;
            cl.restart();
        }




       


        if (collisX == 0)
        {
            x += dx * 0.1;
        }
        else if (collisX == 1)
        {
            if (dx > 0)
                x += dx * 0.1;
        }
        else if (collisX == -1)
        {
            if (dx < 0)
                x += dx * 0.1;
        }

        if (collisY == 0)
        {
            y += dy * 0.1;
        }
        else if (collisY == 1)
        {
            if (dy > 0)
                y += dy * 0.1;
        }
        else if (collisY == -1)
        {
            if (dy < 0)
                y += dy * 0.1;
        }

        if (collisZ == 0)
        {
            z += dz * 0.1;

        }
        else if (collisZ == 1)
        {
            if (dz > 0)
            {
                z += dz * 0.1;

            }
        }
        else if (collisZ == -1)
        {
            //dz = -1;
            if (dz < 0)
            {
                z += dz * 0.1;

            }
        }

    }

    void mou(Window& window)
    {
        MouseX = Mouse::getPosition(window).x;
        MouseY = Mouse::getPosition(window).y;

        mdx = MouseX - width / 2;
        mdy = MouseY - heigh / 2;



        AngleZ += mdx / 6 * sensivity;

        if (AngleX > -179 && AngleX < -1)
        {
            AngleX += mdy / 6 * sensivity;
        }
        else
        {
            if (AngleX <= -179 && mdy > 0)
            {
                AngleX += mdy / 6 * sensivity;
            }
            else if (AngleX >= -1 && mdy < 0)
            {
                AngleX += mdy / 6 * sensivity;
            }
        }

        Mouse::setPosition(Vector2i(width / 2, heigh / 2));
    }


    void DrawCam()
    {
        //AngleX = 0;
        //AngleZ = 0;
        glRotatef(AngleX, 1, 0, 0);
        glRotatef(AngleZ, 0, 0, 1);
        glTranslatef(-x, -y, -z - h);
        //cout << -sin((PI * -AngleX) / 180) * sin((PI * AngleZ) / 180) << " " << -sin((PI * -AngleX) / 180) * cos((PI * AngleZ) / 180) << " " << -cos((PI * -AngleX) / 180) <<" " << x << " " << y << " " << z << endl;

    }

};


class Object
{
public:


    int sizevert = 0;
    int sizetex = 0;
    int sizeindex = 0;

    int sizevert1 = 0;
    int sizetex1 = 0;
    int sizeindex1 = 0;



    float vert[3];
    bool UseShader;
    GLuint index[3];
    int texidx[3];
    float tex6[6];
    //float tex[100000];
    GLuint prog;
    GLuint VBO;
    GLuint IBO;
    GLuint TBO;
    GLuint TNBO;
    int sizeobj;
    int sizeobj1;
    /*mat4 Model;
    mat4 View;
    mat4 Projection;*/
    int cX[1000], cY[1000], cZ[1000];
    int numtexstr[1000];
    bool ongr = false;
    int vnf = 0;
    string str;
    string strstr;
    char huita;
    int musor;
    float maxXlocal[1000], maxYlocal[1000], maxZlocal[1000], minXlocal[1000], minYlocal[1000], minZlocal[1000];
    float maxX[1000], maxY[1000], maxZ[1000], minX[1000], minY[1000], minZ[1000];
    bool casanie;
    string nametex[100];
    int nametexsize = 0;
    float nametexnum = 0;
    int texsize = 0;

    unsigned int texture[1000];
    unsigned int font;
    unsigned int normalmaptex;

    int pv1, pv2, pv3, pn, v1, v2, v3, n;
    float x, y, z, size;

    /* float** vert;
     float** normal;
     float** index;*/

    mat4 ProjectionMatrix;
    


    float light[4] = { 5,5,3,0 };

    GLuint CreateShader(string FileName, char Type)
    {

        static int len = 8000;
        fstream file;
        if (Type == 'f')
        {
            file.open(FileName + ".frag");
        }
        else if (Type == 'v')
        {
            file.open(FileName + ".vert");
        }
        else if (Type == 'g')
        {
            file.open(FileName + ".geom");
        }
        char* txt = new char[len];
        file.getline(txt, len, '\0');
        //cout << text << endl;
        file.close();
        GLuint shader;
        if (Type == 'f')
        {
            shader = glCreateShader(GL_FRAGMENT_SHADER);
        }
        else if (Type == 'v')
        {
            shader = glCreateShader(GL_VERTEX_SHADER);
        }
        else if (Type == 'g')
        {
            shader = glCreateShader(GL_GEOMETRY_SHADER);
        }
        glShaderSource(shader, 1, &txt, NULL);
        glCompileShader(shader);
        delete txt;
        GLint ok;
        GLchar log[2000];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
        if (!ok)
        {
            glGetShaderInfoLog(shader, 2000, NULL, log);
            printf("%s\n", log);
        }
        return shader;

    }

    void LoadShader(string FileName)
    {
        GLuint  FragShader = CreateShader(FileName, 'f');
        GLuint  VertShader = CreateShader(FileName, 'v');
        GLuint  GeomShader = CreateShader(FileName, 'g');

        prog = glCreateProgram();
        glAttachShader(prog, FragShader);
        glAttachShader(prog, VertShader);
        glAttachShader(prog, GeomShader);
        glLinkProgram(prog);

    }



    void LoadTexture(string name, unsigned int& texture)
    {

        int www, hhh, cnt;
        unsigned char* data = stbi_load(name.c_str(), &www, &hhh, &cnt, 0);

        for (int i = 0; i < www; i++)
        {
            for (int j = 0; j < hhh; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    //cout << data[i * www + j] << endl;
                    data[i * hhh * 4 + j * 4 + k] = static_cast <char>(128);
                }
            }
        }

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, www, hhh, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);
    }
    void LoadObj(string name, int shader, Window& window,int &sizeobjmain)
    {
        LoadObj(name, "0", window, sizeobjmain);

    }
    void LoadObj(string name, string shader, Window& window,int& sizeobjmain)
    {

        ProjectionMatrix = perspective(
            radians(53.f),
            static_cast <float>(1.6),
            (float)0.2,
            (float)80
        );


        if (name[name.length() - 3] == 'o' && name[name.length() - 2] == 'b' && name[name.length() - 1] == 'j')
        {

            Clock tti;
            float ttu;
            /*LoadTexture("textures\\bob01_diffuse.png", texture[0]);
            LoadTexture("textures\\eyebrow009.png", texture[1]);
            LoadTexture("textures\\green_eye.png", texture[2]);
            LoadTexture("textures\\eyelashes04.png", texture[3]);
            LoadTexture("textures\\male_casualsuit02_diffuse.png", texture[4]);
            LoadTexture("textures\\old_lightskinned_female_diffuse.png", texture[5]);
            LoadTexture("textures\\shoes03_diffuse.png", texture[6]);
            LoadTexture("textures\\teeth.png", texture[7]);
            LoadTexture("textures\\tongue01_diffuse.png", texture[8]);*/



            LoadFont("Verdana_B_alpha.png", font);

            string namemtl;
            for (int i = 0; i < name.length() - 3; i++)
            {
                namemtl += name[i];
            }
            namemtl += "mtl";


            fstream filemtl(namemtl);
            getline(filemtl, str);
            getline(filemtl, str);
            getline(filemtl, str);

            while (!filemtl.eof())
            {
                filemtl >> str;
                if (str == "newmtl")
                {
                    filemtl >> str;
                    nametex[nametexsize] = str;
                    bool sosi = true;
                    while (sosi)
                    {
                        filemtl >> str;
                        if (str == "map_Kd")
                        {
                            filemtl >> str;
                            nametex[nametexsize + 1] = str;


                            LoadTexture(str, texture[texsize]);

                            sosi = false;
                            nametexsize += 2;
                            texsize += 1;
                        }
                    }
                }
            }
            filemtl.close();

            LoadTexture("pngwing.png", normalmaptex);

            for (int i = 0; i < nametexsize; i++)
            {
                if (i % 2 == 0)
                {
                    cout << nametex[i] << " ";
                }
                else
                {
                    cout << nametex[i] << endl;

                }
            }



            fstream file1(name);

            getline(file1, str);
            getline(file1, str);
            getline(file1, str);



            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, width, 0, heigh, -1, 1);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glDisable(GL_DEPTH_TEST);

            glUseProgram(0);
            glPushMatrix();







            tti.restart();
            while (!file1.eof())
            {

                ttu = tti.getElapsedTime().asSeconds();

                Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    else if (event.type == sf::Event::Resized)
                        glViewport(0, 0, event.size.width, event.size.height);
                }


                file1 >> str;

                if (str == "v")
                {
                    if (vnf == 3)
                    {
                        sizeobj1++;
                        //cout << endl;
                    }
                    sizevert1 += 3;
                    vnf = 1;
                }
                else if (str == "vt")
                {
                    sizetex1 += 2;
                    vnf = 2;
                }            
                else if (str == "f")
                {
                    sizeindex1 += 3;
                    vnf = 3;
                }

                if (ttu > 0.01)
                {

                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                    glPushMatrix();
                    DrawTxt(to_string(sizevert1 + sizeindex1), width - 32 * 10, heigh - 64, 1, font);
                    glPopMatrix();
                    window.display();
                    tti.restart();
                }
            }
            file1.close();

            vnf = 0;


            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sizevert1, NULL, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);


            glGenBuffers(1, &TNBO);
            glBindBuffer(GL_ARRAY_BUFFER, TNBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sizeindex1, NULL, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glGenBuffers(1, &TBO);
            glBindBuffer(GL_ARRAY_BUFFER, TBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sizeindex1 * 2, NULL, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);


          

            glGenBuffers(1, &IBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * sizeindex1, NULL, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);






            int numstr = 4;
            fstream file(name);

            getline(file, str);
            getline(file, str);
            getline(file, str);


            tti.restart();

            float *texmas = new float[sizetex1];
            //cout << sizetex1 << endl;

            while (!file.eof())
            {
                file >> str;



                ttu = tti.getElapsedTime().asSeconds();

                Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    else if (event.type == sf::Event::Resized)
                        glViewport(0, 0, event.size.width, event.size.height);
                    if (Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        window.close();
                    }
                }

                if (str == "v")
                {
                    if (vnf == 3)
                    {
                        sizeobj++;
                        //cout << endl;
                    }



                    file >> vert[0] >> vert[1] >> vert[2];
                    glBindBuffer(GL_ARRAY_BUFFER, VBO);
                    glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * sizevert, sizeof(float) * 3, vert);
                    glBindBuffer(GL_ARRAY_BUFFER, 0);

                    if (sizevert == 0 || vnf == 3)
                    {
                        maxXlocal[sizeobj] = vert[0];
                        maxYlocal[sizeobj] = vert[1];
                        maxZlocal[sizeobj] = vert[2];
                        minXlocal[sizeobj] = vert[0];
                        minYlocal[sizeobj] = vert[1];
                        minZlocal[sizeobj] = vert[2];
                    }

                    vnf = 1;

                    if (maxXlocal[sizeobj] < vert[0]) maxXlocal[sizeobj] = vert[0];
                    if (maxYlocal[sizeobj] < vert[1]) maxYlocal[sizeobj] = vert[1];
                    if (maxZlocal[sizeobj] < vert[2]) maxZlocal[sizeobj] = vert[2];
                    if (minXlocal[sizeobj] > vert[0]) minXlocal[sizeobj] = vert[0];
                    if (minYlocal[sizeobj] > vert[1]) minYlocal[sizeobj] = vert[1];
                    if (minZlocal[sizeobj] > vert[2]) minZlocal[sizeobj] = vert[2];




                    sizevert += 3;

                }
                else if (str == "vt")
                {
                    if (vnf == 1)
                    {
                        numtexstr[sizeobj] = sizevert / 3;
                    }
                    file >> texmas[sizetex] >> texmas[sizetex+1];

                    //texmas[sizetex] = 1 - texmas[sizetex];
                    texmas[sizetex + 1] = 1 - texmas[sizetex + 1];
                    //cout << texmas[sizetex] << " " << texmas[sizetex + 1] << endl;

                    vnf = 2;
                    sizetex += 2;
                }                
                else if (str == "usemtl")
                {
                    file >> str;
                    for (int i = 0; i < nametexsize; i += 2)
                    {
                        if (nametex[i] == str)
                        {
                            nametexnum = i / 2;
                            //cout << nametexnum << endl;
                            i = nametexsize;
                            //cout << nametexnum << endl;
                        }
                    }



                }
                else if (str == "f")
                {


                    float tex[2];

                    

                        file >> index[0] >> huita >> texidx[0] >> 
                            index[1] >> huita >> texidx[1] >> 
                            index[2] >> huita >> texidx[2];
                    

                        //cout << texidx[0] << " " << texidx[1] << " " << texidx[2] << endl;

                    
                    index[0]--;
                    index[1]--;
                    index[2]--;
                    texidx[0]--;
                    texidx[1]--;
                    texidx[2]--;
                    musor++;

                  


                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
                    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * sizeindex, sizeof(GLuint) * 3, index);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

                  
                    for (int r = 0; r < 3; r++)
                    {
                        tex[0] = texmas[texidx[r] * 2];
                        tex[1] = texmas[texidx[r] * 2 + 1];

                        



                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, TBO);
                        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * index[r] * 2, sizeof(float) * 2, tex);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                    }

                   





                    for (int r = 0; r < 3; r++)
                    {


                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, TNBO);
                        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * index[r], sizeof(float), &nametexnum);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                    }








                    vnf = 3;



                    sizeindex += 3;
                }


                numstr++;
                if (ttu > 0.01)
                {
                    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                    glPushMatrix();
                    DrawTxt(to_string(sizevert + sizeindex), width - 32 * 10, heigh - 64, 1, font);
                    glPopMatrix();
                    window.display();
                    tti.restart();
                }


            }
            sizeobj++;


            file.close();

            delete[] texmas;

            if (shader != '0')
            {
                LoadShader(shader);
                UseShader = true;
            }
            else
            {
                UseShader = false;
            }




           
        }
        else if (name[name.length() - 3] == 'd' && name[name.length() - 2] == 'a' && name[name.length() - 1] == 'e')
        {




        }
        sizeobjmain += 1;
        
    }

    bool checkcas(Player& p, int num)
    {
        if (p.x + p.w / 2 >= minX[num] && p.x - p.w / 2 <= maxX[num] && p.y + p.w / 2 >= minY[num] && p.y - p.w / 2 <= maxY[num] && p.z + p.h >= minZ[num] && p.z <= maxZ[num])
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    void DrawObj(float xf, float yf, float zf, float sizef, float r, float g, float b,float AngleXf, float AngleYf, float AngleZf, Player& p,bool usecollision)
    {
        if (UseShader)glUseProgram(prog);
        else glUseProgram(0);

        mat4 ModelMatrix(1.f);
        ModelMatrix = translate(ModelMatrix, vec3(xf, yf, zf));
        ModelMatrix = rotate(ModelMatrix, radians(AngleZf), vec3(0.f, 0.f, 1.f));
        ModelMatrix = rotate(ModelMatrix, radians(AngleYf), vec3(0.f, 1.f, 0.f));
        ModelMatrix = rotate(ModelMatrix, radians(AngleXf), vec3(1.f, 0.f, 0.f));
        ModelMatrix = scale(ModelMatrix, vec3(1.f));

        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-0.1 * mnojitel, 0.1 * mnojitel, -0.1, 0.1, 0.2, 80);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //cout << p.x << " " << p.y << " " << p.z << endl;
        //cout << p.AngleX << " " << p.AngleZ << endl;
        vec3 CamPos(p.x, p.y, p.z + p.h);
        vec3 CamFront(abs(sin(-p.AngleX / 180 * PI)) * sin(p.AngleZ / 180 * PI), abs(sin(-p.AngleX / 180 * PI)) * cos(p.AngleZ / 180 * PI), -cos(-p.AngleX / 180 * PI));
        vec3 WorldUp(0.f, 0.f, 1.f);
        mat4 ViewMatrix;
        ViewMatrix = lookAt(CamPos, CamPos + CamFront, WorldUp);
       
        vec3 color(r, g, b);
        vec3 lightpos = vec3(0, 0, 10);
        //cout << p.x << " " << p.y << " " << p.z << endl;
        GLfloat shootf = p.shoot;





        /*for (int e = 0; e < 10; e++)
        {
            glActiveTexture(GL_TEXTURE0+e);
            glBindTexture(GL_TEXTURE_2D, texture[e]);
            glUniform1i(glGetUniformLocation(prog, "texture[" + (char)e +']'), e);
        }*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glUniform1i(glGetUniformLocation(prog, "texture[0]"), 0);

        glActiveTexture(GL_TEXTURE0 + 1);
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glUniform1i(glGetUniformLocation(prog, "texture[1]"), 1);

        glActiveTexture(GL_TEXTURE0 + 2);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glUniform1i(glGetUniformLocation(prog, "texture[2]"), 2);

        glActiveTexture(GL_TEXTURE0 + 3);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glUniform1i(glGetUniformLocation(prog, "texture[3]"), 3);
        
        glActiveTexture(GL_TEXTURE0 + 4);
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        glUniform1i(glGetUniformLocation(prog, "texture[4]"), 4);

        glActiveTexture(GL_TEXTURE0 + 5);
        glBindTexture(GL_TEXTURE_2D, texture[5]);
        glUniform1i(glGetUniformLocation(prog, "texture[5]"), 5);

        glActiveTexture(GL_TEXTURE0 + 6);
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        glUniform1i(glGetUniformLocation(prog, "texture[6]"), 6);

        glActiveTexture(GL_TEXTURE0 + 7);
        glBindTexture(GL_TEXTURE_2D, texture[7]);
        glUniform1i(glGetUniformLocation(prog, "texture[7]"), 7);

        glActiveTexture(GL_TEXTURE0 + 8);
        glBindTexture(GL_TEXTURE_2D, texture[8]);
        glUniform1i(glGetUniformLocation(prog, "texture[8]"), 8);

        glActiveTexture(GL_TEXTURE0 + 9);
        glBindTexture(GL_TEXTURE_2D, texture[9]);
        glUniform1i(glGetUniformLocation(prog, "texture[9]"), 9);


        glActiveTexture(GL_TEXTURE0 + 10);
        glBindTexture(GL_TEXTURE_2D, normalmaptex);
        glUniform1i(glGetUniformLocation(prog, "normalmap"), 10);

        

        glUniformMatrix4fv(glGetUniformLocation(prog, "ProjectionMat"), 1, GL_FALSE, value_ptr(ProjectionMatrix));
        glUniformMatrix4fv(glGetUniformLocation(prog, "ModelMat"), 1, GL_FALSE, value_ptr(ModelMatrix));
        glUniformMatrix4fv(glGetUniformLocation(prog, "ViewMat"), 1, GL_FALSE, value_ptr(ViewMatrix));
        glUniform3fv(glGetUniformLocation(prog, "color"), 1, value_ptr(color));
        glUniform3fv(glGetUniformLocation(prog, "lightpos"), 1, value_ptr(lightpos));
        glUniform3fv(glGetUniformLocation(prog, "campos"), 1, value_ptr(CamPos));

        glUniform1f(glGetUniformLocation(prog, "shoot"), shootf);


        x = xf;
        y = yf;
        z = zf;
        size = sizef;
        glPushMatrix();
        //glLightfv(GL_LIGHT0, GL_POSITION, light);

        glTranslatef(x, y, z);
        //glRotatef(AngleZf, 1, 0, 0);
        glColor4f(r, g, b, 1);



        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindBuffer(GL_ARRAY_BUFFER, TNBO);
        glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, NULL);
        glBindBuffer(GL_ARRAY_BUFFER, 0);


       




        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glEnableVertexAttribArray(3);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glDrawElements(GL_TRIANGLES, sizeindex, GL_UNSIGNED_INT, NULL);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glDisableVertexAttribArray(3);
        glDisableVertexAttribArray(2);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);






        glPopMatrix();

        glActiveTexture(GL_TEXTURE0);

        if (usecollision)
        {
            for (int i = 0; i < sizeobj; i++)
            {
                maxX[i] = x + maxXlocal[i];
                maxY[i] = y + maxYlocal[i];
                maxZ[i] = z + maxZlocal[i];
                minX[i] = x + minXlocal[i];
                minY[i] = y + minYlocal[i];
                minZ[i] = z + minZlocal[i];


                if (p.x + p.w / 2 >= minX[i] && p.x - p.w / 2 <= maxX[i] && p.y + p.w / 2 >= minY[i] && p.y - p.w / 2 <= maxY[i] && p.z + p.h >= minZ[i] && p.z <= maxZ[i])
                {

                    if (abs(p.z + p.h - minZ[i]) < abs(p.z - maxZ[i]))
                    {
                        if (abs(p.z + p.h - minZ[i]) < abs(p.x - p.w / 2 - maxX[i]))
                        {
                            if (abs(p.z + p.h - minZ[i]) < abs(p.x + p.w / 2 - minX[i]))
                            {
                                if (abs(p.z + p.h - minZ[i]) < abs(p.y - p.w / 2 - maxY[i]))
                                {
                                    if (abs(p.z + p.h - minZ[i]) < abs(p.y + p.w / 2 - minY[i]))
                                    {
                                        p.collisZ = -1;
                                        cZ[i] = -1;
                                    }
                                }
                            }
                        }

                    }
                    else if (abs(p.z + p.h - minZ[i]) > abs(p.z - maxZ[i]))
                    {
                        if (abs(p.z - maxZ[i]) < abs(p.x - p.w / 2 - maxX[i]))
                        {
                            if (abs(p.z - maxZ[i]) < abs(p.x + p.w / 2 - minX[i]))
                            {
                                if (abs(p.z - maxZ[i]) < abs(p.y - p.w / 2 - maxY[i]))
                                {
                                    if (abs(p.z - maxZ[i]) < abs(p.y + p.w / 2 - minY[i]))
                                    {
                                        p.collisZ = 1;
                                        cZ[i] = 1;
                                        p.z = maxZ[i];
                                        p.onGround = true;
                                    }
                                }
                            }
                        }
                    }
                    if (abs(p.x + p.w / 2 - minX[i]) < abs(p.x - p.w / 2 - maxX[i]))
                    {
                        if (abs(p.x + p.w / 2 - minX[i]) < abs(p.y - p.w / 2 - maxY[i]))
                        {
                            if (abs(p.x + p.w / 2 - minX[i]) < abs(p.y + p.w / 2 - minY[i]))
                            {
                                if (abs(p.x + p.w / 2 - minX[i]) < abs(p.z - maxZ[i]))
                                {
                                    if (abs(p.x + p.w / 2 - minX[i]) < abs(p.z + p.h - minZ[i]))
                                    {

                                        if (maxZ[i] - p.z <= 1.3 && p.onGround && p.dx > 0)
                                        {
                                            p.z = maxZ[i];
                                            p.x += 0.1;
                                        }
                                        else
                                        {

                                            p.collisX = -1;
                                            cX[i] = -1;

                                        }

                                    }
                                }
                            }
                        }
                    }
                    else if (abs(p.x + p.w / 2 - minX[i]) > abs(p.x - p.w / 2 - maxX[i]))
                    {
                        if (abs(p.x - p.w / 2 - maxX[i]) < abs(p.y - p.w / 2 - maxY[i]))
                        {
                            if (abs(p.x - p.w / 2 - maxX[i]) < abs(p.y + p.w / 2 - minY[i]))
                            {
                                if (abs(p.x - p.w / 2 - maxX[i]) < abs(p.z - maxZ[i]))
                                {
                                    if (abs(p.x - p.w / 2 - maxX[i]) < abs(p.z + p.h - minZ[i]))
                                    {

                                        if (maxZ[i] - p.z <= 1.3 && p.onGround && p.dx < 0)
                                        {
                                            p.z = maxZ[i];
                                            p.x -= 0.1;
                                        }
                                        else
                                        {

                                            p.collisX = 1;
                                            cX[i] = 1;

                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (abs(p.y + p.w / 2 - minY[i]) < abs(p.y - p.w / 2 - maxY[i]))
                    {
                        if (abs(p.y + p.w / 2 - minY[i]) < abs(p.x - p.w / 2 - maxX[i]))
                        {
                            if (abs(p.y + p.w / 2 - minY[i]) < abs(p.x + p.w / 2 - minX[i]))
                            {
                                if (abs(p.y + p.w / 2 - minY[i]) < abs(p.z - maxZ[i]))
                                {
                                    if (abs(p.y + p.w / 2 - minY[i]) < abs(p.z + p.h - minZ[i]))
                                    {

                                        if (maxZ[i] - p.z <= 1.3 && p.onGround && p.dy > 0)
                                        {
                                            p.z = maxZ[i];
                                            p.y += 0.1;
                                        }
                                        else
                                        {

                                            p.collisY = -1;
                                            cY[i] = -1;

                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (abs(p.y + p.w / 2 - minY[i]) > abs(p.y - p.w / 2 - maxY[i]))
                    {
                        if (abs(p.y - p.w / 2 - maxY[i]) < abs(p.x - p.w / 2 - maxX[i]))
                        {
                            if (abs(p.y - p.w / 2 - maxY[i]) < abs(p.x + p.w / 2 - minX[i]))
                            {
                                if (abs(p.y - p.w / 2 - maxY[i]) < abs(p.z - maxZ[i]))
                                {
                                    if (abs(p.y - p.w / 2 - maxY[i]) < abs(p.z + p.h - minZ[i]))
                                    {

                                        if (maxZ[i] - p.z <= 1.3 && p.onGround && p.dy < 0)
                                        {
                                            p.z = maxZ[i];
                                            p.y -= 0.1;
                                        }
                                        else
                                        {

                                            p.collisY = 1;
                                            cY[i] = 1;

                                        }
                                    }
                                }
                            }
                        }
                    }


                    /*if (cZ[i] == 1)
                    {
                        if (cX[i] != 0)
                        {
                            p.collisX = 0;
                        }
                        if (cY[i] != 0)
                        {
                            p.collisY = 0;
                        }
                    }*/



                }
                else
                {
                    if (cX[i] != 0)
                    {
                        p.collisX = 0;
                        cX[i] = 0;
                    }
                    if (cY[i] != 0)
                    {
                        p.collisY = 0;
                        cY[i] = 0;
                    }
                    if (cZ[i] != 0)
                    {
                        if (cZ[i] == 1)
                        {
                            p.onGround = false;
                        }
                        p.collisZ = 0;
                        cZ[i] = 0;
                    }
                }

            }
        }
    }
};




class Collada
{
public:
    GLuint VBO;
    GLuint IBO;
    GLuint TBO;
    string texname[1000];
    string vertf;
    string texf;
    float vert;
    float tex;

    int sizetexname;
    int sizevert;
    int sizetex;
    int sizeindex;



    void LoadObj(string name, string shader, Window& window)
    {


        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 1000, NULL, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glGenBuffers(1, &TBO);
        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 1000, NULL, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 1000, NULL, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



        TiXmlDocument doc(name.c_str());
        if (!doc.LoadFile())
        {
            cout << "object is missing" << endl;
            return;
        }
        TiXmlElement* COLLADA = doc.FirstChildElement("COLLADA");
        TiXmlElement* library_images = COLLADA->FirstChildElement("library_images");
        TiXmlElement* image = library_images->FirstChildElement("image");
        texname[0] = image->Attribute("name");
        cout << texname[0] << endl;
        TiXmlElement* library_geometries = COLLADA->FirstChildElement("library_geometries");
        TiXmlElement* geometry = library_geometries->FirstChildElement("geometry");
        TiXmlElement* mesh = geometry->FirstChildElement("mesh");
        TiXmlElement* source = mesh->FirstChildElement("source");
        TiXmlElement* float_array = source->FirstChildElement("float_array");
        vertf = float_array->GetText();
        //cout << vertf << endl;
        string vertstr;
        for (int i = 0; i < vertf.size(); i++)
        {
            if (vertf[i] != ' ')
            {
                vertstr += vertf[i];
            }
            else
            {
                vert = stof(vertstr);
                vertstr = "";
                //cout << vert << endl;
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * sizevert, sizeof(float), &vert);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                sizevert++;
            }
        }
        vert = stof(vertstr);
        vertstr = "";
        //cout << vert << endl;
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * sizevert, sizeof(float), &vert);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        sizevert++;


        source = source->NextSiblingElement("source");
        source = source->NextSiblingElement("source");
        float_array = source->FirstChildElement("float_array");
        texf = float_array->GetText();
        string texstr;
        for (int i = 0; i < texf.size(); i++)
        {
            if (texf[i] != ' ')
            {
                texstr += texf[i];
            }
            else
            {
                tex = stof(texstr);
                texstr = "";
                //cout << tex << endl;
                glBindBuffer(GL_ARRAY_BUFFER, TBO);
                glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * sizetex, sizeof(float), &tex);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                sizetex++;
            }
        }
        tex = stof(texstr);
        texstr = "";
        //cout << tex << endl;
        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * sizetex, sizeof(float), &tex);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        sizetex++;

    }
    void LoadObj(string name, int shader, Window& window)
    {
        LoadObj(name, "0", window);

    }





};



class Enemy
{
public:
    float x, y, z;
    float dx, dy, dz;
    float AngleX, AngleZ;
    int collisX = 0;
    int collisY = 0;
    int collisZ = 0;
    float speed = 1;
    bool onGround;
    Object model;



    float jmp;
    float tm;
    int hits = 0;

    Clock clX;
    float tmX = 1;
    float tmX1 = 1;
    float tmX2 = 1;
    Clock clY;
    float tmY = 1;
    float tmY1 = 1;
    float tmY2 = 1;


    float dirX = 0;
    float dirY = 0;
    int diX = 0;
    int diY = 0;
    int vspX = 0;
    int vspY = 0;

    void gravity(float time, float tm1)
    {

        dz = jmp * time - (tm + tm1) * time;

    }

    void key(float time)
    {




        if (diX == 0)
        {
            if (vspX == 0)
            {
                clX.restart();
                vspX = 1;
            }
            tmX = tmX1 - clX.getElapsedTime().asSeconds() * 8;
            tmX2 = tmX;
            if (tmX < 0 || collisX != 0 || collisY != 0)
            {
                tmX = 0;
                tmX2 = tmX;
            }
        }
        else
        {
            if (vspX == 1)
            {
                clX.restart();
                vspX = 0;
            }
            tmX = tmX2 + clX.getElapsedTime().asSeconds() * 8;
            tmX1 = tmX;
            if (tmX > 1)
            {
                tmX = 1;
                tmX1 = tmX;
            }
        }


        if (diY == 0)
        {
            if (vspY == 0)
            {
                clY.restart();
                vspY = 1;
            }
            tmY = tmY1 - clY.getElapsedTime().asSeconds() * 8;
            tmY2 = tmY;
            if (tmY < 0 || collisX != 0 || collisY != 0)
            {
                tmY = 0;
                tmY2 = tmY;
            }

        }
        else
        {
            if (vspY == 1)
            {
                clY.restart();
                vspY = 0;
            }
            tmY = tmY2 + clY.getElapsedTime().asSeconds() * 8;
            tmY1 = tmY;
            if (tmY > 1)
            {
                tmY = 1;
                tmY1 = tmY;
            }

        }







        dy = cos((PI * AngleZ) / 180) * time * speed * 0.15 * dirY * tmY + -sin((PI * AngleZ) / 180) * time * speed * 0.15 * dirX * tmX;
        dx = sin((PI * AngleZ) / 180) * time * speed * 0.15 * dirY * tmY + cos((PI * AngleZ) / 180) * time * speed * 0.15 * dirX * tmX;








        if (collisX == 0)
        {
            x += dx * 0.1;
        }
        else if (collisX == 1)
        {
            if (dx > 0)
                x += dx * 0.1;
        }
        else if (collisX == -1)
        {
            if (dx < 0)
                x += dx * 0.1;
        }

        if (collisY == 0)
        {
            y += dy * 0.1;
        }
        else if (collisY == 1)
        {
            if (dy > 0)
                y += dy * 0.1;
        }
        else if (collisY == -1)
        {
            if (dy < 0)
                y += dy * 0.1;
        }

        if (collisZ == 0)
        {
            z += dz * 0.1;

        }
        else if (collisZ == 1)
        {
            if (dz > 0)
            {
                z += dz * 0.1;

            }
        }
        else if (collisZ == -1)
        {
            //dz = -1;
            if (dz < 0)
            {
                z += dz * 0.1;

            }
        }

    }



};



class Menu
{
public:
    unsigned int fontf;
    bool running = true;



    void DrawMenu(Window& window, bool& Multipleer, bool& CrCon)
    {
        bool asdf = false;
        while (running)
        {
            if (!Mouse::isButtonPressed(Mouse::Left))
            {
                asdf = true;
            }


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
            //cout << p.onGround << endl;

            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPushMatrix();

            if (x > 140 && x < 140 + 32 * 14 && y > heigh / 2 && y < heigh / 2 + 32)
            {
                DrawTxt("Одиночная игра", 140 / 1.3, heigh / 2, 1.3, fontf);
                DrawTxt("Мультиплеер", 160 + width / 2, heigh / 2, 1, fontf);
                if (Mouse::isButtonPressed(Mouse::Left) && asdf)
                {
                    Multipleer = false;
                    return;
                }
            }
            else if (x > 120 + width / 2 && x < 120 + width / 2 + 32 * 11 && y>heigh / 2 && y < heigh / 2 + 32)
            {
                DrawTxt("Одиночная игра", 140, heigh / 2, 1, fontf);
                DrawTxt("Мультиплеер", 120 + width / 2, heigh / 2, 1.3, fontf);
                if (Mouse::isButtonPressed(Mouse::Left) && asdf)
                {
                    Multipleer = true;
                    DrawMenu2(window, CrCon);
                    return;
                }
            }
            else
            {
                DrawTxt("Одиночная игра", 140, heigh / 2, 1, fontf);
                DrawTxt("Мультиплеер", 160 + width / 2, heigh / 2, 1, fontf);
            }
            glPopMatrix();
            glFinish();



            window.display();
        }

    }

    void DrawMenu2(Window& window, bool& CrCon)
    {
        bool asdf = false;
        while (running)
        {
            if (!Mouse::isButtonPressed(Mouse::Left))
            {
                asdf = true;
            }

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
            //cout << p.onGround << endl;

            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPushMatrix();

            if (x > 140 && x < 140 + 32 * 14 && y > heigh / 2 && y < heigh / 2 + 32)
            {
                DrawTxt("Подключиться", 170 / 1.3, heigh / 2, 1.3, fontf);
                DrawTxt("Создать", 190 + width / 2, heigh / 2, 1, fontf);
                if (Mouse::isButtonPressed(Mouse::Left) && asdf)
                {
                    CrCon = false;
                    return;
                }
            }
            else if (x > 120 + width / 2 && x < 120 + width / 2 + 32 * 11 && y>heigh / 2 && y < heigh / 2 + 32)
            {
                DrawTxt("Подключиться", 170, heigh / 2, 1, fontf);
                DrawTxt("Создать", 170 + width / 2, heigh / 2, 1.3, fontf);
                if (Mouse::isButtonPressed(Mouse::Left) && asdf)
                {
                    CrCon = true;
                    return;
                }
            }
            else
            {
                DrawTxt("Подключиться", 170, heigh / 2, 1, fontf);
                DrawTxt("Создать", 190 + width / 2, heigh / 2, 1, fontf);
            }
            glPopMatrix();
            glFinish();



            window.display();
        }

    }

};




