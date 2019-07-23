FROM ubuntu:18.04
LABEL Maintainer="Pierre-Yves Lajoie <lajoie.py@gmail.com>"

# Install and setup some editing and debugging tools
RUN apt-get update &&\
    apt-get install -y gedit nano strace valgrind wget

RUN wget -O vscode.deb https://go.microsoft.com/fwlink/?LinkID=760868 &&\
    apt install -y ./vscode.deb &&\
    apt install -y libasound2

RUN mkdir ~/code &&\
    code --install-extension ms-vscode.cpptools --user-data-dir ~/code

RUN apt-get install -y git build-essential software-properties-common cmake \
                        netcat net-tools pkg-config

# Add dummy argument to force rebuild starting from that point
ARG CODE_UPDATE=unknown

# Install Blabbermouth
RUN git clone https://github.com/lajoiepy/blabbermouth.git &&\
    cd blabbermouth &&\
    mkdir build &&\
    cd build &&\
    cmake ../src &&\
    make

# Put your own git credentials to commit edited code
RUN git config --global user.email "lajoie.py@gmail.com" &&\
    git config --global user.name "Pierre-Yves Lajoie"

# Entry point to start the module
WORKDIR /blabbermouth/build