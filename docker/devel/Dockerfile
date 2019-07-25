FROM ros:melodic-perception
LABEL Maintainer="Pierre-Yves Lajoie <lajoie.py@gmail.com>"

# Install and setup some editing and debugging tools
RUN apt-get update

RUN apt-get update &&\
    apt-get install -y nano vim

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

# Entry point to start the module
WORKDIR /blabbermouth/build

COPY entrypoint.sh entrypoint.sh
RUN chmod +x entrypoint.sh
ENTRYPOINT ["/blabbermouth/build/entrypoint.sh"]
CMD ["0", "1"]