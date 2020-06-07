# Docker file to build and test AnyMeal on different versions of Debian
#
# configure /etc/default/docker
# DOCKER_OPTS="--dns 8.8.8.8 --dns 8.8.4.4 --ip-masq=true"
FROM debian:sid
MAINTAINER Jan Wedekind <jan@wedesoft.de>
RUN echo "deb http://httpredir.debian.org/debian unstable main" > /etc/apt/sources.list
RUN apt-get update  # Forced update Fr 5. Jun 19:28:48 BST 2020
RUN apt-get -q -y dist-upgrade
RUN apt-get install -q -y apt-utils
RUN apt-get install -q -y build-essential
RUN apt-get install -q -y autoconf automake libtool
RUN apt-get install -q -y devscripts equivs
RUN apt-get install -q -y flex
RUN apt-get install -q -y googletest
RUN apt-get install -q -y librecode-dev
RUN apt-get install -q -y libsqlite3-dev
RUN apt-get install -q -y qtbase5-dev-tools
RUN apt-get install -q -y qttools5-dev-tools
RUN apt-get install -q -y qtbase5-dev
RUN mkdir -p /usr/src/anymeal
WORKDIR /usr/src/anymeal
ADD debian/control debian/control
RUN mk-build-deps --install --remove --tool 'apt-get -q --yes' debian/control
COPY anymeal.tar.xz .
COPY anymeal.tar.xz.asc .
ADD configure.ac .
ADD debian debian
ADD Makefile.package .
RUN make -f Makefile.package
RUN dpkg --install pkg/anymeal_*.deb
