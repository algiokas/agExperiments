#ifndef DUNGEON_H
#define DUNGEON_H

#include <string>

enum Tile {
        floor,
        wall,
        edge
};

struct Cell {
        int x;
        int y;
        Tile tile;
};

class Dungeon {

        public:
                Dungeon(int width, int height);
                //~Dungeon();
                void display_dungeon();
                //void display_empty();
                //void write_dungeon(string filename);
                //cell* get_cell(int x, int y); 
                //void edit_cell(int x, int y, Tile tile);
                int width();
                int height();

        private:
                int w, h;
                Cell** map;

                void gen_map(int width, int height);

};


#endif 

