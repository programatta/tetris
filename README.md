# TETRIS (RayLib)
## Preparación del entorno.
Vamos a utilizar docker para desarrollar dentro del contenedor, y así evitar llenar de librerías la máquina.
La idea consiste en crear el contenedor, y trabajar dentro de él, plugin de VSCode de conexión a contenedores remotos.

Creamos dos archivos __Dockerfile__ y __docker-compose.yml__ y trabajaremos dentro del contenedor:

### Dockerfile.
En la imagen instalamos las herramientas para compilar con c++ y las librerías gráficas, así como la librería __raylib__.
En el proceso de construcción de la imagen, pasaremos el usuario local, para evitar que la imgagen cree los archivos como root y no tener problemas con los permisos.

~~~
FROM debian:bookworm-20231120-slim

ARG user

RUN useradd -ms /bin/bash $user
RUN echo "deb https://deb.debian.org/debian/ stable main" > /etc/apt/sources.list \
    && apt-get update \
    && apt-get install -y build-essential gdb cmake git pkg-config \
       libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev \
       && git clone https://github.com/raysan5/raylib.git raylib \
    && cd raylib \
    && mkdir build && cd build \
    #&& cmake -DBUILD_SHARED_LIBS=ON ..
    && cmake .. \
    && make \
    && make install \
    && mkdir /code


USER $user

WORKDIR /code
~~~

### docker-compose.yml.
El contenedor establece el binding al directorio de trabajo al directorio /code dentro del contenedor, y guardamos en la carpeta docker la configuración de vscode para no perderla.

También se mapean los puertos .X11 para permitir al conenedor ejecutar la aplciación y enviarla al entorno gráfico de local.
~~~
version: '3'
services:
  development_env:
    #container_name: development-env
    build:
      context: .
      dockerfile: Dockerfile
    environment:
      - DISPLAY=$DISPLAY
    command: sleep infinity
    image: development-env
    user: jorge
    volumes:
      - .:/code
      - ./docker/.vscode-server:/home/jorge/.vscode-server
      - /tmp/.X11-unix:/tmp/.X11-unix
    # ports:
    #   - "1:0"
~~~

### Creación de la imagen.
Para construir la imagen hacemos:
~~~
docker compose build --build-arg="user=<usuario>"
~~~

Donde __usuario__ es nuestro usuario.

### Entorno de desarrollo.
Una vez creada la imagen, damos permisos a docker a usar las X11 y levantamos el contenedor que se quedará esperando a que nos conectemos para empezar a trabajar.

Vemos que tenemos:
~~~
xhost
~~~

Nos puede salir algo como esto:
~~~
access control enabled, only authorized clients can connect
~~~

Añadidermos a docker a usar las X11:
~~~
xhost +local:docker
~~~

Y nos aparece:
~~~
non-network local connections being added to access control list
~~~

Verificamos que aparece __LOCAL:__
~~~
xhost
~~~

Y levantamos el contenedor.
~~~
docker compose up
~~~


Al finalizar, podemos volver a quitar a docker de las X11:

~~~
xhost -local:docker
~~~

Y nos aparece:
~~~
non-network local connections being removed from access control list
~~~


Y comprobamos:
~~~
xhost
~~~

Y nos aparece:
~~~
access control enabled, only authorized clients can connect
~~~

Y lo hemos dejado como al inicio.
