#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread> //Hilos de procesos
#include <fstream> //Flujo de archivos
#include <string> //Control de cadenas
#include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Dibujo moto("./assets/images/moto.txt");
    Dibujo bloque("./assets/images/bloque.txt");

    /*ifstream archivo;
    archivo.open("./assets/images/moto.txt");
    Elements elementos;
    string linea;
    while (getline(archivo,linea))
    {
        elementos.emplace_back(text(linea));
    }
    Element moto = vbox(elementos);
    archivo.close();

    archivo.open("./assets/images/bloque.txt");
    Elements objetos;
    string serie;
    while (getline(archivo,serie))
    {
        objetos.emplace_back(text(serie));
    }
    Element bloque = vbox(objetos);
    archivo.close();*/
    
    
    int fotograma = 0;
    while (true)
    {
        this_thread::sleep_for(0.1s);
        fotograma++;
        Element personaje = spinner(21,fotograma) | bold | color(Color::Red) | bgcolor(Color::White);
        /*Element ebloque = bloque;
        Element eMoto = moto;*/
        Element dibujo = hbox({personaje, moto.GetElement(), bloque.GetElement()});
        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla, dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }
    return EXIT_SUCCESS;
}