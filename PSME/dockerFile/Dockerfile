FROM abrother94/psme-ubuntu16.04:latest 
MAINTAINER Nick_Huang 
WORKDIR /
EXPOSE 8888 
ADD ./libonlp-platform.so /lib/x86_64-linux-gnu/ 
ADD ./libonlp-platform-defaults.so /lib/x86_64-linux-gnu/
ADD ./libonlp-platform.so.1 /lib/x86_64-linux-gnu/
RUN dpkg -i *.deb 
