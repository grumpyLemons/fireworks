#pragma once

#include <vector>
#include <algorithm>

namespace Core {
    template<typename Entity>
    class Server {
    public:
        void OnFrame(float dt) {
            for (Entity* entity: entities)
            {
                entity->OnFrame(dt);
            }
        }
        void RegisterEntity(Entity *entity) {
            entities.push_back(entity);
        }
        void UnregisterEntity(Entity *entity) {
            auto iterator = std::find(entities.begin(), entities.end(), entity);
            if(iterator != entities.end())
                entities.erase(iterator);
        }
    private:
        std::vector<Entity*> entities;
    protected:
        virtual void OnFrameImpl(float dt) {}
    };
}

