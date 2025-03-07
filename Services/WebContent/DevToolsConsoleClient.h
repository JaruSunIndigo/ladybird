/*
 * Copyright (c) 2025, Tim Flynn <trflynn89@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Console.h>
#include <LibJS/Forward.h>
#include <LibWeb/Forward.h>
#include <WebContent/Forward.h>
#include <WebContent/WebContentConsoleClient.h>

namespace WebContent {

class DevToolsConsoleClient final : public WebContentConsoleClient {
    GC_CELL(DevToolsConsoleClient, WebContentConsoleClient);
    GC_DECLARE_ALLOCATOR(DevToolsConsoleClient);

public:
    static GC::Ref<DevToolsConsoleClient> create(JS::Realm&, JS::Console&, PageClient&);
    virtual ~DevToolsConsoleClient() override;

private:
    DevToolsConsoleClient(JS::Realm&, JS::Console&, PageClient&, ConsoleGlobalEnvironmentExtensions&);

    virtual void handle_result(JS::Value) override;
    virtual void report_exception(JS::Error const&, bool) override;
    virtual void send_messages(i32 start_index) override;

    virtual JS::ThrowCompletionOr<JS::Value> printer(JS::Console::LogLevel log_level, PrinterArguments) override;
};

}
