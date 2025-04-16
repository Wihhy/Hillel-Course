#include "glfwbgi.h"
int main(int argc, char* argv[])
{
    Graph::InitGraph(1200, 1000, "");
    const char buffer[] = { 73, 116, 32, 105,115, 32,65,108,105,118,101, 0 };
    Graph::OutText(100, 100, buffer, Graph::Color::Lime, 20);
    Graph::SwapBuffers();
    Graph::ReadKey();
    Graph::CloseGraph();



    return 0;
}
