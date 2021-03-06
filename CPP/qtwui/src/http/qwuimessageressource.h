/***************************************************************************
 *   Copyright (C) 2007 by Eric ALBER                                      *
 *   eric.alber@gmail.com                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef QWUIMESSAGERESSOURCE_H
#define QWUIMESSAGERESSOURCE_H

#include <QtWui/QwuiAbstractRessource>
#include <QtWui/QwuiGlobal>

/**
 * \brief A simple ressource that wraps a message.
 * Use this to wrap a static string as a ressource.
 */
class QTWUI_EXPORT QwuiMessageRessource : public QwuiAbstractRessource
{
public:
    QwuiMessageRessource(const QString& path = QString::null);
    virtual ~QwuiMessageRessource();

    virtual QString mimeType() const;
    virtual qint64 length() const;
    virtual void sendToDevice(QIODevice* dev) const;
    virtual void setMessage(const QString& message);
    QString message() const;

private:
    QString m_message;
};

#endif // QWUIMESSAGERESSOURCE_H
