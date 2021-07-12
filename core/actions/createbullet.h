#pragma once

#include "core/actions/iaction.h"
#include "core/gameinterface.h"

namespace Action{
    class CreateBullet final : public IAction{
    public:
        explicit CreateBullet(const GameInterface& iface);
        ~CreateBullet() override = default;

        void Execute() const override;

    private:
        const GameInterface& interface;
    };
}