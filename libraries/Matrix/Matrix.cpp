#include "Matrix.h"

Matrix::Matrix() {

  // parto dal centro
  r[0] = r[1] = c[0] = c[1] = 8;
  floor = 0;
  dir = 0;
}

void Matrix::check(float tempDx, float tempSx, float distDx, float distSx, byte color) { /// Controlla lo stato della cella
  maze[floor][r[floor]][c[floor]].visited = true;
  maze[floor][r[floor]][c[floor]].direction = dir;
  /*maze[floor][r[floor]][c[floor]].hot = tempdx > 68 || tempsx > 60;*/
  bool hotDx = tempDx >= DELTATEMP && distDx < DISTWALL;
  bool hotSx = tempSx >= DELTATEMP && distSx < DISTWALL;
  maze[floor][r[floor]][c[floor]].hot = hotDx || hotSx;
  if (color == 1) {
    checkr = r[floor];
    checkc = c[floor];
    checkfl = floor;
  }else if(color == 2) maze[floor][r[floor]][c[floor]].black = true;
}

void Matrix::changeFloor() {
  floor = !floor;
}

bool Matrix::frontCheck() { /// Restituisce vero se la cella davanti al bot è già stata visitata
  go();
  bool ris = maze[floor][r[floor]][c[floor]].visited;
  back();
  return ris;
}

bool Matrix::frontBlack() { /// Restituisce vero se la cella davanti al bot è nera
  go();
  bool ris = maze[floor][r[floor]][c[floor]].black;
  back();
  return ris;
}

void Matrix::reset() {
  r[floor][floor] = checkr;
  c[floor] = checkc;
  floor = checkfl;
  dir = maze[floor][r[floor]][c[floor]].direction;
}

void Matrix::go() {
  switch (dir) {
    case 0:
    r[floor]++;
    break;
    case 1:
    c[floor]++;
    break;
    case 2:
    r[floor]--;
    break;
    case 3:
    c[floor]--;
    break;
  }
}

void Matrix::back() {
  switch (dir) {
    case 0:
    r[floor]--;
    break;
    case 1:
    c[floor]--;
    break;
    case 2:
    r[floor]++;
    break;
    case 3:
    c[floor]++;
    break;
  }
}

byte Matrix::getDir(float dx, float front, float sx) { /// Ritorna 1 per destra, 2 per avanti, 3 per sinistra, 4 dietro
  byte saved_dir = dir;
  byte pdir = 4;
  rotate(false);
  if(!frontCheck() && !frontBlack() && dx < DISTWALL){
    pdir = 1;
    rotate(true);
  }else if (!frontCheck() && !frontBlack() && front < DISTWALL){
    pdir = 2;
    rotate(true);
  }else if(!frontCheck() && !frontBlack() && sx < DISTWALL){
    pdir = 3;
    dir = saved_dir;
    maze[floor][r[floor]][c[floor]].direction = saved_dir;
    rotate(false);
  }else if(!frontBlack() && dx < DISTWALL){
    pdir = 1;
    rotate(true);
  }else if (!frontBlack() && front < DISTWALL){
    pdir = 2;
    rotate(true);
  }else if(!frontBlack() && sx < DISTWALL){
    pdir = 3;
  }
  dir = saved_dir;
  maze[floor][r[floor]][c[floor]].direction = saved_dir;
  return dir;
}

void Matrix::rotate(bool direction) { /// Cambia direzione nella matrice (true = sinistra, false = destra)
  if (direction)
  dir = dir == 0 ? 3 : dir - 1;
  else
  dir = dir == 3 ? 0 : dir + 1;
  maze[floor][r[floor]][c[floor]].direction = dir;
}

bool Matrix::isHot() {
  return maze[floor][r[floor]][c[floor]].hot;
}

bool Matrix::isVisited() {
  return maze[floor][r[floor]][c[floor]].visited;
}
