#ifndef Warlock_hpp
#define Warlock_hpp


#include "JsonEntityBuilder.hpp"
#include "entity.hpp"

Class Warlock : public Entity
{
    private:
            void EldritchBlast(Entity * target);
            void WeaponAttack(Entity * target);
            void SacredFlame(Entity * target);
    public:
            Warlock(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid);

            virtual void OutputStatus() const override;
            virtual void WeaponAttack(Entity * target) override;

            virtual void UseAction(Entity * target, const std::string& spellName, const std::string & args) override;


};

#endif