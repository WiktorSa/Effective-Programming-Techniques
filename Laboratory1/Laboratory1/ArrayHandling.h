#ifndef ARRAYHANDLING_H
#define ARRAYHANDLING_H
#include "CTable.h"

void v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY);
void v_mod_tab(CTable* pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);
void v_test();

#endif
