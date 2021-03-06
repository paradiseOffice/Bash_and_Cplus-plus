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

#ifndef QWUIABSTRACTRESSOURCEPROVIDERFACTORY_H
#define QWUIABSTRACTRESSOURCEPROVIDERFACTORY_H

#include <QtCore/QString>
#include <QtWui/QwuiGlobal>

class QwuiAbstractRessourceProvider;

/**
 * \brief Abstract class defining the interface for a ressource provider factory.
 * Subclasses must implement the create() method to return a QwuiAbstractRessourceProvider.
 */
class QTWUI_EXPORT QwuiAbstractRessourceProviderFactory
{
public:
    QwuiAbstractRessourceProviderFactory();
    virtual ~QwuiAbstractRessourceProviderFactory();

    /**
     * @param sessionId the session identifier for the ressource provider.
     * @return a new ressource provider.
     */
    virtual QwuiAbstractRessourceProvider* create(const QString& sessionId) const = 0;
};

#endif // QWUIABSTRACTRESSOURCEPROVIDERFACTORY_H
