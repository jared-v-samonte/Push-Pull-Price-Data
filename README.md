# Data Push Pull - Push and Pull Pricing Data

A program written in C++ to download historical and real-time crypto market data and provide real-time crypto index NAV prices.

Install Prerequisites:
  ```
  sudo apt-get install libgtkmm-3.0-dev libboost-system-dev libboost-filesystem-dev libmariadb-dev
  ```
  
## Display Set-Up (must do this for every newly opened WSL2 terminal with Xlaunch):
  ```
 export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
 export LIBGL_ALWAYS_INDIRECT=0
  ```

## Install an Run MariaDBpp:
```
  sudo apt update
  sudo apt install mariadb-server
  sudo mysql_secure_installation
  sudo systemctl start mariadb.service -p enter-password
  sudo mariadb -p enter-password
  ```

## How to Build and Run

Build MariaDBpp pre-built libraries first:

* MariaDBpp
  ```
  cd mariadbpp_pre
  mkdir build && cd build
  cmake ..
  make
  ```
  
* Coin Gecko API
  ```
  cd coin_gecko_api_pre
  mkdir build && cd build
  cmake ..
  make
  ```
  
Build Pre-built libraries first:
  * move library ".a" file 
  * It will be exported here ${Name of Library}/build
  * Move or copy and pasted to libraries
  
Build Main Cmake file next:
  ```
  mkdir build && cd build
  cmake ..
  make
  ```
  
  
Compile with Make:
  ```
  mkdir build && cd build
  cmake ..
  make
  ```
Compile via Terminal:
  ```
  cd source
  g++ -std=c++11 -I/usr/local/include -I/usr/include/mariadb -L/usr/local/lib main.cpp daps.cpp global.cpp initial.cpp preferences.cpp basicfunctions.cpp -lboost_filesystem -lboost_system -o test `pkg-config gtkmm-3.0 --cflags --libs`
  ```

Run Application:
  ```
  ./Data_Push_Pull
  ```
