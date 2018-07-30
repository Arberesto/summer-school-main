all: clean reload lint build exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build: 
	cd cmake-build-debug;make

exec:
	./cmake-build-debug/dmitrij-bagaev-main-game

clean:
	rm -rf cmake-build-debug

reload: mkdir_build
	cd cmake-build-debug;cmake ..

fast_build:
	cd cmake-build-debug;make

run: fast_build exec

lint:
	cd cmake-build-debug;make lint

debug: fast_build debug_server

debug_server:
	gdbserver :8080 ./cmake-build-debug/dmitrij-bagaev-main-game

reformat:
	clang-format -i -style=file ./src/*.h
	clang-format -i -style=file ./src/*.cpp

osx_dep:
	brew install ncurses

linux_dep:
	sudo apt install libncurses5-dev
