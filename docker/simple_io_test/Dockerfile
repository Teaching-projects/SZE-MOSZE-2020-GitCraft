FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y \
    g++ \
    cppcheck \
    valgrind \
    make \
&& rm -rf /var/lib/apt/lists/*