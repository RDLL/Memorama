#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <opencv2/core.hpp>
#include <vector>

using namespace cv;
using namespace std;

class imagenes{
    string ruta = "/home/rdll/Memorama/imagenes/";
    string im[6] = {ruta + "bender.jpg",ruta + "bender2.jpg",ruta +"bender3.jpg",ruta + "bender4.jpg",ruta + "bender5.jpg",ruta + "bender6.jpg"};
    short int op = 0;
    short int intento;
    Mat image[6];
    Mat ventana;
    public:
        imagenes();
        void mostrar();
        void cambiar();
        void Ventana();
};

imagenes::imagenes(){
    for(int i = 0; i < 6; i++)
        image[i] = imread(im[i]);
    cambiar();
    Ventana();
}

void imagenes::cambiar(){
    Mat a[6];
    for (int i = 0; i < 6;i++)
        resize(image[i],a[i],Size(300,200));
    for (int i = 0; i < 6; i++)
        image[i] = a[i];
}

void imagenes::mostrar(){
    namedWindow("Display Image", WINDOW_AUTOSIZE  );
    imshow("Display Image",ventana);
    waitKey(0);
}

void imagenes::Ventana(){
    vector<Mat> a = {image[0],image[1],image[2]};
    vector<Mat> b = {image[3],image[4],image[5]};
    Mat c;
    Mat d;
    hconcat(a,c);
    hconcat(b,d);
    imshow("Display",c);
    waitKey(0);
    vector<Mat> e = {c,d};
    vconcat(e,ventana);
}

int main()
{
    imagenes imagen;
    imagen.mostrar();
    return 0;
}
