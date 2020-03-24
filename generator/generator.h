#ifndef GENERATOR_H
#define GENERATOR_H

int RandBetween(int low, int high);
void PrintGraph(int **graph, int n);
void PrintArray(int *array, int n);
int *GenerateArray(int n, int low, int high);
int **GenerateGraph(int n, int m, int low_w, int high_w);
bool BigFirst(int &a, int &b);

#endif