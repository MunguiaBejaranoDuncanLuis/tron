output = bin/
source = src
inc = -Iinclude
dependencias = -Iinclude -lftxui-screen -lftxui-dom -lftxui-component
flags = -std=c++2a $(dependencias) $(Iinclude)


run : $(output)/tron
	./$<

$(output)/tron : $(source)/main.cpp 
	g++ -o $@ $<  $(flags)

runPantalla : $(output)/pantalla
	./$<

$(output)/pantalla : $(source)/pantalla.cpp 
	g++ -o $@ $<  $(flags)