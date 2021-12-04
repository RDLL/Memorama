# Memorama
Memorama hecho en C++ usando OpenCV

## Requisitos
- cmake
- g++
- OpenCV
- ninja (opcional)
### Instalación de OpenCV
#### Linux
```
mkdir opencv && cd opencv

git clone https://github.com/opencv/opencv.git

# Se puede omitir los modulos de contrib
git clone https://github.com/opencv/opencv_contrib.git

mkdir build && cd build

cmake -DCMAKE_INSTALL_PREFIX=/user/local -DOPENCV_EXTRA_MODULES_PATH=/path/opencv/opencv_contrib-master/modules /path/opencv/opencv-master/

# Sin los modulos de contrib
cmake -DCMAKE_INSTALL_PREFIX=/user/local /path/opencv/opencv-master/

# En caso de usar ninja
cmake -Gninja -DCMAKE_INSTALL_PREFIX=/user/local -DOPENCV_EXTRA_MODULES_PATH=/path/opencv/opencv_contrib-master/modules /path/opencv/opencv-master/

# Con make
make -j4

#Con ninja
ninja

# Instalar
sudo make install
``` 
El sitio de OpenCV recomienda no instalar OpenCV en las carpetas del sistema, sin embargo hay ocasiones en el que no instalarlas ahí hace que al usar cmake para generar los binarios no las pueda localizar

#### Windows
- Descargar [OpenCV](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/)
- Ejecutar como administrador
