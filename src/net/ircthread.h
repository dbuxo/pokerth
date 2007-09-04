/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
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
/* IRC thread for the lobby. */

#ifndef _IRCTHREAD_H_
#define _IRCTHREAD_H_

#include <core/thread.h>
#include <string>

struct IrcContext;

class IrcThread : public Thread
{
public:
	IrcThread();
	virtual ~IrcThread();

	// Set the parameters.
	void Init(const std::string &serverAddress, unsigned serverPort, bool ipv6, const std::string &nick, const std::string &channel);

protected:

	// Main function of the thread.
	virtual void Main();

	const IrcContext &GetContext() const;
	IrcContext &GetContext();

private:
	std::auto_ptr<IrcContext> m_context;
};

#endif
