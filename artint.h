#ifndef ARTINT_H
#define ARTINT_H

class ArtInt {
private:
  bool piece;
  int* scores;
public:
  ArtInt(bool);
  bool is_x();
  int doTurn();
};

#endif
