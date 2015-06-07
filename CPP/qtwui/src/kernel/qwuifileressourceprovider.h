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

#ifndef QWUIFILERESSOURCEPROVIDER_H
#define QWUIFILERESSOURCEPROVIDER_H

#include <QtWui/QwuiAbstractRessourceProvider>
#include <QtCore/QString>
#include <QtWui/QwuiGlobal>

/**
 * \brief A ressource provider that provides file ressources.
 * When provide() is called, the ressource provider looks for a file that corresponds to the path
 * given in the header relatively to the rootDirectory().
 */
class QTWUI_EXPORT QwuiFileRessourceProvider : public QwuiAbstractRessourceProvider
{
    Q_OBJECT

public:
    QwuiFileRessourceProvider(const QString& sessionId = QString::null);
    virtual ~QwuiFileRessourceProvider();

    /**
     * @param path path of the file ressources root directory.
     */
    void setRootDirectory(const QString& path);

    /**
     * @return path of the file ressources root directory.
     */
    QString rootDirectory() const;

    QwuiAbstractRessource* provide(const QHttpRequestHeader& header, const QString& postContent);

private:
    QString m_rootDir;
};

#endif // QWUIFILERESSOURCEPROVIDER_H
