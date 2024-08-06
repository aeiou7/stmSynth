#!/usr/bin/env sh

CONTAINER_NAME="stmsynth"
DISTRO="ubuntu"
RELEASE="noble"
ARCH="amd64"
DEPS="vim build-essential make git autoconf gcc-arm-none-eabi cmake pkg-config openssh-server"
lxc-create -n $CONTAINER_NAME -t download -- -d $DISTRO -r $RELEASE -a $ARCH
lxc-start -n $CONTAINER_NAME
lxc-attach -n $CONTAINER_NAME -- apt update -y
lxc-attach -n $CONTAINER_NAME -- apt install -y $DEPS
#lxc-attach -n $CONTAINER_NAME --
lxc-attach -n $CONTAINER_NAME -- mkdir git
lxc-attach -n $CONTAINER_NAME -- cd git
lxc-attach -n $CONTAINER_NAME -- git clone https://github.com/aeiou7/stmSynth.git
lxc-attach -n $CONTAINER_NAME -- cd stmSynth
lxc-attach -n $CONTAINER_NAME
