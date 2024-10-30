#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    auto can = Canvas(300,150);
    can.DrawPointCircle(60,20,3);
    can.DrawPointCircle(80,20,3);
    can.DrawPointCircle(60,20,30);
    can.DrawPointLine(70,25,75,27);
    can.DrawPointLine(60,38,80,36);
    can.DrawPointLine(55,14,65,13);
    can.DrawPointLine(75,15,85,13);
    can.DrawPointCircle(150,20,10);
    can.DrawPointCircle(175,20,10);
   
    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Red1, border(vbox(canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}