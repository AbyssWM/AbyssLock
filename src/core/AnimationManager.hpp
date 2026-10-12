#pragma once

#include <abyssutils/animation/AnimationManager.hpp>
#include <abyssutils/animation/AnimatedVariable.hpp>

#include "../helpers/AnimatedVariable.hpp"
#include "../defines.hpp"

class CAbysslockAnimationManager : public Abyssutils::Animation::CAnimationManager {
  public:
    CAbysslockAnimationManager();

    void         tick();
    virtual void scheduleTick();
    virtual void onTicked();

    using SAnimationPropertyConfig = Abyssutils::Animation::SAnimationPropertyConfig;

    template <Animable VarType>
    void createAnimation(const VarType& v, PHLANIMVAR<VarType>& pav, SP<SAnimationPropertyConfig> pConfig) {
        constexpr const eAnimatedVarType EAVTYPE = typeToeAnimatedVarType<VarType>;
        pav                                      = makeUnique<CAnimatedVariable<VarType>>();

        pav->create2(EAVTYPE, static_cast<Abyssutils::Animation::CAnimationManager*>(this), pav, v);
        pav->setConfig(pConfig);
    }

    bool m_bTickScheduled = false;
};

inline UP<CAbysslockAnimationManager> g_pAnimationManager;
