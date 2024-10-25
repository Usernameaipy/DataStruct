#include "multitude.h"

Mul_T *initMul(int value) {
  if (value > INT_MAX || value < INT_MIN)
    return NULL;
  Mul_T *newMul = (Mul_T *)malloc(sizeof(Mul_T));
  if (newMul != NULL) {
    newMul->val = value;
    newMul->next = NULL;
    newMul->pref = NULL;
  }
  return newMul;
}

Mul_T *searchMul(Mul_T *root, int value) {
  if (!root || (value > INT_MAX || value < INT_MIN))
    return NULL;
  Mul_T *rootCp = root;
  Mul_T *cpy = NULL;
  while (rootCp != NULL) {
    if (rootCp->val == value) {
      cpy = rootCp;
      break;
    }
    rootCp = rootCp->next;
  }
  if (cpy)
    return cpy;
  return NULL;
}

bool insertMul(Mul_T *root, int value) {
  if ((!root) || (value > INT_MAX || value < INT_MIN))
    return false;
  if (!(searchMul(root, value))) {
    Mul_T *rootCp = root;
    while (rootCp->next != NULL) {
      rootCp = rootCp->next;
    }
    rootCp->next = initMul(value);
    if (rootCp->next != NULL) {
      Mul_T *cpy = rootCp;
      rootCp = rootCp->next;
      rootCp->pref = cpy;
      return true;
    } else
      return false;
  }
  return false;
}

bool deleteMul(Mul_T **root, int value) {
  if ((!root || !*root) || (value > INT_MAX || value < INT_MIN))
    return false;
  Mul_T *del = searchMul((*root), value);
  if (del) {
    Mul_T *nextMul = del->next;
    Mul_T *prefMul = del->pref;
    if (!nextMul && prefMul) {
      prefMul->next = NULL;
      free(del);
      return true;
    }
    if (nextMul && !prefMul) {
      free((*root));
      nextMul->pref = NULL;
      *root = (Mul_T *)nextMul;
      return true;
    }
    if (nextMul && prefMul) {
      nextMul->pref = prefMul;
      prefMul->next = nextMul;
      free(del);
      return true;
    } else {
      free(del);
      (*root) = NULL;
      return true;
    }
  }
  return false;
}

void printMul(Mul_T *root) {
  if (!root)
    return;
  Mul_T *rootCp = root;
  while (rootCp != NULL) {
    printf("%d ", rootCp->val);
    rootCp = rootCp->next;
  }
}

void removeMul(Mul_T **root) {
  if (!root || !(*root))
    return;
  if ((*root) != NULL) {
    removeMul(&((*root)->next));
    free((*root));
  }
  *root = NULL;
}
