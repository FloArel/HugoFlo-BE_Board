 #!/usr/bin/bash
cd src_proj
echo "g++ -Wall -std=c++11 -lpthread board.cpp core_simulation.cpp mydevices.cpp sketch_ino.cpp -o arduino"
g++ -Wall -std=c++11 -pthread board.cpp core_simulation.cpp jeu.cpp internal.cpp mydevices.cpp sketch_ino.cpp -o arduino
