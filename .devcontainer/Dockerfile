# syntax=docker/dockerfile:1
FROM debian:stable-slim

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=1000

RUN echo "deb [trusted=yes] http://archive.debian.org/debian buster main\n\
deb [trusted=yes] http://archive.debian.org/debian-security buster/updates main" > /etc/apt/sources.list


# bsdmainutils - includes hexdump
RUN set -eux; \
    apt-get update && \
    apt-get install -y --no-install-recommends \
        make wget git ssh sudo \
        bsdmainutils && \
    rm -rf /var/lib/apt/lists/*

# gcc-mingw for utilapiset.h headers for x86
RUN set -eux; \
    apt-get update && \
    apt-get install -y --no-install-recommends \
        gcc-mingw-w64-i686 \
        mingw-w64 \
        binutils-mingw-w64-i686 && \
    apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# headers are now available on /usr/i686-w64-mingw32/include/utilapiset.h  [or /usr/x86_64-w64-mingw32/include/utilapiset.h for x64]

RUN set -eux; \
    groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -c "VsCode user" -s /bin/bash  -m $USERNAME && \
    mkdir -p /etc/sudoers.d && \
    echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME && \
    chmod 0440 /etc/sudoers.d/$USERNAME

RUN mkdir -p /usr/src/app && \
    chown -R 1000:1000 /usr/src/app

USER ${USERNAME}
RUN git config --global --add safe.directory /usr/src/app
WORKDIR /usr/src/app

ENTRYPOINT [ "/bin/bash" ]
