g++ main.cpp ^
./src/hunter_controller/hunter.cpp     -I./src/hunter_controller/ ^
./src/modification/add.cpp ./src/modification/delete.cpp    -I./src/modification/ ^
./src/structs/structs.cpp   -I./src/structs/ ^
./src/utilities/trim.cpp  ./src/utilities/color.cpp    -I./src/utilities/ ^
./src/validation/selection.cpp ./src/validation/validation.cpp  -I./src/validation/ ^
-o Pokemon