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

