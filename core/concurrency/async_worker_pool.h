/* Copyright (C) 2020 - 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/hope
 */

#pragma once

#include "async_worker.h"
#include <array>

namespace hope::concurrency {

    template<std::size_t ThreadCount>
    class async_worker_pool final {
        using WorkersPool = std::array<async_worker, ThreadCount>;
    public:
        using Job = async_worker::job;
        async_worker_pool() noexcept = default;

        void run() noexcept;

        void stop() noexcept;

        void shutdown() noexcept;

        void add_job(Job&& task) noexcept;

        void wait();
    private:
        WorkersPool m_pool;
    };

    template <std::size_t ThreadCount>
    void async_worker_pool<ThreadCount>::run() noexcept {
        for (auto&& thread : m_pool)
            thread.run();
    }

    template <std::size_t ThreadCount>
    void async_worker_pool<ThreadCount>::stop() noexcept {
        for (auto&& thread : m_pool)
            thread.stop();
    }

    template <std::size_t ThreadCount>
    void async_worker_pool<ThreadCount>::shutdown() noexcept {
        for (auto&& thread : m_pool)
            thread.shutdown();
    }

    template <std::size_t ThreadCount>
    void async_worker_pool<ThreadCount>::add_job(Job&& task) noexcept {
        std::size_t thread_index = (1 + ThreadCount) * std::rand() / RAND_MAX;
        thread_index = thread_index % ThreadCount;
        m_pool[thread_index].add_job(std::move(task));
    }

    template <std::size_t ThreadCount>
    void async_worker_pool<ThreadCount>::wait() {
        for (auto&& thread : m_pool)
            thread.wait();
    }
}
