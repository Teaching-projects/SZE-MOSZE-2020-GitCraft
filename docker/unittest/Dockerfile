FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y \
    g++ \
    libgtest-dev \
    make \
    cmake\
&& cd /usr/src/gtest \
&& cmake CMakeLists.txt \
&& make