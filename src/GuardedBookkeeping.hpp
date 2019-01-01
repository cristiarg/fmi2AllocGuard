#ifndef FMI2GUARDEDBOOKKEEPING_H
#define FMI2GUARDEDBOOKKEEPING_H

#include "fmi2AllocGuard.h"
#include "PointerKeeper.hpp"

struct fmi2_guarded_alloc_free_str {
  int                  id;
  fmi2_guarded_alloc_t calloc_p;
  fmi2_guarded_free_t  free_p;
  PointerKeeper*       pointer_keeper;
};

void* fmi2_calloc1 ( size_t _num , size_t _size );
void* fmi2_calloc2 ( size_t _num , size_t _size );
void* fmi2_calloc3 ( size_t _num , size_t _size );
void* fmi2_calloc4 ( size_t _num , size_t _size );
void* fmi2_calloc5 ( size_t _num , size_t _size );
void* fmi2_calloc6 ( size_t _num , size_t _size );
void* fmi2_calloc7 ( size_t _num , size_t _size );
void* fmi2_calloc8 ( size_t _num , size_t _size );
void* fmi2_calloc9 ( size_t _num , size_t _size );
void* fmi2_calloc10 ( size_t _num , size_t _size );
void* fmi2_calloc11 ( size_t _num , size_t _size );
void* fmi2_calloc12 ( size_t _num , size_t _size );
void* fmi2_calloc13 ( size_t _num , size_t _size );
void* fmi2_calloc14 ( size_t _num , size_t _size );
void* fmi2_calloc15 ( size_t _num , size_t _size );
void* fmi2_calloc16 ( size_t _num , size_t _size );
void* fmi2_calloc17 ( size_t _num , size_t _size );
void* fmi2_calloc18 ( size_t _num , size_t _size );
void* fmi2_calloc19 ( size_t _num , size_t _size );
void* fmi2_calloc20 ( size_t _num , size_t _size );
void* fmi2_calloc21 ( size_t _num , size_t _size );
void* fmi2_calloc22 ( size_t _num , size_t _size );
void* fmi2_calloc23 ( size_t _num , size_t _size );
void* fmi2_calloc24 ( size_t _num , size_t _size );
void* fmi2_calloc25 ( size_t _num , size_t _size );
void* fmi2_calloc26 ( size_t _num , size_t _size );
void* fmi2_calloc27 ( size_t _num , size_t _size );
void* fmi2_calloc28 ( size_t _num , size_t _size );
void* fmi2_calloc29 ( size_t _num , size_t _size );
void* fmi2_calloc30 ( size_t _num , size_t _size );
void* fmi2_calloc31 ( size_t _num , size_t _size );
void* fmi2_calloc32 ( size_t _num , size_t _size );
void* fmi2_calloc33 ( size_t _num , size_t _size );
void* fmi2_calloc34 ( size_t _num , size_t _size );
void* fmi2_calloc35 ( size_t _num , size_t _size );
void* fmi2_calloc36 ( size_t _num , size_t _size );
void* fmi2_calloc37 ( size_t _num , size_t _size );
void* fmi2_calloc38 ( size_t _num , size_t _size );
void* fmi2_calloc39 ( size_t _num , size_t _size );
void* fmi2_calloc40 ( size_t _num , size_t _size );
void* fmi2_calloc41 ( size_t _num , size_t _size );
void* fmi2_calloc42 ( size_t _num , size_t _size );
void* fmi2_calloc43 ( size_t _num , size_t _size );
void* fmi2_calloc44 ( size_t _num , size_t _size );
void* fmi2_calloc45 ( size_t _num , size_t _size );
void* fmi2_calloc46 ( size_t _num , size_t _size );
void* fmi2_calloc47 ( size_t _num , size_t _size );
void* fmi2_calloc48 ( size_t _num , size_t _size );
void* fmi2_calloc49 ( size_t _num , size_t _size );
void* fmi2_calloc50 ( size_t _num , size_t _size );
void* fmi2_calloc51 ( size_t _num , size_t _size );
void* fmi2_calloc52 ( size_t _num , size_t _size );
void* fmi2_calloc53 ( size_t _num , size_t _size );
void* fmi2_calloc54 ( size_t _num , size_t _size );
void* fmi2_calloc55 ( size_t _num , size_t _size );
void* fmi2_calloc56 ( size_t _num , size_t _size );
void* fmi2_calloc57 ( size_t _num , size_t _size );
void* fmi2_calloc58 ( size_t _num , size_t _size );
void* fmi2_calloc59 ( size_t _num , size_t _size );
void* fmi2_calloc60 ( size_t _num , size_t _size );
void* fmi2_calloc61 ( size_t _num , size_t _size );
void* fmi2_calloc62 ( size_t _num , size_t _size );
void* fmi2_calloc63 ( size_t _num , size_t _size );
void* fmi2_calloc64 ( size_t _num , size_t _size );
void* fmi2_calloc65 ( size_t _num , size_t _size );
void* fmi2_calloc66 ( size_t _num , size_t _size );
void* fmi2_calloc67 ( size_t _num , size_t _size );
void* fmi2_calloc68 ( size_t _num , size_t _size );
void* fmi2_calloc69 ( size_t _num , size_t _size );
void* fmi2_calloc70 ( size_t _num , size_t _size );
void* fmi2_calloc71 ( size_t _num , size_t _size );
void* fmi2_calloc72 ( size_t _num , size_t _size );
void* fmi2_calloc73 ( size_t _num , size_t _size );
void* fmi2_calloc74 ( size_t _num , size_t _size );
void* fmi2_calloc75 ( size_t _num , size_t _size );
void* fmi2_calloc76 ( size_t _num , size_t _size );
void* fmi2_calloc77 ( size_t _num , size_t _size );
void* fmi2_calloc78 ( size_t _num , size_t _size );
void* fmi2_calloc79 ( size_t _num , size_t _size );
void* fmi2_calloc80 ( size_t _num , size_t _size );
void* fmi2_calloc81 ( size_t _num , size_t _size );
void* fmi2_calloc82 ( size_t _num , size_t _size );
void* fmi2_calloc83 ( size_t _num , size_t _size );
void* fmi2_calloc84 ( size_t _num , size_t _size );
void* fmi2_calloc85 ( size_t _num , size_t _size );
void* fmi2_calloc86 ( size_t _num , size_t _size );
void* fmi2_calloc87 ( size_t _num , size_t _size );
void* fmi2_calloc88 ( size_t _num , size_t _size );
void* fmi2_calloc89 ( size_t _num , size_t _size );
void* fmi2_calloc90 ( size_t _num , size_t _size );
void* fmi2_calloc91 ( size_t _num , size_t _size );
void* fmi2_calloc92 ( size_t _num , size_t _size );
void* fmi2_calloc93 ( size_t _num , size_t _size );
void* fmi2_calloc94 ( size_t _num , size_t _size );
void* fmi2_calloc95 ( size_t _num , size_t _size );
void* fmi2_calloc96 ( size_t _num , size_t _size );
void* fmi2_calloc97 ( size_t _num , size_t _size );
void* fmi2_calloc98 ( size_t _num , size_t _size );
void* fmi2_calloc99 ( size_t _num , size_t _size );
void* fmi2_calloc100 ( size_t _num , size_t _size );

