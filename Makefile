.PHONY: build
build: clean
	meson build && ninja -v -j8 -C build

.PHONY: clean
clean:
	rm -rf build

.PHONY: run
run: clean build
	./build/blurhash-server-bin

.PHONY: check
check:
	find ${PWD} -name *.c | xargs clang-check

.PHONY: containerlize
containerlize: build
	docker build -t 'blurhash-server:latest' .
	rm -rf build
