#include "botpch.h"
#include "../../playerbot.h"
#include "ImbueAction.h"
#include "../../PlayerbotAI.h"
#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"
using namespace ai;

bool ImbueWithStoneAction::Execute(Event& event)
{
    if (bot->IsInCombat())
        return false;

    // remove stealth
    if (bot->HasAura(SPELL_AURA_MOD_STEALTH))
        bot->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

    // hp check
    if (bot->getStandState() != UNIT_STAND_STATE_STAND)
        bot->SetStandState(UNIT_STAND_STATE_STAND);

    // Search and apply stone to weapons
    // Mainhand ...
    Item * stone, *weapon;
    weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        stone = ai->FindStoneFor(weapon);
        if (stone)
        {
            ai->ImbueItem(stone, EQUIPMENT_SLOT_MAINHAND);
            SetDuration(sPlayerbotAIConfig.globalCoolDown);
            return true;
        }
    }
    //... and offhand
    weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        stone = ai->FindStoneFor(weapon);
        if (stone)
        {
            ai->ImbueItem(stone, EQUIPMENT_SLOT_OFFHAND);
            SetDuration(sPlayerbotAIConfig.globalCoolDown);
            return true;
        }
    }

    return false;
}

bool ImbueWithStoneAction::isUseful()
{
    // Search and apply stone to weapons
    // Mainhand ...
    Item* weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        if (ai->FindStoneFor(weapon))
        {
            return true;
        }
    }

    //... and offhand
    weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        if (ai->FindStoneFor(weapon))
        {
            return true;
        }
    }

    return false;
}

bool ImbueWithOilAction::Execute(Event& event)
{
   if (bot->IsInCombat())
      return false;

   // remove stealth
   if (bot->HasAura(SPELL_AURA_MOD_STEALTH))
      bot->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

   // hp check
   if (bot->getStandState() != UNIT_STAND_STATE_STAND)
      bot->SetStandState(UNIT_STAND_STATE_STAND);

   // Search and apply oil to weapons
   Item* oil, *weapon;
   weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
   if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
   {
      oil = ai->FindOilFor(weapon);
      if (oil)
      {
         ai->ImbueItem(oil, EQUIPMENT_SLOT_MAINHAND);
         SetDuration(sPlayerbotAIConfig.globalCoolDown);
         return true;
      }
   }

   return false;
}

bool ImbueWithOilAction::isUseful()
{
    Item* weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        if (ai->FindOilFor(weapon))
        {
            return true;
        }
    }

    return false;
}

bool TryEmergencyAction::Execute(Event& event)
{
   // Do not use consumable if bot can heal self
   if ((ai->IsHeal(bot)) && (ai->GetManaPercent() > 20))
      return false;

   // If bot does not have aggro: use bandage instead of potion/stone/crystal
   if ((!(AI_VALUE(uint8, "my attacker count") >= 1)) && !bot->HasAura(11196)) // Recently bandaged
   {
      Item* bandage = ai->FindBandage();
      if (bandage)
      {
         ai->ImbueItem(bandage, bot);
         SetDuration(sPlayerbotAIConfig.globalCoolDown);
         return true;
      }
   }

   // Else loop over the list of health consumable to pick one
   Item* healthItem;
   for (uint8 i = 0; i < countof(uPriorizedHealingItemIds); ++i)
   {
      healthItem = ai->FindConsumable(uPriorizedHealingItemIds[i]);
      if (healthItem)
      {
         ai->ImbueItem(healthItem);
         return true;
      }
   }

   return false;
}
