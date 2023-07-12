#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai 
{
    class MarkOfTheWildOnPartyTrigger : public BuffOnPartyTrigger 
    {
    public:
        MarkOfTheWildOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "mark of the wild", 4) {}
        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("gift of the wild", GetTarget()); }
    };

    class MarkOfTheWildTrigger : public BuffTrigger 
    {
    public:
        MarkOfTheWildTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "mark of the wild", 4) {}
        virtual bool IsActive() { return BuffTrigger::IsActive() &&  !ai->HasAura("gift of the wild", GetTarget()); }
    };

    class GiftOfTheWildOnPartyTrigger : public GreaterBuffOnPartyTrigger
    {
    public:
        GiftOfTheWildOnPartyTrigger(PlayerbotAI* ai) : GreaterBuffOnPartyTrigger(ai, "gift of the wild", "mark of the wild", 4) {}
    };

    class ThornsOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        ThornsOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "thorns", 4) {}

        virtual bool IsActive()
        {
            Unit* target = GetTarget();
            return BuffOnPartyTrigger::IsActive() && (!target->IsPlayer() || !ai->IsRanged((Player*)target));
        }
    };

    class ThornsTrigger : public BuffTrigger
    {
    public:
        ThornsTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "thorns", 4) {}
    };

    class OmenOfClarityTrigger : public BuffTrigger
    {
    public:
        OmenOfClarityTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "omen of clarity") {}
    };

    class RakeTrigger : public DebuffTrigger
    {
    public:
        RakeTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "rake") {}
    };

    class RipTrigger : public NoDebuffAndComboPointsAvailableTrigger
    {
    public:
        RipTrigger(PlayerbotAI* ai, uint8 comboPoints = 3) : NoDebuffAndComboPointsAvailableTrigger(ai, "rip", comboPoints) {}
    };

    class InsectSwarmTrigger : public DebuffTrigger
    {
    public:
        InsectSwarmTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "insect swarm") {}
    };

    class MoonfireTrigger : public DebuffTrigger
    {
    public:
        MoonfireTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "moonfire") {}
        virtual bool IsActive() { return DebuffTrigger::IsActive() && !GetTarget()->IsRooted(); }
    };

    class FaerieFireTrigger : public DebuffTrigger
    {
    public:
        FaerieFireTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "faerie fire") {}
    };

    class FaerieFireFeralTrigger : public DebuffTrigger
    {
    public:
        FaerieFireFeralTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "faerie fire (feral)") {}
    };

    class BashInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        BashInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "bash") {}
    };

    class TigersFuryTrigger : public BoostTrigger
    {
    public:
        TigersFuryTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "tiger's fury") {}
    };

    class NaturesGraspTrigger : public BoostTrigger
    {
    public:
        NaturesGraspTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "nature's grasp") {}
    };

    class EntanglingRootsTrigger : public HasCcTargetTrigger
    {
    public:
        EntanglingRootsTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "entangling roots") {}
    };

    class EntanglingRootsKiteTrigger : public DebuffTrigger
    {
    public:
        EntanglingRootsKiteTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "entangling roots") {}
        virtual bool IsActive();
    };

    class EntanglingRootsSnareTrigger : public SnareTargetTrigger
    {
    public:
        EntanglingRootsSnareTrigger(PlayerbotAI* ai) : SnareTargetTrigger(ai, "entangling roots", 5) {}
    };

    class HibernateTrigger : public HasCcTargetTrigger
    {
    public:
        HibernateTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "hibernate") {}
    };

    class CurePoisonTrigger : public NeedCureTrigger
    {
    public:
        CurePoisonTrigger(PlayerbotAI* ai) : NeedCureTrigger(ai, "cure poison", DISPEL_POISON) {}
    };

    class PartyMemberCurePoisonTrigger : public PartyMemberNeedCureTrigger
    {
    public:
        PartyMemberCurePoisonTrigger(PlayerbotAI* ai) : PartyMemberNeedCureTrigger(ai, "cure poison", DISPEL_POISON) {}
    };

    CURE_TRIGGER(RemoveCurseTrigger, "remove curse", DISPEL_CURSE);
    CURE_PARTY_TRIGGER(RemoveCurseOnPartyTrigger, "remove curse", DISPEL_CURSE);

    class BearFormTrigger : public BuffTrigger
    {
    public:
        BearFormTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "bear form") {}
        virtual bool IsActive() { return !ai->HasAnyAuraOf(bot, "bear form", "dire bear form", NULL); }
    };

    class TreeFormTrigger : public BuffTrigger
    {
    public:
        TreeFormTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "tree of life") {}
        virtual bool IsActive() { return !ai->HasAura("tree of life", bot); }
    };

    class MoonkinFormTrigger : public BuffTrigger
    {
    public:
        MoonkinFormTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "moonkin form") {}
        virtual bool IsActive() { return !ai->HasAura("moonkin form", bot); }
    };

    class CatFormTrigger : public BuffTrigger
    {
    public:
        CatFormTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "cat form") {}
        virtual bool IsActive() { return !ai->HasAura("cat form", bot); }
    };

    class EclipseSolarTrigger : public HasAuraTrigger
    {
    public:
        EclipseSolarTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "eclipse (solar)") {}
    };

    class EclipseLunarTrigger : public HasAuraTrigger
    {
    public:
        EclipseLunarTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "eclipse (lunar)") {}
    };

    class BashInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        BashInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "bash") {}
    };

    class NaturesSwiftnessTrigger : public BuffTrigger
    {
    public:
        NaturesSwiftnessTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "nature's swiftness") {}
    };

    class EnrageTrigger : public BuffTrigger
    {
    public:
        EnrageTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "enrage") {}

    private:
        bool IsActive() override
        {
            return AI_VALUE2(uint8, "health", "self target") >= sPlayerbotAIConfig.mediumHealth &&
                   AI_VALUE2(uint8, "rage", "self target") < 20;
        }
    };

    class LacerateTrigger : public DebuffTrigger
    {
    public:
        LacerateTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "lacerate") {}

    private:
        bool IsActive() override
        {
            Unit* target = GetTarget();
            return target && !ai->HasAura("lacerate", target, true) && !HasMaxDebuffs();
        }
    };

    class InStealthTrigger : public HasAuraTrigger
    {
    public:
        InStealthTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "prowl") {}
    };

    class NoStealthTrigger : public HasNoAuraTrigger
    {
    public:
        NoStealthTrigger(PlayerbotAI* ai) : HasNoAuraTrigger(ai, "prowl")
        {
            checkInterval = 2;
        }
    };

    class UnstealthTrigger : public BuffTrigger
    {
    public:
        UnstealthTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "prowl", 2) {}

        bool IsActive() override
        {
            if (!ai->HasAura("prowl", bot))
            {
                return false;
            }

            if (bot->InBattleGround())
            {
                return false;
            }

            return ai->HasAura("prowl", bot) &&
                !AI_VALUE(bool, "has attackers") &&
                !AI_VALUE(bool, "has enemy player targets") &&
                (AI_VALUE2(bool, "moving", "self target") &&
                    ((ai->GetMaster() &&
                        sServerFacade.IsDistanceGreaterThan(AI_VALUE2(float, "distance", "master target"), 10.0f) &&
                        AI_VALUE2(bool, "moving", "master target")) ||
                        !AI_VALUE(bool, "has attackers")));
        }
    };

    class StealthTrigger : public Trigger
    {
    public:
        StealthTrigger(PlayerbotAI* ai) : Trigger(ai, "prowl") {}

        bool IsActive() override
        {
            if (ai->HasAura("prowl", bot) || sServerFacade.IsInCombat(bot) || !sServerFacade.IsSpellReady(bot, 5215))
            {
                return false;
            }

            Unit* target = AI_VALUE(Unit*, "enemy player target");
            if (!target)
            {
                target = AI_VALUE(Unit*, "grind target");
            }
            if (!target)
            {
                target = AI_VALUE(Unit*, "dps target");
            }
            if (!target)
            {
                return false;
            }

            float distance = 30.0f;
            if (target && target->GetVictim())
            {
                distance -= 10;
            }

            if (sServerFacade.isMoving(target) && target->GetVictim())
            {
                distance -= 10;
            }

            if (bot->InBattleGround())
            {
                distance += 20;
            }

#ifndef MANGOSBOT_ZERO
            if (bot->InArena())
            {
                distance += 20;
            }
#endif

            return (target && sServerFacade.GetDistance2d(bot, target) < distance);
        }
    };

    class PowershiftTrigger : public Trigger
    {
    public:
        PowershiftTrigger(PlayerbotAI* ai) : Trigger(ai, "powershift") {}

        bool IsActive() override
        {
            if (ai->HasAura("cat form", bot) &&
                AI_VALUE2(uint8, "energy", "self target") < 20 &&
                AI_VALUE2(uint8, "mana", "self target") > sPlayerbotAIConfig.lowMana)
            {
                return true;
            }

            return false;
        }
    };

    class FerociousBiteTrigger : public ComboPointsAvailableTrigger
    {
    public:
        FerociousBiteTrigger(PlayerbotAI* ai) : ComboPointsAvailableTrigger(ai, 5) {}
    };
}
