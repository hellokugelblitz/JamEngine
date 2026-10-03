#ifndef WINDOW_H
#define WINDOW_H

struct Window {
    virtual ~Window() = default;
    virtual void prepare_frame() = 0;
    virtual void end_frame() = 0;
    virtual bool is_close_requested() = 0;
    virtual void close() = 0;
    virtual bool resized() = 0;
};

#endif
