// #include "glfwbgi.h"
// #include <iostream>
//
//
// using namespace Graph;
//
//
// void RunGameLoop()
// {
//     int i = 0;
//     int x1 = 0;
//     while (!Graph::ShouldClose())
//     {
//         // Check input
//         bool is7pressed = IsKeyPressed(GLFW_KEY_7);
//
//         // Logic
//         if (IsKeyPressed(GLFW_KEY_8))
//         {
//             i += 1;
//         }
//
//         x1 += 5;
//
//         if (x1 >= 1600)
//         {
//             x1 = 0;
//             printf("the end\n");
//         }
//
//         // Painting
//         Graph::ClearDevice(Color::White);
//
//         // ...
//         if (is7pressed)
//             FillEllipseSector(100, 100, 20, 20, 0, 360, Color::Red);
//
//         FillEllipseSector(i, 100, 20, 20, 0, 360, Color::Blue);
//
//         FillEllipseSector(x1, 200, 20, 20, 0, 360, Color::Violet);
//
//         Graph::SwapBuffers();
//
//         Graph::Delay(1000 / 50);
//     }
// }
//
// struct SStar
// {
//     Graph::Point coord;
//
//     int radius;
//     int ray_height;
//     unsigned int color;
// };
//
// //void DrawStar2(SStar star )
// void DrawStar2(const SStar & star)
// {
//     Graph::FillEllipseSector(star.coord.x, star.coord.y, star.radius, star.radius, 0, 360, star.color);
//     for (int angle = 0; angle < 360; angle += 40)
//     {
//         Graph::FillEllipseSector(
//             star.coord.x,
//             star.coord.y,
//             star.radius + star.ray_height,
//             star.radius + star.ray_height,
//             angle, angle + 10,
//             star.color);
//     }
// }
//
// void DrawStar(int x, int y, int radius, int ray_height, unsigned int color)
// {
//     Graph::FillEllipseSector(x, y, radius, radius, 0, 360, color);
//     for (int angle = 0; angle < 360; angle += 40)
//     {
//         Graph::FillEllipseSector(x, y, radius + ray_height, radius + ray_height, angle, angle + 10, color);
//     }
// }
//
// void GraphWindow()
// {
//     int a;
//     //printf("Enter a number: ");
//     //std::cin >> a;
//
//     if (!Graph::InitGraph(1600, 1200, "Test"))
//     {
//         printf("Error! cannot run graph\n");
//     }
//
//     Graph::ClearDevice(Graph::GetColor(0, 255, 0)); // Fill with green
//
//     Graph::SetLineWidth(5.0);
//     Graph::DrawLine(0, 100, 500, 100, Graph::Color::Black); // black line
//
//     Graph::DrawRectangle(50, 200, 150, 400, Graph::Color::Blue);
//
//     Graph::FillRectangle(50 + 200, 200, 150 + 200, 400, Graph::Color::Blue);
//
//     Graph::SetLineWidth(1.0);
//
//     Graph::DrawRectangle(50 + 400, 200, 150 + 400, 400, Graph::Color::Blue);
//
//     Graph::FillEllipseSector(100, 100, 50, 50, 0, 360, Graph::Color::Red);
//     Graph::FillEllipseSector(100, 100, 50, 50, 0, 45, Graph::Color::Amethyst);
//
//     Graph::FillEllipseSector(100 + 100, 100, 50, 50, 0, 360, Graph::Color::Red);
//     Graph::FillEllipseSector(100 + 100, 100, 50, 50, 45, 90, Graph::Color::Amethyst);
//     Graph::FillEllipseChord(100 + 100, 100, 50, 50, 45, 90, Graph::Color::Black);
//
//     Graph::FillEllipseSector(100 + 200, 100, 50, 50, 0, 360, Graph::Color::Red);
//     Graph::DrawEllipseSector(100 + 200, 100, 50, 50, 90, 180, Graph::Color::Amethyst);
//
//     Graph::FillEllipseSector(100 + 300, 100, 30, 70, 0, 360, Graph::Color::Red);
//
//     SetLineWidth(5);
//
//     Graph::Point my_points[5];
//     my_points[0].x = 500;
//     my_points[0].y = 200;
//     my_points[1] = { 500,220 };
//     my_points[2] = { 400,320 };
//     my_points[3] = { 500,340 };
//     my_points[4] = { 480,140 };
//
//     //DrawPoly(my_points, 5, Color::Tomato);
//     DrawPolyLine(my_points, 5, Color::Tomato);
//
//     OutText(100, 600, "Hello there", Color::Black, 30);
//
//     Graph::ClearDevice(Color::Black);
//
//     Graph::FillEllipseSector(300, 300, 50, 50, 0, 360, Graph::Color::Yellow);
//
//
//     // Sun
//     SStar TheSun = { 300, 300, 50, 30, Color::Yellow };
//     DrawStar2(TheSun);
//
//     SStar stars[5];
//
//     stars[0] = TheSun;
//
//     stars[1] = TheSun;
//     stars[1].coord.y += 320;
//
//     stars[2] = { 600, 300, 150, 10, Color::DarkRed };
//
//
//     //DrawStar(300, 300, 50, 30, Color::Yellow);
//     //Graph::FillEllipseSector(300, 300, 50, 50, 0, 360, Graph::Color::Yellow);
//     //for (int angle = 0; angle < 360; angle += 40)
//     //{
//     //    Graph::FillEllipseSector(300, 300, 80, 80, angle, angle+10, Graph::Color::Yellow);
//     //}
//
//     // Red Giant
//     //DrawStar(600, 300, 150, 10, Color::DarkRed);
//     //Graph::FillEllipseSector(600, 300, 150, 150, 0, 360, Graph::Color::DarkRed);
//     //for (int angle = 0; angle < 360; angle += 40)
//     //{
//     //    Graph::FillEllipseSector(600, 300, 160, 160, angle, angle + 10, Graph::Color::DarkRed);
//     //}
//
//     // Pulsar
//     //DrawStar(900, 700, 60, 100, Color::Aquamarine);
//     stars[3] = { 900, 700, 60, 100, Color::Aquamarine };
//     stars[4] = stars[3];
//
//     stars[4].coord.x = 0;
//     stars[4].coord.y = 0;
//
//
//
//     for (int i = 0; i < 5; i++)
//     {
//         DrawStar2(stars[i]);
//     }
//     //Graph::FillEllipseSector(900, 700, 60, 60, 0, 360, Graph::Color::Aquamarine);
//     //for (int angle = 0; angle < 360; angle += 40)
//     //{
//     //    Graph::FillEllipseSector(900, 700, 160, 160, angle, angle + 10, Graph::Color::Aquamarine);
//     //}
//
//     //Graph::FillEllipseSector(300, 300, 80, 80, 0, 10, Graph::Color::Yellow);
//     //Graph::FillEllipseSector(300, 300, 80, 80, 30, 40, Graph::Color::Yellow);
//     //Graph::FillEllipseSector(300, 300, 80, 80, 60, 70, Graph::Color::Yellow);
//     //Graph::FillEllipseSector(300, 300, 80, 80, 100, 110, Graph::Color::Yellow);
//
//     //Graph::FillEllipseSector(400, 300, 50, 50, 0, 360, Graph::Color::Yellow);
//
//     Graph::SwapBuffers();
//     Graph::ReadKey();
//
//     //RunGameLoop();
//
//     Graph::CloseGraph();
//
//     printf("Window closed!\n");
// }
//
// int main()
// {
//     // SRP - Single responsibility principle
//     // DRY - Don't repeat yourself
//
//     //taskX();
//     GraphWindow();
//
//     
// }