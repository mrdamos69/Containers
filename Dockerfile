FROM quay.io/school21/alpine:3.13

MAINTAINER Aleksey Kadnikov aka manhunte <manhunte@student.21-school.ru>
ENV TZ=Europe/Moscow

RUN apk --no-cache --upgrade add \
    git \
    git-lfs \
    curl \
    jq \
    bash \
	build-base \
    python3 \
    valgrind \
    cppcheck \
	alpine-sdk \
	pcre-dev \
    gtest \
    gtest-dev \
    libstdc++ \
    libgcc

WORKDIR "/project"

ENTRYPOINT ["/bin/bash", "scripts/test.sh"]

