/*
 * Copyright (C) 2021 CutefishOS Team.
 *
 * Author:     revenmartin <revenmartin@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "application.h"
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    // putenv((char *)"SESSION_MANAGER=");

    if (qEnvironmentVariableIsEmpty("QT_QPA_PLATFORM")) {
        const bool hasWayland = !qEnvironmentVariableIsEmpty("WAYLAND_DISPLAY") ||
            qgetenv("XDG_SESSION_TYPE") == QByteArrayLiteral("wayland");
        qputenv("QT_QPA_PLATFORM", hasWayland ? QByteArrayLiteral("wayland")
                                              : QByteArrayLiteral("xcb"));
    }

    QQuickWindow::setDefaultAlphaBuffer(true);
    QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling);

    Application a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    return a.exec();
}
