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
    int frame_direction = 1;
    const int frame_max = 10;
    const int frame_min = 0;
    int a1 = 140;
    while (true)
    {
        auto can = Canvas(300, 150);
        can.DrawPointCircle(60, 20, frame, Color::Cyan1); // ojos
        can.DrawPointCircle(80, 20, frame, Color::Cyan1); // ojos
        can.DrawPointCircle(60, 20, 30, Color::LightSalmon1);
        can.DrawPointLine(70, 25, 75, 27, Color::LightSalmon1);
        can.DrawPointLine(60, 38, 80, 36, Color::LightSalmon1);
        can.DrawPointLine(55, 14, 65, frame, Color::GrayDark);
        can.DrawPointLine(75, frame, 85, 13, Color::GrayDark);
        int carro_x = a1 + frame * 10;                                     // Control de desplazamiento del carro
        can.DrawPointLine(carro_x - 20, 43, carro_x + 5, 35, Color::Red3); // carro
        can.DrawPointLine(carro_x + 5, 35, carro_x + 20, 35, Color::Red3);
        can.DrawPointLine(carro_x + 20, 35, carro_x + 30, 43, Color::Red3);
        can.DrawPointLine(carro_x - 20, 43, carro_x + 30, 43, Color::Red3);
        can.DrawPointCircle(carro_x - 10, 47, 4, Color::Black); // llantas
        can.DrawPointCircle(carro_x + 20, 47, 4, Color::Black);
        can.DrawPointLine(carro_x + 5, 40, carro_x - 5, 38, Color::Blue);
        can.DrawPointLine(carro_x + 10, 40, carro_x + 5, 40, Color::Blue);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::DeepSkyBlue3, border(vbox(canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        if (frame >= frame_max)
            frame_direction = -1;
        if (frame <= frame_min)
            frame_direction = 1;
        frame += frame_direction;
    }
    return 0;
}