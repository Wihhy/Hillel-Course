// Lesson13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "glfwbgi.h"

//struct SStar
//{
//	Graph::Point coord;
//	int radius;
//	int ray_height;
//	unsigned int color;
//};

class CAstroObject
{
public:

    CAstroObject(Graph::Point position, int size, unsigned int color);

    ~CAstroObject();

    // ---------------- Property "Size"
    // Getter
    int GetSize()
    {
        return radius;
    }
    // Setter
    void SetSize(int newSize)
    {
        if (newSize < 5)
        {
            newSize = 5;
        }

        if (newSize > 200)
        {
            newSize = 200;
        }

        radius = newSize;
        ray_height = newSize / 5;
    }
    // ---------------------------------- 

    void Move(int to_x, int y);
protected:
    Graph::Point coord;
    int radius;
    int ray_height;
    unsigned int base_color;
};

CAstroObject::CAstroObject(Graph::Point position, int size, unsigned int color)
{
    coord = position;
    radius = size;
    base_color = color;
}

CAstroObject::~CAstroObject()
{
    printf("Destroyed object at %d %d", coord.x, coord.y);
}

void CAstroObject::Move(int to_x, int to_y)
{
    // Verify X,Y

    coord.x = to_x;
    coord.y = to_y;
}

// -------------------------------------------------------------------------------

class CPlanet : public CAstroObject
{
public:
    CPlanet() = delete;
    CPlanet(Graph::Point position, int size, unsigned int color1, unsigned int color2);

    void Draw();

private:
    unsigned int target_color;

    struct SColor
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    };

    SColor ToRGB(unsigned int color) {
        SColor result;
        result.b = (color >> 16) & 0xFF;
        result.g = (color >> 8) & 0xFF;
        result.r = color & 0xFF;
        return result;
    }
};

// --------------------------------------------------------------------------

//class CStar
//{
//public:
//    // constructors declaration
//    CStar() = delete;  // new syntax
//
//    //CStar(unsigned int color);
//
//    CStar(Graph::Point position, int size, unsigned int newColor);
//
//    // destructor declaration
//    ~CStar();
//
//    void DrawStar(); // Method declaration
//
//    // ---------------- Property "Size"
//    // Getter
//    int GetSize()
//    {
//        return radius;
//    }
//    // Setter
//    void SetSize(int newSize)
//    {
//        if (newSize < 5)
//        {
//            newSize = 5;
//        }
//
//        if (newSize > 200)
//        {
//            newSize = 200;
//        }
//
//        radius = newSize;
//        ray_height = newSize / 5;
//    }
//    // ---------------------------------- 
//
//private:
//
//    //CStar();  // old syntax
//
//    Graph::Point coord;
//    int radius;
//    int ray_height;
//    unsigned int color;
//};

class CStar : public CAstroObject
{
public:
    // constructors declaration
    CStar() = delete;  // new syntax

    //CStar(unsigned int color);

    CStar(Graph::Point position, int size, unsigned int newColor);

    void DrawStar(); // Method declaration

private:
    int ray_height;
};

CStar::CStar(Graph::Point position, int size, unsigned int newColor)
    : CAstroObject(position, size, newColor)
{
    ray_height = size / 5;
}

//// Constructor definition 1
//CStar::CStar()
//{
//    color = Graph::Color::YellowGreen;
//    radius = 20;
//    ray_height = 5;
//    coord = { 100,100 };
//}
//
//// Constructor definition 2
//CStar::CStar(unsigned int newColor)
//{
//    //color = color;
//    this->color = newColor;
//    radius = 20;
//    ray_height = 5;
//    coord = { 100,100 };
//}

//CStar::CStar(Graph::Point position, int size, unsigned int newColor)
//{
//    this->color = newColor;
//    radius = size;
//    ray_height = size / 5;
//    coord = position;
//}

// Destructor definition
//CStar::~CStar()
//{
//    printf("Object cstar at (%d %d) destroyed\n",
//        coord.x,
//        coord.y
//        );
//}

// Method definition
void CStar::DrawStar()
{
    //this->
    Graph::FillEllipseSector(this->coord.x, coord.y, radius, radius, 0, 360, base_color);
    for (int angle = 0; angle < 360; angle += 40)
    {
        Graph::FillEllipseSector(coord.x, coord.y, radius + ray_height, radius + ray_height, angle, angle + 10, base_color);
    }
}

CPlanet::CPlanet(Graph::Point position, int size, unsigned int color1, unsigned int color2)
    : CAstroObject(position, size, color1)
{
    target_color = color2;
}

void CPlanet::Draw()
{
    SColor base = ToRGB(base_color);
    SColor target = ToRGB(target_color);
    int i = radius / 2;
    int rI = (target.r - base.r) / i;
    int gI = (target.g - base.g) / i;
    int bI = (target.b - base.b) / i;

    int x = coord.x;
    int y = coord.y;
    int tmp_radius = radius;
    while (tmp_radius > 0) {
        Graph::FillEllipseSector(x, y, tmp_radius, tmp_radius, 0, 360, Graph::GetColor(base.r, base.g, base.b));

        tmp_radius -= 2;
        base.r += rI;
        base.b += bI;
        base.g += gI;
        x++;
        y--;
    }
}

int main()
{
    std::cout << "Hello World!\n";

    CStar star1({300,100},30, Graph::Color::YellowGreen);

    //star1.color = Graph::Color::YellowGreen;
    //star1.radius = 20;
    //star1.ray_height = 5;
    //star1.coord = { 200,200 };

    //CStar star2; // default constructor

    CStar star2({ 200,200 }, 30, Graph::Color::YellowGreen);

    CPlanet planet1({ 700,200 }, 150, Graph::Color::Blue, Graph::Color::Green);
    {      
        CStar star3({ 100,300 }, 20, Graph::Color::Red);
        //star3.coord = { 100, 300 };

        Graph::InitGraph(1000, 800, "oop");

        star2.SetSize(500);
        star3.SetSize(-10);

        star1.DrawStar();
        //star2.DrawStar();
        star3.DrawStar();

        //DrawPlanet(700, 200, 150, Graph::Color::Blue, Graph::Color::Green);
        planet1.Draw();
    }

    Graph::SwapBuffers();
    Graph::ReadKey();

    star1.Move(50, 50);
    planet1.Move(500, 500);

    Graph::ClearDevice(Graph::Color::Black);
    star1.DrawStar();
    //star2.DrawStar();
    planet1.Draw();

    Graph::SwapBuffers();
    Graph::ReadKey();

    Graph::CloseGraph();
}

