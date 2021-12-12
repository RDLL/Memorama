#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <cstring>
#include <opencv2/core.hpp>
#include <vector>
#include <ctime>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

const string winName = "Display";

class imagenes{
    string ruta = "/home/rdll/Memorama/imagenes/";
    string im[6] = {ruta + "bender.jpg",ruta + "bender2.jpg",ruta + "bender3.jpg",ruta + "bender.jpg",ruta + "bender2.jpg",ruta + "bender3.jpg"};
    string reverso = ruta + "bender4.jpg";
    Mat rev[6];
    Mat copia[6];
    Mat copia2[6];
    Mat copia3[6];
    Mat copia4[6];
    unordered_set <int> orden;
    int ord[6];
    int intento;
    int cont;
    int band;
    int puntos;
    string primer,segundo;
    Mat image[6];
    Mat cuadro;
    Mat vrev;
    public:
        imagenes();
        void mostrar(bool op);
        void cambiar();
        void ventana();
        void tapa();
        void cadena(int n);
        void reasignar();
        void generar();
        bool comparar();
        void copiar(int n);
        void destapar(int n);
        void clickOn( int event, int x, int y, int flags, void* param );
        int getIntento(){return intento;};
};

imagenes::imagenes(){
    band = -1;
    cont = 0;
    puntos = 0;
    intento = 3;
    generar();
    int i = 0;
    unordered_set<int>::iterator itr;
    for(itr = orden.begin(); itr != orden.end(); itr++){
            image[i] = imread(im[(*itr)]);
            rev[i] = imread(reverso);
            ord[i] = (*itr);
            i++;
    }
    cambiar();
    ventana();
    tapa();
}

void imagenes::generar(){
        while(orden.size() < 6)
            orden.insert(rand()%6);
}

void imagenes::cambiar(){
    Mat a[6];
    Mat b[6];
    for (int i = 0; i < 6;i++){
        resize(image[i],a[i],Size(300,200));
        resize(rev[i],b[i],Size(300,200));
    }
    for (int i = 0; i < 6; i++){
        image[i] = a[i];
        rev[i] = b[i];
    }
}

void imagenes::mostrar(bool op){
    if(op){
        imshow(winName,vrev);
    }
    else{
        imshow(winName,cuadro);
        waitKey(1000);
    }
}

void imagenes::ventana(){
    vector<Mat> a = {image[0],image[1],image[2]};
    vector<Mat> b = {image[3],image[4],image[5]};
    Mat c;
    Mat d;
    hconcat(a,c);
    hconcat(b,d);
    vector<Mat> e = {c,d};
    vconcat(e,cuadro);
}

void imagenes::tapa(){
    vector<Mat> a = {rev[0],rev[1],rev[2]};
    vector<Mat> b = {rev[3],rev[4],rev[5]};
    Mat c;
    Mat d;
    hconcat(a,c);
    hconcat(b,d);
    vector<Mat> e = {c,d};
    vconcat(e,vrev);
}

bool imagenes::comparar(){
    int n = 0;
    if(primer.size() == segundo.size()){
        for(int i = 0; i < primer.size(); i++){
            if(primer[i] != segundo[i])
                n++;
        }
    }else
        return 0;
    if(n != 0)
        return 0;
    else 
        return 1;
}

void imagenes::copiar(int n){
    for(int i = 0; i < 6; i++){
        if(intento == 3){
            if(i != n)
                resize(rev[i],copia[i],Size(300,200));
            else
                resize(image[i],copia[i],Size(300,200));
            cout << "n" << '\n';
        }
        if(intento == 2){
             if(i != n)
                 resize(rev[i],copia2[i],Size(300,200));
             else
                 resize(image[i],copia2[i],Size(300,200));
        }
        if(intento == 1){
             if(i != n)
                 resize(rev[i],copia3[i],Size(300,200));
             else
                 resize(image[i],copia3[i],Size(300,200));
        }
        if(intento == 0){
           destroyAllWindows();
           cout << "Has perdido, suerte a la próxima\n";
           cout << "Oprime cualquier tecla para salir";
           cin.get();
           destroyAllWindows();
        }
     }

    cout << "intento: " << intento << '\n';
}

void imagenes::reasignar(){
    for(int i = 0; i < 6; i++){
        if(puntos == 1)
            resize(copia[i],rev[i],Size(300,200));
        if(puntos == 2)
            resize(copia2[i],rev[i],Size(300,200));
        if(puntos == 3)
            resize(copia3[i],rev[i],Size(300,200));
    }
}

void imagenes::cadena(int n){
    if(cont == 1){
        primer.assign(im[ord[n]]);
        band = n;
    }
    if(cont == 2){
        segundo.assign(im[ord[n]]);
        //cout << primer  << '\n' << segundo << '\n';
        //cout << "Comparacion: " << segundo.compare(primer) << '\n';
        //cout << "Tamaño 1: " << primer.length() << '\n';
        //cout << "Tamaño 2: " << segundo.length() << '\n';
        if(comparar()){
                //ord[band] = -1;
                //ord[n] = -1;
                puntos++;
        }else{
            intento--;
        }
        cont = 0;
    }
    cout << "Cont: "<< cont << '\n';
    cout << "Puntos: " << puntos << '\n';
}

void imagenes::destapar(int n){
    cont++;
    int j = 0;
    Mat a[6];
    for(int i : orden){
        if(i != n){
            if(cont > 1 || puntos > 0){
                if(intento == 3)
                    resize(copia[i],a[i],Size(300,200));
                if(intento == 2)
                     resize(copia2[i],a[i],Size(300,200));
                if(intento == 2)
                     resize(copia3[i],a[i],Size(300,200));
            }else
                resize(rev[i],a[i],Size(300,200));
        }
        else
            resize(image[i],a[i],Size(300,200));
        if(j == n){
            cadena(j);
            copiar(j);
        }
        j++;
    }
    vector<Mat> b = {a[0],a[1],a[2]};
    vector<Mat> c = {a[3],a[4],a[5]};
    Mat d;
    Mat e;
    hconcat(b,d);
    hconcat(c,e);
    vector<Mat> f = {d,e};
    Mat aux; 
    vconcat(f,aux);
    imshow(winName,aux);
    waitKey(0);
}

void imagenes::clickOn(int event,int x, int  y,int flags, void* param ){
    int n;
    bool a = y < 200;
    bool b = y > 200;
    bool c = x > 300 && x < 600;
    bool d = x > 600 && x < 900;
    bool e = x < 300;
    if(event == EVENT_LBUTTONDOWN){
        if(e && a)
            destapar(0);
        if(c && a )
            destapar(1);
        if(d && a)
            destapar(2);
        if(e && b )
            destapar(3);
        if(c && b)
            destapar(4);
        if(d && b)
            destapar(5);
    }
}

imagenes imagen;

static void onMouse(int event, int x, int y, int flags, void* param ){
    imagen.clickOn(event, x, y, flags, param);
}

int main()
{
    srand(time(NULL));
    namedWindow(winName,WINDOW_AUTOSIZE);
    setMouseCallback(winName,onMouse,NULL);
    imagen.mostrar(0);
    imagen.mostrar(1);
    waitKey(0);
    return 0;
}
