#include "global.hpp"
#include "daps.hpp"

int main(int argc, char *argv[]) {
    //Opening main window
    Gtk::Main kit(argc,argv);
    MainWindow mainWindow;
    kit.run(mainWindow);
    return 0;
}
