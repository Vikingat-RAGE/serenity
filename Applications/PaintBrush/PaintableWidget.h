/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <LibGUI/Widget.h>

class PaintableWidget final : public GUI::Widget {
    C_OBJECT(PaintableWidget)
public:
    static PaintableWidget& the();

    virtual ~PaintableWidget() override;

    Color primary_color() const { return m_primary_color; }
    Color secondary_color() const { return m_secondary_color; }

    void set_primary_color(Color);
    void set_secondary_color(Color);

    Color color_for(const GUI::MouseEvent&) const;
    Color color_for(GUI::MouseButton) const;

    void set_bitmap(const Gfx::Bitmap&);

    Gfx::Bitmap& bitmap() { return *m_bitmap; }
    const Gfx::Bitmap& bitmap() const { return *m_bitmap; }

    Function<void(Color)> on_primary_color_change;
    Function<void(Color)> on_secondary_color_change;

private:
    PaintableWidget();

    RefPtr<Gfx::Bitmap> m_bitmap;

    Color m_primary_color { Color::Black };
    Color m_secondary_color { Color::White };
};
