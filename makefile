grafica2o.py: ecuaciones.dat
	python grafica28.py
ecuaciones.dat: diferenciales.x
	./diferenciales.x 
	./diferenciales.x > ecuaciones.dat
diferenciales.x : clase28.cpp
	c++ clase28.cpp -o diferenciales.x
