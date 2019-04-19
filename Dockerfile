FROM ubuntu
COPY ubuntu18.04.list /etc/apt/sources.list
RUN apt-get update && apt-get -y install build-essential && \
apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