void fmi2_free1 ( void* _ptr );
void fmi2_free2 ( void* _ptr );
void fmi2_free3 ( void* _ptr );
void fmi2_free4 ( void* _ptr );
void fmi2_free5 ( void* _ptr );
void fmi2_free6 ( void* _ptr );
void fmi2_free7 ( void* _ptr );
void fmi2_free8 ( void* _ptr );
void fmi2_free9 ( void* _ptr );
void fmi2_free10 ( void* _ptr );
void fmi2_free11 ( void* _ptr );
void fmi2_free12 ( void* _ptr );
void fmi2_free13 ( void* _ptr );
void fmi2_free14 ( void* _ptr );
void fmi2_free15 ( void* _ptr );
void fmi2_free16 ( void* _ptr );
void fmi2_free17 ( void* _ptr );
void fmi2_free18 ( void* _ptr );
void fmi2_free19 ( void* _ptr );
void fmi2_free20 ( void* _ptr );
void fmi2_free21 ( void* _ptr );
void fmi2_free22 ( void* _ptr );
void fmi2_free23 ( void* _ptr );
void fmi2_free24 ( void* _ptr );
void fmi2_free25 ( void* _ptr );
void fmi2_free26 ( void* _ptr );
void fmi2_free27 ( void* _ptr );
void fmi2_free28 ( void* _ptr );
void fmi2_free29 ( void* _ptr );
void fmi2_free30 ( void* _ptr );
void fmi2_free31 ( void* _ptr );
void fmi2_free32 ( void* _ptr );
void fmi2_free33 ( void* _ptr );
void fmi2_free34 ( void* _ptr );
void fmi2_free35 ( void* _ptr );
void fmi2_free36 ( void* _ptr );
void fmi2_free37 ( void* _ptr );
void fmi2_free38 ( void* _ptr );
void fmi2_free39 ( void* _ptr );
void fmi2_free40 ( void* _ptr );
void fmi2_free41 ( void* _ptr );
void fmi2_free42 ( void* _ptr );
void fmi2_free43 ( void* _ptr );
void fmi2_free44 ( void* _ptr );
void fmi2_free45 ( void* _ptr );
void fmi2_free46 ( void* _ptr );
void fmi2_free47 ( void* _ptr );
void fmi2_free48 ( void* _ptr );
void fmi2_free49 ( void* _ptr );
void fmi2_free50 ( void* _ptr );
void fmi2_free51 ( void* _ptr );
void fmi2_free52 ( void* _ptr );
void fmi2_free53 ( void* _ptr );
void fmi2_free54 ( void* _ptr );
void fmi2_free55 ( void* _ptr );
void fmi2_free56 ( void* _ptr );
void fmi2_free57 ( void* _ptr );
void fmi2_free58 ( void* _ptr );
void fmi2_free59 ( void* _ptr );
void fmi2_free60 ( void* _ptr );
void fmi2_free61 ( void* _ptr );
void fmi2_free62 ( void* _ptr );
void fmi2_free63 ( void* _ptr );
void fmi2_free64 ( void* _ptr );
void fmi2_free65 ( void* _ptr );
void fmi2_free66 ( void* _ptr );
void fmi2_free67 ( void* _ptr );
void fmi2_free68 ( void* _ptr );
void fmi2_free69 ( void* _ptr );
void fmi2_free70 ( void* _ptr );
void fmi2_free71 ( void* _ptr );
void fmi2_free72 ( void* _ptr );
void fmi2_free73 ( void* _ptr );
void fmi2_free74 ( void* _ptr );
void fmi2_free75 ( void* _ptr );
void fmi2_free76 ( void* _ptr );
void fmi2_free77 ( void* _ptr );
void fmi2_free78 ( void* _ptr );
void fmi2_free79 ( void* _ptr );
void fmi2_free80 ( void* _ptr );
void fmi2_free81 ( void* _ptr );
void fmi2_free82 ( void* _ptr );
void fmi2_free83 ( void* _ptr );
void fmi2_free84 ( void* _ptr );
void fmi2_free85 ( void* _ptr );
void fmi2_free86 ( void* _ptr );
void fmi2_free87 ( void* _ptr );
void fmi2_free88 ( void* _ptr );
void fmi2_free89 ( void* _ptr );
void fmi2_free90 ( void* _ptr );
void fmi2_free91 ( void* _ptr );
void fmi2_free92 ( void* _ptr );
void fmi2_free93 ( void* _ptr );
void fmi2_free94 ( void* _ptr );
void fmi2_free95 ( void* _ptr );
void fmi2_free96 ( void* _ptr );
void fmi2_free97 ( void* _ptr );
void fmi2_free98 ( void* _ptr );
void fmi2_free99 ( void* _ptr );
void fmi2_free100 ( void* _ptr );

extern struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ];

void fmi2_guarded_bookkeeping_init();

#endif // FMI2GUARDEDBOOKKEEPING_H
