#pragma once

#include "Event.h"

namespace PiggE {

    class PIGGE_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }
        inline int GetScanCode() const { return m_ScanCode; }
        inline int GetMods() const { return m_Mods; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode, int scancode = 0, int mods = 0)
            : m_KeyCode(keycode), m_ScanCode(scancode), m_Mods(mods)
        {}

        int m_KeyCode;
        int m_ScanCode;
        int m_Mods;
    };

    class PIGGE_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int scancode = 0, int mods = 0, int repeatCount = 0)
            : KeyEvent(keycode, scancode, mods), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed);
    private:
        int m_RepeatCount;
    };

    class PIGGE_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode, int scancode = 0, int mods = 0)
            : KeyEvent(keycode, scancode, mods) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class PIGGE_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(int keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped);
    };
}