/*********************************************************************/
/* Copyright (c) 2014-2018, EPFL/Blue Brain Project                  */
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

#ifndef WALLSURFACERENDERER_H
#define WALLSURFACERENDERER_H

#include "types.h"

#include "BackgroundRenderer.h"
#include "WallRenderContext.h"

#include <QObject>

class QQuickItem;

/**
 * Render a surface in Qml in the wall application.
 */
class WallSurfaceRenderer : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(WallSurfaceRenderer)

public:
    /**
     * Constructor.
     * @param context for rendering Qml elements.
     * @param parentItem to attach to.
     */
    WallSurfaceRenderer(WallRenderContext context, QQuickItem& parentItem);

    /** Destructor. */
    ~WallSurfaceRenderer();

    /** Set the Surface to render, replacing the previous one. */
    void setSurface(SurfacePtr surface);

    /** Set the touchpoint's markers. */
    void setMarkers(MarkersPtr markers);

    /** Set different options used for rendering. */
    void setRenderingOptions(OptionsPtr options);

    /** Set the ScreenLock replacing the previous one. */
    void setScreenLock(ScreenLockPtr lock);

    /** Set countdown status used to display the inactivity timeout. */
    void setCountdownStatus(CountdownStatusPtr status);

    /** @return true if the renderer requires a redraw. */
    bool needRedraw() const;

public slots:
    /** Increment number of rendered/swapped frames for FPS display. */
    void updateRenderedFrames();

private:
    WallRenderContext _context;
    QQmlContext& _qmlContext;

    SurfacePtr _surface;
    MarkersPtr _markers;
    OptionsPtr _options;
    ScreenLockPtr _screenLock;
    CountdownStatusPtr _countdownStatus;

    std::unique_ptr<QQuickItem> _surfaceItem;
    std::unique_ptr<BackgroundRenderer> _backgroundRenderer;
    std::unique_ptr<DisplayGroupRenderer> _displayGroupRenderer;

    void _setContextProperties();
    void _createSurfaceItem(QQuickItem& parentItem);
    void _createGroupRenderer();

    void _setBackground(const Background& background);
    bool _hasBackgroundChanged(const QString& newUri) const;
    void _adjustBackgroundTo(const DisplayGroup& displayGroup);
};

#endif
