FROM alpine:3.17

RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.tuna.tsinghua.edu.cn/g' /etc/apk/repositories

ADD ./build/blurhash-server-bin /usr/bin/blurhash-server

EXPOSE 3000

CMD ["/usr/bin/blurhash-server"]
