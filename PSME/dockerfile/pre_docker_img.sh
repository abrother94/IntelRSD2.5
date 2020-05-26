#!/bin/bash
rm libonlp-platform*
cp /lib/x86_64-linux-gnu/libonlp-platform.so ./ 
cp /lib/x86_64-linux-gnu/libonlp-platform-defaults.so ./ 
cp /lib/x86_64-linux-gnu/libonlp-platform.so.1 ./ 
docker build -t psme .
docker run -it -v "/etc/onl/":/etc/onl/ -v "/lib/platform-config":/lib/platform-config --privileged -p 8888:8888 psme /bin/bash
