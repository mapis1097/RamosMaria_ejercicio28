#include <iostream>
#include <cmath>

float f10(float, float, float);
float f11(float, float, float);
float f20(float, float, float);
float f21(float, float, float);

void ecuaciones_diferenciales(double t, double &x0, double & y0, double &x1, double &y1);

float K = 0.7;
int n = 1;
float h = 0.01;
float g = -9.8;

float f0_x(float tiempo, float distancia, float altura){
    return -K*pow(distancia, n)*distancia/sqrt( pow(distancia,2) + pow(altura,2) );
}

float f1_x(float t, float distancia, float altura){
    return distancia;
}

float f0_y(float t, float distancia, float altura){
    return -g - K*(pow(altura, n))* altura/sqrt( pow(distancia,2) + pow(altura,2) );
}

float f1_y(float t, float distancia, float altura){
    return altura;
}

int main(){
   
    double x, y, Vx, Vy, t;
    x = 0;
    y = 0;
    Vx = 10;
    Vy = 10;
    for(t = 0; t <= 20; t+= h){
        std::cout << t << "\t" << x  <<"\t" << y << "\t"  << std::endl;
        ecuaciones_diferenciales(t, Vx, Vy, x, y);
     }
   
   
    return 0;
}

void ecuaciones_diferenciales(double t, double &x0, double & y0, double &x1, double &y1)
{
    double k10_x, k11_x, k20_x, k21_x, k30_x, k31_x, k40_x, k41_x;
    double k10_y, k11_y, k20_y, k21_y, k30_y, k31_y, k40_y, k41_y;

   
	//k4 para los 10
    k10_x = h*f0_x(t, x0, y0);
	k10_y = h*f0_y(t, x1, y1);
	
	//K4 para los 11
    k11_x = h*f1_x(t, x0, y0);
	k11_y = h*f1_y(t, x1, y1);
	
	//k4 para los 20
    k20_x = h*f0_x(t+h/2, x0 + k10_x/2, y0 + k10_y/2);
	k20_y = h*f0_y(t+h/2, x1 + k10_x/2, y1 + k10_y/2);
	
	//K4 para los 21
    k21_x = h*f1_x(t+h/2, x0 + k11_x/2, y0 + k11_y/2);
	k21_y = h*f1_y(t+h/2, x1 + k11_x/2, y1 + k11_y/2);
	
	//k4 para los 30
    k30_x = h*f0_x(t+h/2, x0 + k20_x/2, y0 + k20_y/2);
	k30_y = h*f0_y(t+h/2, x1 + k20_x/2, y1 + k20_y/2);
	
	//k4 para los 31
    k31_x = h*f1_x(t+h/2, x0 + k21_x/2, y0 + k21_y/2);
	k31_y = h*f1_y(t+h/2, x1 + k21_x/2, y1 + k21_y/2);
	
	//k4 para los 40
    k40_x = h*f0_x(t + h, x0 + k30_x, y0 + k30_y);
	k40_y = h*f0_y(t + h, x1 + k30_x, y1 + k30_y);
	
	//k4 para los 41
    k41_x = h*f1_x(t + h, x0 + k31_x, y0 + k31_y);
    k41_y = h*f1_y(t + h, x1 + k31_x, y1 + k31_y);
	
	
   
    x0 = x0 + (1.0/6.0)*(k10_x + 2*k20_x + 2*k30_x + k40_x);
	y0 = y0 + (1.0/6.0)*(k10_y + 2*k20_y + 2*k30_y + k40_y);
	
	
    x1 = x1 + (1.0/6.0)*(k11_x + 2*k21_x + 2*k31_x + k41_x);
    y1 = y1 + (1.0/6.0)*(k11_y + 2*k21_y + 2*k31_y + k41_y);
   
}

