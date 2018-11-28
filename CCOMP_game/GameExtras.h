#ifndef GameExtras_hpp
#define GameExtras_hpp
#include "buffs.h"
#include <vector>

class ExtrasManager {
public:
    static void init();
    static void getBuff(std::vector<Buff*> &v);
    static void DrawBuffs(std::vector<Buff*> &v);
    static void Verify(std::vector<Buff*> &v, std::vector<Buff*> &bull);
    static void Update(std::vector<Buff*> &v);
    //Facade
    
};

#endif /* GameExtras_hpp */
