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

#include "ContentType.h"

#include <iostream>

bool contentTypeIsFile(const ContentType type)
{
    switch (type)
    {
    case ContentType::invalid:
    case ContentType::pixel_stream:
#if TIDE_ENABLE_WEBBROWSER_SUPPORT
    case ContentType::webbrowser:
#endif
        return false;
    default:
        return true;
    }
}

std::ostream& operator<<(std::ostream& str, const ContentType type)
{
    switch (type)
    {
    case ContentType::invalid:
        str << "invalid";
        break;
    case ContentType::dynamic_texture:
        str << "dynamic_texture";
        break;
#if TIDE_ENABLE_MOVIE_SUPPORT
    case ContentType::movie:
        str << "movie";
        break;
#endif
#if TIDE_ENABLE_PDF_SUPPORT
    case ContentType::pdf:
        str << "pdf";
        break;
#endif
#if TIDE_ENABLE_WEBBROWSER_SUPPORT
    case ContentType::webbrowser:
        str << "webbrowser";
        break;
#endif
#if TIDE_USE_TIFF
    case ContentType::image_pyramid:
        str << "image_pyramid";
        break;
#endif
    case ContentType::pixel_stream:
        str << "pixel_stream";
        break;
    case ContentType::svg:
        str << "svg";
        break;
    case ContentType::image:
        str << "image";
        break;
    }
    return str;
}
