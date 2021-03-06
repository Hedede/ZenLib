//
// Created by andre on 13.05.16.
//

#include <utils/logger.h>
#include "DaedalusStdlib.h"
#include "DaedalusVM.h"

#define OFFSET(c, v) (int32_t)(((char*)v) - ((char*)c))
#define REGISTER(cname, obj, var) vm.getDATFile().getSymbolByName(cname "." #var).dataOffset = OFFSET(&obj, &obj.var);

void Daedalus::registerDaedalusStdLib(Daedalus::DaedalusVM& vm, bool enableVerboseLogging)
{
    bool l = enableVerboseLogging;

    vm.registerExternalFunction("inttostring", [l](Daedalus::DaedalusVM& vm){
        int32_t x = vm.popDataValue();

        vm.setReturn(std::to_string(x));
    });

    vm.registerExternalFunction("floattoint", [l](Daedalus::DaedalusVM& vm){
        float x = *reinterpret_cast<float*>(vm.popDataValue());
        vm.setReturn(static_cast<int32_t>(x));
    });

    vm.registerExternalFunction("inttofloat", [l](Daedalus::DaedalusVM& vm){
        int32_t x = vm.popDataValue();
        float y = static_cast<float>(x);

        vm.setReturn(*reinterpret_cast<int32_t*>(&y));
    });

    vm.registerExternalFunction("concatstrings", [l](Daedalus::DaedalusVM& vm){
        std::string s2 = vm.popString();
        std::string s1 = vm.popString();

        vm.setReturn(s1 + s2);
    });

    vm.registerExternalFunction("hlp_strcmp", [l](Daedalus::DaedalusVM& vm){
        std::string s1 = vm.popString();
        std::string s2 = vm.popString();

        vm.setReturn(s1 == s2 ? 1 : 0);
    });

    vm.registerExternalFunction("hlp_random", [=](Daedalus::DaedalusVM& vm){
        int32_t n0 = vm.popDataValue();

        vm.setReturn(rand() % n0);
    });

    //
}

