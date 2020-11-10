FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y \
    g++ \
    libgtest-dev \
    make \
    cmake\
&& cd /usr/src/googletest/googletest \
&& cmake CMakeLists.txt \
&& make \
&& cp libgtest* /usr/lib/ \
&& ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a \
&& ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a