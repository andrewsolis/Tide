/*********************************************************************/
/* Copyright (c) 2013-2018, EPFL/Blue Brain Project                  */
/*                          Daniel Nachbaur <daniel.nachbaur@epfl.ch>*/
/*                          Raphael Dumusc <raphael.dumusc@epfl.ch>  */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/*   1. Redistributions of source code must retain the above         */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer.                                                  */
/*                                                                   */
/*   2. Redistributions in binary form must reproduce the above      */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer in the documentation and/or other materials       */
/*      provided with the distribution.                              */
/*                                                                   */
/*    THIS  SOFTWARE  IS  PROVIDED  BY  THE  ECOLE  POLYTECHNIQUE    */
/*    FEDERALE DE LAUSANNE  ''AS IS''  AND ANY EXPRESS OR IMPLIED    */
/*    WARRANTIES, INCLUDING, BUT  NOT  LIMITED  TO,  THE  IMPLIED    */
/*    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  A PARTICULAR    */
/*    PURPOSE  ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  ECOLE    */
/*    POLYTECHNIQUE  FEDERALE  DE  LAUSANNE  OR  CONTRIBUTORS  BE    */
/*    LIABLE  FOR  ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,    */
/*    EXEMPLARY,  OR  CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT NOT    */
/*    LIMITED TO,  PROCUREMENT  OF  SUBSTITUTE GOODS OR SERVICES;    */
/*    LOSS OF USE, DATA, OR  PROFITS;  OR  BUSINESS INTERRUPTION)    */
/*    HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY,  WHETHER IN    */
/*    CONTRACT, STRICT LIABILITY,  OR TORT  (INCLUDING NEGLIGENCE    */
/*    OR OTHERWISE) ARISING  IN ANY WAY  OUT OF  THE USE OF  THIS    */
/*    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of Ecole polytechnique federale de Lausanne.          */
/*********************************************************************/

#ifndef TYPES_H
#define TYPES_H

#include <deflect/server/types.h>

#include <QRectF>
#include <QString>

#include <exception>
#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

/**
 * The type of texture formats that Tide can render.
 */
enum class TextureFormat
{
    rgba,
    yuv420,
    yuv422,
    yuv444
};

/**
 * The supported color spaces for rendering image textures.
 */
enum class ColorSpace
{
    undefined,
    yCbCrJpeg,
    yCbCrVideo
};

/**
 * The power state of the wall's displays.
 */
enum class ScreenState
{
    on,
    off,
    undefined
};

/**
 * The methods for synchronizing the GL buffer swap.
 */
enum class SwapSync
{
    software,
    hardware
};

/**
 * The different texture update policies.
 */
enum class TextureType
{
    static_,
    dynamic
};

class ActivityLogger;
class Background;
class Configuration;
class Content;
class ContentSynchronizer;
class ContextMenu;
class ContextMenuController;
class CountdownStatus;
class DataProvider;
class DataSource;
class DisplayGroup;
class DisplayGroupController;
class DisplayGroupRenderer;
class FFMPEGFrame;
class FFMPEGMovie;
class FFMPEGPicture;
class FFMPEGVideoStream;
class Image;
class ImageReader;
class ImageSource;
class ImagePyramidDataSource;
class InactivityTimer;
class KeyboardState;
class LodTools;
class Markers;
class MovieContent;
class MovieUpdater;
class MPICommunicator;
class NetworkBarrier;
class Options;
class PDFContent;
class PixelStreamContent;
class PixelStreamUpdater;
class PixelStreamWindowManager;
struct Process;
class Scene;
class Session;
struct SessionInfo;
class ScreenLock;
class SharedNetworkBarrier;
class SideController;
class Surface;
struct SurfaceConfig;
class SwapSynchronizer;
class TestPattern;
class Tile;
struct WallConfiguration;
class WallSurfaceRenderer;
class WallToWallChannel;
class WallWindow;
class WebbrowserContent;
class Window;

typedef std::shared_ptr<Background> BackgroundPtr;
typedef std::unique_ptr<Content> ContentPtr;
typedef std::shared_ptr<ContentSynchronizer> ContentSynchronizerSharedPtr;
typedef std::shared_ptr<ContextMenu> ContextMenuPtr;
typedef std::shared_ptr<CountdownStatus> CountdownStatusPtr;
typedef std::shared_ptr<DataSource> DataSourceSharedPtr;
typedef std::shared_ptr<DisplayGroup> DisplayGroupPtr;
typedef std::shared_ptr<FFMPEGPicture> PicturePtr;
typedef std::shared_ptr<Image> ImagePtr;
typedef std::shared_ptr<Markers> MarkersPtr;
typedef std::shared_ptr<Options> OptionsPtr;
typedef std::shared_ptr<Scene> ScenePtr;
typedef std::shared_ptr<ScreenLock> ScreenLockPtr;
typedef std::shared_ptr<Surface> SurfacePtr;
typedef std::shared_ptr<Tile> TilePtr;
typedef std::weak_ptr<Tile> TileWeakPtr;
typedef std::shared_ptr<Window> WindowPtr;
typedef std::unique_ptr<WallWindow> WallWindowPtr;

typedef std::set<WindowPtr> WindowSet;
typedef std::vector<WindowPtr> WindowPtrs;
typedef std::set<size_t> Indices;
typedef std::vector<QPointF> Positions;

using BoolCallback = std::function<void(bool)>;
using BoolMsgCallback = std::function<void(bool, QString)>;
using ScreenStateCallback = std::function<void(ScreenState)>;

class load_error : public std::runtime_error
{
    using runtime_error::runtime_error;
};

static constexpr QRectF UNIT_RECTF(0.0, 0.0, 1.0, 1.0);
static constexpr QSize UNDEFINED_SIZE(-1, -1);

inline bool operator<(const QSizeF& a, const QSizeF& b)
{
    return (a.width() < b.width() || a.height() < b.height());
}

inline bool operator<=(const QSizeF& a, const QSizeF& b)
{
    return (a.width() <= b.width() || a.height() <= b.height());
}

inline bool operator>(const QSizeF& a, const QSizeF& b)
{
    return (a.width() > b.width() || a.height() > b.height());
}

inline bool operator>=(const QSizeF& a, const QSizeF& b)
{
    return (a.width() >= b.width() || a.height() >= b.height());
}

inline std::ostream& operator<<(std::ostream& str, const QSizeF& s)
{
    str << s.width() << 'x' << s.height();
    return str;
}

inline std::ostream& operator<<(std::ostream& str, const QPointF& p)
{
    str << p.x() << ',' << p.y();
    return str;
}

inline std::ostream& operator<<(std::ostream& str, const ScreenState state)
{
    switch (state)
    {
    case ScreenState::on:
        str << "on";
        break;
    case ScreenState::off:
        str << "off";
        break;
    case ScreenState::undefined:
        str << "undefined";
        break;
    }
    return str;
}

inline std::ostream& operator<<(std::ostream& str, const QRectF& r)
{
    str << r.x() << ',' << r.y() << ' ' << r.width() << 'x' << r.height();
    return str;
}

inline std::ostream& operator<<(std::ostream& str, const QString& s)
{
    str << s.toStdString();
    return str;
}

#endif