void Daedalus::registerGothicEngineClasses(DaedalusVM& vm)
{
    GEngineClasses::C_Npc npc;
    GEngineClasses::C_Focus focus;
    GEngineClasses::C_Info info;
    GEngineClasses::C_ItemReact itemreact;
    GEngineClasses::C_Item item;
    GEngineClasses::C_Mission mission;

    REGISTER("C_Npc", npc, id);
    REGISTER("C_Npc", npc, name);
    REGISTER("C_Npc", npc, slot);
    REGISTER("C_Npc", npc, npcType);
    REGISTER("C_Npc", npc, flags);
    REGISTER("C_Npc", npc, attribute);
    REGISTER("C_Npc", npc, protection);
    REGISTER("C_Npc", npc, damage);
    REGISTER("C_Npc", npc, damagetype);
    REGISTER("C_Npc", npc, guild);
    REGISTER("C_Npc", npc, level);
    REGISTER("C_Npc", npc, mission);
    REGISTER("C_Npc", npc, fight_tactic);
    REGISTER("C_Npc", npc, weapon);
    REGISTER("C_Npc", npc, voice);
    REGISTER("C_Npc", npc, voicePitch);
    REGISTER("C_Npc", npc, bodymass);
    REGISTER("C_Npc", npc, daily_routine);
    REGISTER("C_Npc", npc, start_aistate);
    REGISTER("C_Npc", npc, spawnPoint);
    REGISTER("C_Npc", npc, spawnDelay);
    REGISTER("C_Npc", npc, senses);
    REGISTER("C_Npc", npc, senses_range);
    REGISTER("C_Npc", npc, ai);
    REGISTER("C_Npc", npc, wp);
    REGISTER("C_Npc", npc, exp);
    REGISTER("C_Npc", npc, exp_next);
    REGISTER("C_Npc", npc, lp);

    REGISTER("C_Focus", focus, npc_longrange);
    REGISTER("C_Focus", focus, npc_range1);
    REGISTER("C_Focus", focus, npc_range2);
    REGISTER("C_Focus", focus, npc_azi);
    REGISTER("C_Focus", focus, npc_elevdo);
    REGISTER("C_Focus", focus, npc_elevup);
    REGISTER("C_Focus", focus, npc_prio);
    REGISTER("C_Focus", focus, item_range1);
    REGISTER("C_Focus", focus, item_range2);
    REGISTER("C_Focus", focus, item_azi);
    REGISTER("C_Focus", focus, item_elevdo);
    REGISTER("C_Focus", focus, item_elevup);
    REGISTER("C_Focus", focus, item_prio);
    REGISTER("C_Focus", focus, mob_range1);
    REGISTER("C_Focus", focus, mob_range2);
    REGISTER("C_Focus", focus, mob_azi);
    REGISTER("C_Focus", focus, mob_elevdo );
    REGISTER("C_Focus", focus, mob_elevup);
    REGISTER("C_Focus", focus, mob_prio);

    REGISTER("C_Info", info, npc);
    REGISTER("C_Info", info, nr);
    REGISTER("C_Info", info, important);
    REGISTER("C_Info", info, condition);
    REGISTER("C_Info", info, information);
    REGISTER("C_Info", info, description);
    REGISTER("C_Info", info, trade);
    REGISTER("C_Info", info, permanent);

    REGISTER("C_ItemReact", itemreact, npc);
    REGISTER("C_ItemReact", itemreact, trade_item);
    REGISTER("C_ItemReact", itemreact, trade_amount);
    REGISTER("C_ItemReact", itemreact, requested_cat);
    REGISTER("C_ItemReact", itemreact, requested_item);
    REGISTER("C_ItemReact", itemreact, requested_amount);
    REGISTER("C_ItemReact", itemreact, reaction);

    REGISTER("C_Item", item, id);
    REGISTER("C_Item", item, name );
    REGISTER("C_Item", item, nameID);
    REGISTER("C_Item", item, hp);
    REGISTER("C_Item", item, hp_max);
    REGISTER("C_Item", item, mainflag );
    REGISTER("C_Item", item, flags);
    REGISTER("C_Item", item, weight );
    REGISTER("C_Item", item, value);
    REGISTER("C_Item", item, damageType);
    REGISTER("C_Item", item, damageTotal);
    REGISTER("C_Item", item, damage);
    REGISTER("C_Item", item, wear);
    REGISTER("C_Item", item, protection);
    REGISTER("C_Item", item, nutrition);
    REGISTER("C_Item", item, cond_atr);
    REGISTER("C_Item", item, cond_value);
    REGISTER("C_Item", item, change_atr);
    REGISTER("C_Item", item, change_value);
    REGISTER("C_Item", item, magic   );
    REGISTER("C_Item", item, on_equip    );
    REGISTER("C_Item", item, on_unequip  );
    REGISTER("C_Item", item, on_state);
    REGISTER("C_Item", item, owner   );
    REGISTER("C_Item", item, ownerGuild    );
    REGISTER("C_Item", item, disguiseGuild);
    REGISTER("C_Item", item, visual);
    REGISTER("C_Item", item, visual_change );
    REGISTER("C_Item", item, visual_skin);
    REGISTER("C_Item", item, scemeName);
    REGISTER("C_Item", item, material);
    REGISTER("C_Item", item, munition);
    REGISTER("C_Item", item, spell);
    REGISTER("C_Item", item, range);
    REGISTER("C_Item", item, mag_circle);
    REGISTER("C_Item", item, description);
    REGISTER("C_Item", item, text);
    REGISTER("C_Item", item, count);

    REGISTER("C_Mission", mission, name);
    REGISTER("C_Mission", mission, description);
    REGISTER("C_Mission", mission, duration);
    REGISTER("C_Mission", mission, important);
    REGISTER("C_Mission", mission, offerConditions);
    REGISTER("C_Mission", mission, offer);
    REGISTER("C_Mission", mission, successConditions);
    REGISTER("C_Mission", mission, success);
    REGISTER("C_Mission", mission, failureConditions);
    REGISTER("C_Mission", mission, failure);
    REGISTER("C_Mission", mission, obsoleteConditions);
    REGISTER("C_Mission", mission, obsolete);
    REGISTER("C_Mission", mission, running);

}



