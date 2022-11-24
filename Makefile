CC = g++ --std=c++2a -g -Wall
G_INC = -Iinclude $(CPPFLAGS)
O = -o gauss
DEPS_SFML = -I/usr/local/Cellar/sfml/2.5.1_2/include -L/usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
DEPS_GAUSS = launcher.cpp gaussian_vis.cpp k_means.cpp em_maximization.cpp
DEPS_UTILS = utils/*.cpp

all: clean gauss

gauss:
	$(CC) $(G_INC) $(O) $(DEPS_SFML) $(DEPS_GAUSS) $(DEPS_UTILS)

clean:
	$(RM) gauss