#include <QApplication>
#include <iostream>
#include <filesystem>
#include "textBox.h"
#include "Editor.h"
#include "editormainwindow.h"
#include "StateSaver.h"
#include "MapLoader.h"


int main(int argc, char *argv[]) {
    QApplication editorView(argc, argv);
    std::string name;
    int x;
    int y;
    int mode=0;
    int players;
    EditorMainWindow e(name,x,y,mode,players);
    e.show();
    editorView.exec();

    if (mode == 1) {
        Editor editor(Vector2i(1366, 768),name, x, y, players);
        editor.gameloop();
    }else if (mode == 2){
        std::vector<std::vector<int>>map;
        Editor editor(Vector2i(1366, 768),name, x, y, players);
        MapLoader loader;
        std::string  path("../map/" + name + ".yaml");
        loader.loadMap(path, map,players,name);
        editor.setMap(map);
        editor.gameloop();
    }
    return 0;

}
