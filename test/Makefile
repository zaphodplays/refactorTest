name=king_test

options = -g -Wall -Wextra -pedantic -std=c++14

include_path=-Iutil -Ientity -Iservice -Icommands -Iui
sources=$(wildcard entity/*.cpp service/*.cpp commands/*.cpp ui/*.cpp)

default: $(name)
	
$(name): $(sources) 
	rm -rf bin && mkdir bin && g++ $(options) $(include_path) -o bin/$@ $^

 
