//
//  Thanos.h
//  Thanos
//
//  Created by Mingmanas Sivaraksa on 24/4/2563 BE.
//  Copyright © 2563 Mingmanas Sivaraksa. All rights reserved.
//

#ifndef Thanos_h
#define Thanos_h
#include "monster.h"
class Thanos:public monster{
private:
    int stones;
    int hp; //extra hp;
public:
    /* constructor and destructor */
    void snap_finger(monster[]);
    /* show all hps
    / clear half of monster hp, if stones =6*/
    void operator++(); // increase the stone;
};


#endif /* Thanos_h */
