#include <thread>
#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <assets/images/moto.txt>
using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Full());

    int x = 0;
    while (true)
    {
        x++;
        pantalla.Clear();
        this_thread::sleep_for(0.1s);

        pantalla.PixelAt(x,5).character = "Hola";
        pantalla.PixelAt(x,6).hyperlink = moto.txt;

        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }

    return 0;
}
