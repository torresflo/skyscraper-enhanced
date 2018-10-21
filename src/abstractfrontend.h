/***************************************************************************
 *            abstractfrontend.h
 *
 *  Wed Jun 18 12:00:00 CEST 2017
 *  Copyright 2017 Lars Muldjord
 *  muldjordlars@gmail.com
 ****************************************************************************/
/*
 *  This file is part of skyscraper.
 *
 *  skyscraper is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  skyscraper is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with skyscraper; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */

#ifndef ABSTRACTFRONTEND_H
#define ABSTRACTFRONTEND_H

#include <QObject>
#include <QFileInfo>
#include <QSharedPointer>

#include "gameentry.h"
#include "settings.h"
#include "queue.h"

class AbstractFrontend : public QObject
{
  Q_OBJECT

public:
  AbstractFrontend();
  virtual ~AbstractFrontend();
  void setConfig(Settings *config);
  virtual void checkReqs(){};
  virtual void assembleList(QString &, const QList<GameEntry> &, int){};
  virtual void skipExisting(const QString &, QList<GameEntry> &, QSharedPointer<Queue>){};
  virtual bool canSkip();
  virtual bool loadOldGameList(const QString &);
  virtual QString getGameListFileName();
  virtual QString getInputFolder();
  virtual QString getGameListFolder();
  virtual QString getCoversFolder();
  virtual QString getScreenshotsFolder();
  virtual QString getWheelsFolder();
  virtual QString getMarqueesFolder();
  virtual QString getVideosFolder();
  virtual void sortEntries(QList<GameEntry> &gameEntries);

protected:
  Settings *config;
  
};

#endif // ABSTRACTFRONTEND_H
