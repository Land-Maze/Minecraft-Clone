#ifndef WINDOW_H
#define WINDOW_H
#pragma once

#include <string>

namespace Core {
class Window {
public:
    Window();
    ~Window();

    void Show();
    void Hide();
    void SetTitle(const std::string& title);
    void Resize(int width, int height);

    int GetWidth() const;
    int GetHeight() const;
    const std::string& GetTitle() const;
    bool IsVisible() const;

private:
    std::string m_title;
    int m_width;
    int m_height;
    bool m_visible;
};
}

#endif
