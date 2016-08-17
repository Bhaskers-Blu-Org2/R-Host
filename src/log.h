/* ****************************************************************************
 *
 * Copyright (c) Microsoft Corporation. All rights reserved. 
 *
 *
 * This file is part of Microsoft R Host.
 * 
 * Microsoft R Host is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Microsoft R Host is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Microsoft R Host.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ***************************************************************************/

#pragma once
#include "stdafx.h"

namespace rhost {
    namespace log {
        enum class log_level {
            trace,
            information,
            warning,
            error
        };

        void init_log(const std::string& log_suffix);

        void vlogf(log_level level, const char* format, va_list va);

        inline void logf(log_level level, const char* format, ...) {
            va_list va;
            va_start(va, format);
            vlogf(level, format, va);
            va_end(format);
        }

        inline void vlogf(const char* format, va_list va) {
            vlogf(log_level::trace, format, va);
        }

        inline void logf(const char* format, ...) {
            va_list va;
            va_start(va, format);
            vlogf(format, va);
            va_end(format);
        }

        void indent_log(int n);

        void flush_log();

        __declspec(noreturn) void terminate(const char* format, ...);

        __declspec(noreturn) void fatal_error(const char* format, ...);
    }
}
