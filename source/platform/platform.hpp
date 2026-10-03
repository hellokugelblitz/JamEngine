#ifndef PLATFORM_H
#define PLATFORM_H

struct Window;

struct PlatformManager {
    Window* window;

    PlatformManager() = default;
    ~PlatformManager();
};

#endif
