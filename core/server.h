#pragma once

#include <vector>

namespace Core {
    template<typename Entity>
    class Server {
    public:
        void OnFrame(float dt) {
            for (Entity* entity: entities)
            {
                entity.OnFrame(dt);
            }
            OnFrameImpl(dt);
        }
        void registerEntity(Entity *entity) {
            entities.push_back(entity)
        }
        void unregisterEntity(Entity *entity) {
            auto iterator = entities.find(entity);
            if(iterator != entities.end())
                entities.erase(iterator);
        }
    private:
        std::vector<Entity*> entities;
    protected:
        virtual void onFrameImpl(float dt) {}
    };
}

