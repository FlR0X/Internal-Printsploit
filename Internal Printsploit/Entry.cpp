#include <Windows.h>

#define GameModuleBase (reinterpret_cast<uintptr_t>(GetModuleHandleA("RobloxPlayerBeta.exe")))

int ExecutePrints() {
    uintptr_t printaddy = GameModuleBase + 0x155C160; // roblox offset
    using PrintFunc = int(__fastcall*)(int, const char*, ...);
    auto PrintMessage = reinterpret_cast<PrintFunc>(printaddy);

    enum class PrintLevel : int {
        Normal = 0,
        Info = 1,
        Warning = 2,
        Error = 3
    };


    while (true) {
        PrintMessage(static_cast<int>(PrintLevel::Normal), "Normal // Updated");
        Sleep(1000);
        PrintMessage(static_cast<int>(PrintLevel::Info), "Info // Updated");
        Sleep(1000);
        PrintMessage(static_cast<int>(PrintLevel::Warning), "Warning // Updated");
        Sleep(1000);
        PrintMessage(static_cast<int>(PrintLevel::Error), "Error // Updated");
        Sleep(1000);
    }


    return 1;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        ExecutePrints();
        DisableThreadLibraryCalls(module);
    }
    return TRUE;
}
