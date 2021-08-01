/* Copyright (C) 2020 - 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/hope
 */

#pragma once

#include "queue.h"
#include "event.h"
#include <functional>
#include <thread>

namespace hope::concurrency {

    class async_worker final
    {
    public:
        using job = std::function<void()>;
        async_worker() noexcept;

        void run() noexcept;

        void stop() noexcept;

        void shut_down() noexcept;

        void add_job(job&& task) noexcept;

        void wait() const noexcept;
    private:
        void run_impl() noexcept;

        std::atomic_flag m_shut_down;
        std::atomic_bool m_wait;
        std::atomic_bool m_launched;
        queue<job> m_job_queue;
        std::thread m_thread_impl;

        auto_reset_event m_job_added;
        auto_reset_event m_jobs_complete;
    };

}
