#ifndef _TREE_H_
#define _TREE_H_

class Tree {
private:
  static inline int objectCount = 0;
public:
  Tree() { objectCount++; }
  static  int getObjectCount() { return objectCount; }

};
#endif