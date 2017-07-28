#include <dungeon.hpp>
#include <iostream>
#include <string>

Dungeon::Dungeon(int width, int height) {
        w = width;
        h = height;
        Cell **map = new Cell[w][h];
}

/*
Dungeon::~Dungeon() {
        delete [] map;
}
*/

void Dungeon::display_dungeon() {
        for (int y = 0; y < h; y++)
        {               
                for (int x = 0; x < w; x++)
                {
                        if (map[x][y].tile == floor) {
                                std::cout << ' ';
                        }
                        if (map[x][y].tile == wall) {
                                std::cout << '#';
                        }
                        if (map[x][y].tile == edge) {
                                std::cout << 'E';
                        }
                        if (map[x][y] == NULL) {
                                std::cout << '!';
                        }
                }
                std::cout << endl;
        }
}

//void Dungeon::display_empty() {

int Dungeon::width() {
        return w;
}

int Dungeon::height() {
        return w;
}
